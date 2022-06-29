/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbombur <hbombur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 18:24:47 by hbombur           #+#    #+#             */
/*   Updated: 2022/06/29 22:23:53 by hbombur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	hex_to_dec(char *hex, long long dec)
{
	long long	base;
	int			i;

	base = 1;
	i = ft_strlen(hex);
	while (i >= 0)
	{
		if (hex[i] >= '0' && hex[i] <= '9')
		{
			dec += (hex[i] - 48) * base;
			base *= 16;
		}
		else if (hex[i] >= 'A' && hex[i] <= 'F')
		{
			dec += (hex[i] - 55) * base;
			base *= 16;
		}
		else if (hex[i] >= 'a' && hex[i] <= 'f')
		{
			dec += (hex[i] - 87) * base;
			base *= 16;
		}
		i--;
	}
	return (dec);
}

void	isometric(t_pix *start, t_pix *finish, t_data *data)
{
	start->x = (start->x - start->y) * cos(data->angle_cos);
	start->y = (start->x + start->y) * sin(data->angle_sin) - start->z;
	finish->x = (finish->x - finish->y) * cos(data->angle_cos);
	finish->y = (finish->x + finish->y) * sin(data->angle_sin) - finish->z;
}

void	make_zoom(t_pix *a, t_pix *b, t_data *data)
{
	a->x *= data->zoom;
	a->y *= data->zoom;
	a->z *= (data->z_scale * 0.6);
	b->x *= data->zoom;
	b->y *= data->zoom;
	b->z *= (data->z_scale * 0.6);
}

void	make_shift(t_pix *start, t_pix *end, t_data *data)
{
	start->x += data->shift_x;
	start->y += data->shift_y;
	end->x += data->shift_x;
	end->y += data->shift_y;
}

void	set_color(t_pix *matrix, char *z)
{
	matrix->z = ft_atoi(z);
	if (matrix->z > -9)
		matrix->color = 0x00FF00;
	if (matrix->z > -7)
		matrix->color = 0xCAFFCA;
	if (matrix->z > -5)
		matrix->color = 0xACFFAC;
	if (matrix->z > -3)
		matrix->color = 0x97FF97;
	if (matrix->z > -1)
		matrix->color = 0x5CFF5C;
	if (matrix->z == 0)
		matrix->color = 0x00CC00;
	if (matrix->z > 1)
		matrix->color = 0x00A300;
	if (matrix->z > 3)
		matrix->color = 0x008200;
	if (matrix->z > 5)
		matrix->color = 0x006800;
	if (matrix->z > 7)
		matrix->color = 0xA30000;
	if (matrix->z > 9)
		matrix->color = 0xCC0000;
}
