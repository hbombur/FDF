/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbombur <hbombur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 14:18:26 by hbombur           #+#    #+#             */
/*   Updated: 2022/06/19 18:08:50 by hbombur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


void	ft_perror(char *str)
{
	perror(str);
	exit(0);
}

// Главная функция
int	main(int argc, char **argv)
{
	fdf		*data;
	int		x;
	int		y;

	if (argc == 2)
	{
		data = (fdf *)malloc(sizeof(fdf));
		if (!data)
			ft_perror("Memory not allocated");
		read_file(argv[1], data);
		init_windows(data);
		init_win(data);
		y = 0;
		while (y != data->height)
		{
			x = 0;
			while (x != data->width)
			{
				printf("%d", data->matrix[y][x]);
				x++;
			}
			y++;
			printf("\n");
		}
		mlx_loop(data->mlx_ptr);
	}
	return (0);
}
