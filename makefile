#	Names
NAME_FDF		=	fdf

#	Includes
-include make/includes.mk
-include make/srcs.mk

#	Compilation
CC				=	gcc
CFLAGS			=	-Wall -Werror -Wextra
AR				=	ar rcs
LINUX_MLX		=	minilibx-linux
LINUX_MLX_SRC	=	https://github.com/42Paris/minilibx-linux.git
LIBS			=	./libraries/minilibx-linux/libmlx_Linux.a
USR_LIBS		=	-L/usr/lib -lXext -lm -lX11
INCLUDES_PATH	=	./includes

SRCS_OBJS		=	$(SRCS_SOURCES:.c=.o)

#	Delete
RM				=	rm -rf

#	RULES
#		Defaults:
all: linux_mlx $(NAME_FDF)

#		Compile FdF
$(NAME_FDF): $(INCLUDES) $(SRCS_OBJS)
	@make -C libraries/$(LINUX_MLX)
	@$(CC) -o $(NAME_FDF) $(SRCS_OBJS) $(LIBS) $(USR_LIBS) $(CFLAGS) -I $(INCLUDES_PATH)
	@echo "FDF CREATED"

#		Install minilibx-linux

linux_mlx:
	@if [ ! -d libraries/"$(LINUX_MLX)" ]; then \
		git clone $(LINUX_MLX_SRC) libraries/$(LINUX_MLX); \
	fi; \

#		Clean
clean:
	$(RM) $(SRCS_OBJS)
	make clean -C libraries/$(LINUX_MLX)
	echo "CLEANING ALL .O PROJECTS"

#		Fclean
fclean: clean
	$(RM) $(NAME_FDF)
	echo "CLEANING COMPILED PROGRAMS!"

#		Re
re:			fclean all

#		Generate .mk (Makefile includes)
gmk:
		@find includes -name '*.h' | sed 's/^/INCLUDES += /' > make/includes.mk
		@find srcs -name '*.c' | sed 's/^/SRCS_SOURCES += /' > make/srcs.mk

#		PHONY
.PHONY:			all clean fclean re gmk
