/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piboidin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 11:50:55 by piboidin          #+#    #+#             */
/*   Updated: 2022/02/04 11:51:05 by piboidin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>

# define BUFFER_SIZE 4096

typedef struct s_fdf
{
	int	width;
	int	height;
	int	**alt;
}		s_fdf;

char	*ft_malloc_word(char const *s, char c);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);

char	**ft_split(char const *s, char c);

int		ft_atoi(const char *str);
int		ft_count_word(char const *s, char c);
int		ft_get_height(char *file);
int		ft_get_next_line(int fd, char **line);
int		ft_get_width(char *file);
int		ft_is_charset(char s, char c);

size_t	ft_strlen(const char *s);

void	ft_file_reader(char *file, s_fdf *data);
void	ft_matrix(int *data, char *lines);

#endif
