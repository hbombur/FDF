/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbombur <hbombur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 14:01:39 by hbombur           #+#    #+#             */
/*   Updated: 2022/06/29 15:50:50 by hbombur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <math.h>
# include <fcntl.h>
# include "mlx.h"
# include "get_next_line.h"

# define WIDTH			1920
# define HEIGHT			1080

# define UP				126
# define DOWN			125
# define LEFT			123
# define RIGHT			124
# define ESC			53
# define ZOOM_UP		24
# define ZOOM_DOWN		27
# define ANGLE_COS_DOWN	2
# define ANGLE_COS_UP	0
# define ANGLE_SIN_DOWN	13
# define ANGLE_SIN_UP	1
# define Z_UP			14
# define Z_DOWN			12
# define ISO_1			18
# define ISO_2			19
# define ISO_3			20
# define RESET			48

typedef struct s_pix
{
	float	x;
	float	y;
	int		z;
	int		color;
}	t_pix;

typedef struct s_data {
	int		width;
	int		height;
	t_pix	**matrix;
	int		zoom;
	int		color;
	double	angle_cos;
	double	angle_sin;
	double	z_scale;
	int		flag;
	int		center_x;
	int		center_y;
	int		shift_x;
	int		shift_y;

	void	*mlx_ptr;
	void	*win_ptr;
	int		screen_x;
	int		screen_y;

	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

void	win_init(t_data *data);
void	make_matrix(t_pix *matrix, char *line, int y);
void	read_file(char *file, t_data *data);
void	create_line(t_pix start, t_pix end, t_data *data);
void	print_menu(t_data *data);
void	img_init(t_data *data);
void	draw(t_data *data, t_pix **matrix);
void	set_color(t_pix *matrix, char *z);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	isometric(t_pix *start, t_pix *end, t_data *data);
int		found_center_x(t_data *data);
int		found_center_y(t_data *data);
int		key_hook(int key, t_data *data);
int		hex_to_dec(char *hex, long long decimal);
void	make_zoom(t_pix *a, t_pix *b, t_data *data);
void	make_shift(t_pix *start, t_pix *end, t_data *data);
char	**ft_free(char **arr);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	**ft_split(char const *s, char c);
int		ft_atoi(const char *str);
int		ft_perror(char *error);
int		my_exit_program(t_data *data);
#endif
