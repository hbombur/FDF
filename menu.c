/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbombur <hbombur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 13:59:27 by hbombur           #+#    #+#             */
/*   Updated: 2022/06/29 19:33:15 by hbombur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_menu(t_data *data)
{
	void	*mlx;
	void	*win;
	int		y;

	y = 0;
	mlx = data->mlx_ptr;
	win = data->win_ptr;
	mlx_string_put(mlx, win, 15, y += 30, 0x88F403, "Move : arrows");
	mlx_string_put(mlx, win, 15, y += 30, 0x88F403, "Zoom : + / -");
	mlx_string_put(mlx, win, 15, y += 30, 0x88F403, "Scale : Q / E");
	mlx_string_put(mlx, win, 15, y += 30, 0x88F403, "Rotate : A / S / D / F");
	if (!data->flag)
		mlx_string_put(mlx, win, 15, 30, \
		0x88F403, "Turn on ISO : TAB");
	else
		mlx_string_put(mlx, win, 15, y += 30, \
		0x88F403, "Switch off ISO : 1");
	mlx_string_put(mlx, win, 15, y += 30, 0x88F403, "Reset : TAB");
	mlx_string_put(mlx, win, 15, y += 30, 0x88F403, "Exit : ESC");
}
