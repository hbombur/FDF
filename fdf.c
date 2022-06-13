/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbombur <hbombur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 14:18:26 by hbombur           #+#    #+#             */
/*   Updated: 2022/06/13 18:16:18 by hbombur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
// #include "mlx.h"

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
	}
	return (0);
}
