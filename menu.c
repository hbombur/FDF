/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbombur <hbombur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 13:59:27 by hbombur           #+#    #+#             */
/*   Updated: 2022/06/29 14:38:35 by hbombur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	print_menu(t_data *data)
{
	int		y;
	void	*mlx;
	void	*win;

	y = 0;
	mlx = data->mlx_ptr;
	win = data->win_ptr;
	mlx_string_put(mlx, win, 15, y += 30, 0x88F403, "Move: <- / ->");
	mlx_string_put(mlx, win, 15, y += 30, 0x88F403, "Zoom: + / -");
	mlx_string_put(mlx, win, 15, y += 30, 0x88F403, "Scale: Q / E");
	mlx_string_put(mlx, win, 15, y += 30, 0x88F403, "Rotate: A / S / D / F");
	if (!data->flag)
		mlx_string_put(mlx, win, 15, y += 30, 0x88F403, "ISO ON: Use RESET");
	else
		mlx_string_put(mlx, win, 15, y += 30, 0x88F403, "ISO OFF: 1");
	mlx_string_put(mlx, win, 15, y += 30, 0x88F403, "Reset: TAB");
	mlx_string_put(mlx, win, 15, y += 30, 0x88F403, "Exit: ESC");
}
