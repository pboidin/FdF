
#	Names
NAME_FDF		=	fdf

#	Includes
-include make/

#	Compilation
#	Delete
#	RULES
#		Defaults :
#		Convert .c to .o :
#		Compile FdF :


#		Clean :
clean:
				@$(RM) $(SRCS_OBJS)
				@echo "Cleaning all .o in project!"

#		Fclean :
fclean:			clean
				@$(RM) $(NAME_FDF)
				@echo "Cleaning compiled program!"

#		Re :
re:			fclean all

#		PHONY :
.PHONY:			all clean fclean re gmk
