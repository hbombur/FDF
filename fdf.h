/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbombur <hbombur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 14:01:39 by hbombur           #+#    #+#             */
/*   Updated: 2022/06/13 18:20:45 by hbombur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <limits.h>
# include "./minilibx_macos/mlx.h"
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_coor
{
	int	x;
	int	y;
	int	z;
	int	color;
}	t_coor;

typedef struct s_struct
{
	int		width;
	int		height;
	int		**matrix;

	void	*mlx_ptr;
	void	*win_ptr;
}			fdf;

int		read_file(char *file_name, fdf *data);
int		get_params(fdf *data, char *file_name);
void	ft_perror(char *str);
void	make_line_matrix(fdf *data, char **map_line, int y);
void	make_matrix(char *file_name, fdf *data);
int		ft_atoi(const char *str);
size_t	ft_strlen(const char *c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*get_next_line(int fd);
char	**ft_split(char const *s, char c);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_word_count(char *str, char c);



#endif
