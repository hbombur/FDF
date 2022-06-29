/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_win.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbombur <hbombur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 16:51:15 by hbombur           #+#    #+#             */
/*   Updated: 2022/06/29 19:43:53 by hbombur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	win_init(t_data *data)
{
	data->screen_x = WIDTH;
	data->screen_y = HEIGHT;
	data->shift_y = 250;
	data->shift_x = 900;
	data->zoom = 30;
	data->angle_cos = 0.8;
	data->angle_sin = 0.8;
	data->z_scale = 2;
	data->flag = 1;
}

void	img_init(t_data *data)
{
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, data->screen_x, \
											data->screen_y, "fdf");
	data->img = mlx_new_image(data->mlx_ptr, data->screen_x, data->screen_y);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, \
								&data->line_length, &data->endian);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	found_center_x(t_data *data)
{
	int	x;

	x = 0;
	while (x != data->width)
		x++;
	x /= 2;
	return (x);
}

int	found_center_y(t_data *data)
{
	int	y;

	y = 0;
	while (y != data->height)
		y++;
	y /= 2;
	return (y);
}
