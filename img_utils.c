/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbombur <hbombur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 18:24:47 by hbombur           #+#    #+#             */
/*   Updated: 2022/06/29 15:51:55 by hbombur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	hex_to_dec(char *hex, long long decimal)
{
	long long	base;
	int			i;

	base = 1;
	i = ft_strlen(hex);
	while (i >= 0)
	{
		if (hex[i] >= '0' && hex[i] <= '9')
		{
			decimal += (hex[i] - 48) * base;
			base *= 16;
		}
		else if (hex[i] >= 'A' && hex[i] <= 'F')
		{
			decimal += (hex[i] - 55) * base;
			base *= 16;
		}
		else if (hex[i] >= 'a' && hex[i] <= 'f')
		{
			decimal += (hex[i] - 87) * base;
			base *= 16;
		}
		i--;
	}
	return (decimal);
}

void	isometric(t_pix *start, t_pix *end, t_data *data)
{
	start->x = (start->x - start->y) * cos(data->angle_cos);
	start->y = (start->x + start->y) * sin(data->angle_sin) - start->z;
	end->x = (end->x - end->y) * cos(data->angle_cos);
	end->y = (end->x + end->y) * sin(data->angle_sin) - end->z;
}

void	make_zoom(t_pix *a, t_pix *b, t_data *data)
{
	a->x *= data->zoom;
	a->y *= data->zoom;
	a->z *= (data->z_scale);
	b->x *= data->zoom;
	b->y *= data->zoom;
	b->z *= data->z_scale;
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
