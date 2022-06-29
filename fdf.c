/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbombur <hbombur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 14:18:26 by hbombur           #+#    #+#             */
/*   Updated: 2022/06/29 20:21:37 by hbombur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	my_exit_func(t_data *data)
{
	mlx_destroy_image(data->mlx_ptr, data->img);
	exit(1);
}

int	main(int argc, char **argv)
{
	t_data	*data;

	if (argc == 2)
	{
		data = malloc(sizeof(t_data));
		if (!data)
			ft_perror("Memory not allocated");
		read_file(argv[1], data);
		win_init(data);
		img_init(data);
		draw(data, data->matrix);
		mlx_hook(data->win_ptr, 2, 0, key_hook, data);
		mlx_hook(data->win_ptr, 17, 0, my_exit_func, data);
		mlx_loop(data->mlx_ptr);
		free(data);
	}
	else
		ft_perror("Wrong number of arguments!");
	return (0);
}
