/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbombur <hbombur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 18:01:45 by hbombur           #+#    #+#             */
/*   Updated: 2022/06/29 22:25:41 by hbombur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static float	max_step(float x, float y)
{
	float	max;

	if (x > y)
		max = x;
	else
		max = y;
	return (max);
}

static float	module(float num)
{
	if (num < 0)
		num = -num;
	return (num);
}

void	draw_line(t_pix start, t_pix finish, t_data *data)
{
	float	x_step;
	float	y_step;
	int		max;

	make_zoom(&start, &finish, data);
	if (data->flag)
		isometric(&start, &finish, data);
	make_shift(&start, &finish, data);
	x_step = finish.x - start.x;
	y_step = finish.y - start.y;
	max = max_step(module(x_step), module(y_step));
	x_step /= max;
	y_step /= max;
	if (start.z < finish.z)
		start.color = finish.color;
	while ((int)(start.x - finish.x) || (int)(start.y - finish.y))
	{
		if ((int)start.x < data->screen_x && (int)start.y < data->screen_y
			&& (int)start.x >= 0 && (int)start.y >= 0)
			my_mlx_pixel_put(data, start.x, start.y, start.color);
		start.x += x_step;
		start.y += y_step;
	}
}

void	draw(t_data *data, t_pix **matrix)
{
	int	x;
	int	y;

	y = 0;
	ft_bzero(data->addr, data->screen_y * data->screen_x * \
								(data->bits_per_pixel / 8));
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			if (x < data->width - 1)
				draw_line(matrix[y][x], matrix[y][x + 1], data);
			if (y < data->height - 1)
				draw_line(matrix[y][x], matrix[y + 1][x], data);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img, 0, 0);
	draw_menu(data);
}
