/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbombur <hbombur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 13:59:27 by hbombur           #+#    #+#             */
/*   Updated: 2022/06/29 22:08:04 by hbombur          ###   ########.fr       */
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
	mlx_string_put(mlx, win, 15, y += 30, 0x88F403, "Rotate : W / A / S / D");
	mlx_string_put(mlx, win, 15, y += 30, 0x88F403, "ISO ON/OFF: 1 / 2");
	mlx_string_put(mlx, win, 15, y += 30, 0x88F403, "Reset: TAB");
	mlx_string_put(mlx, win, 15, y += 30, 0x88F403, "Exit: ESC");
}
