/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_win.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbombur <hbombur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 16:51:15 by hbombur           #+#    #+#             */
/*   Updated: 2022/06/19 18:08:54 by hbombur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


void	init_windows(fdf *data)
{
	data->zoom = 30;
	data->scale = 2;
	data->shift_y = 250;
	data->shift_x = 900;
	data->screen_x = WIDTH;
	data->screen_y = HEIGHT;
	data->center_x = found_center_x(data);
	data->center_y = found_center_y(data);
}

void	init_win(fdf *data)
{
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, data->screen_x, \
	data->screen_y, "fdf");
	data->img = mlx_new_image(data->mlx_ptr, data->screen_x, data->screen_y);
}

int	found_center_x(fdf *data)
{
	int	x;
	
	x = 0;
	while (*data->matrix[x])
		x++;
	x /= 2;
	return (x);
}

int	found_center_y(fdf *data)
{
	int	y;

	y = 0;
	while (data->matrix[y])
		y++;
	y /= 2;
	return (y);
}