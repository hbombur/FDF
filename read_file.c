/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbombur <hbombur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 13:50:12 by hbombur           #+#    #+#             */
/*   Updated: 2022/06/13 18:26:05 by hbombur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	make_line_matrix(fdf *data, char **map_line, int y)
{
	int	x;
	int	i;

	x = 0;
	i = 0;
	while (x < data->width)
	{
		data->matrix[y][x] = ft_atoi(map_line[i]);
		x++;
		i++;
	}
}

void	matrix_malloc(fdf *data)
{
	int	i;

	i = 0;
	data->matrix = (int **) malloc((data->height) * (sizeof (int *)));
	if (!data->matrix)
		ft_perror("Memory is not allocated");
	while (i != data->height)
	{
		data->matrix[i] = (int *)malloc((data->width) * sizeof(int));
		i++;
	}
}

void	make_matrix(char *file_name, fdf *data)
{
	int		fd;
	char	*line;
	char	**map_line;
	int		y;

	y = 0;
	matrix_malloc(data);
	fd = open(file_name, O_RDONLY, 0);
	while (y != data->height)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		map_line = ft_split(line, ' ');
		make_line_matrix(data, map_line, y);
		free(line);
		free(map_line);
		y++;
	}
	close(fd);
}

int	get_params(fdf *data, char *file_name)
{
	int		fd;
	int		height;
	char	*line;

	fd = open(file_name, O_RDONLY, 0);
	if (!fd)
		return (0);
	height = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		free(line);
		data->width = ft_word_count(line, ' ');
		height++;
	}
	close(fd);
	return (height);
}

int	read_file(char *file_name, fdf *data)
{
	data->height = get_params(data, file_name);
	printf("data->height is done...\n");
	make_matrix(file_name, data);
	printf("%d\n%d\n", data->height, data->width);
	return (0);
}
