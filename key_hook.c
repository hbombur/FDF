/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbombur <hbombur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 13:53:36 by hbombur           #+#    #+#             */
/*   Updated: 2022/06/29 15:52:05 by hbombur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	move(int key, t_data *data)
{
	if (key == UP)
		data->shift_y -= 35;
	if (key == DOWN)
		data->shift_y += 35;
	if (key == LEFT)
		data->shift_x -= 35;
	if (key == RIGHT)
		data->shift_x += 35;
	return (0);
}

static int	zoom(int key, t_data *data)
{
	if (key == ZOOM_UP)
		data->zoom += 1;
	if (key == ZOOM_DOWN)
		data->zoom -= 1;
	return (0);
}

static int	angle(int key, t_data *data)
{
	if (key == ANGLE_COS_UP)
		data->angle_cos += 0.01;
	if (key == ANGLE_COS_DOWN)
		data->angle_cos -= 0.01;
	if (key == ANGLE_SIN_UP)
		data->angle_sin += 0.01;
	if (key == ANGLE_SIN_DOWN)
		data->angle_sin -= 0.01;
	return (0);
}

static int	z_scale(int key, t_data *data)
{
	if (key == Z_UP)
		data->z_scale += 0.1;
	if (key == Z_DOWN)
		data->z_scale -= 0.1;
	return (0);
}

int	key_hook(int key, t_data *data)
{
	if (key == UP || key == DOWN || key == LEFT || key == RIGHT)
		move(key, data);
	if (key == ZOOM_UP || key == ZOOM_DOWN)
		zoom(key, data);
	if (key == ANGLE_COS_DOWN || key == ANGLE_COS_UP || key == ANGLE_SIN_DOWN \
												|| key == ANGLE_SIN_UP)
		angle(key, data);
	if (key == Z_UP || key == Z_DOWN)
		z_scale(key, data);
	if (key == ISO_1)
		data->flag = 0;
	if (key == ISO_2)
		data->flag = 1;
	if (key == ISO_3)
		data->flag = 2;
	if (key == RESET)
		win_init(data);
	if (key == ESC)
		exit(0);
	draw(data, data->matrix);
	return (0);
}
