/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_F.C                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbombur <hbombur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 13:50:12 by hbombur           #+#    #+#             */
/*   Updated: 2022/05/25 21:12:29 by hbombur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

fdf	*get_params(char *file_name)
{
	int	fd;
	int	height;
	int	width;
	fdf	*data;
	char	*line;
	
	data = (fdf*)malloc(sizeof(fdf));
	if (!data)
		return (NULL);
	fd = open(file_name, O_RDONLY, 0);
	height = 0;
	printf("%d\n", fd);
	
	while (line != 0)
	{
		printf("start gnl\n");
		line = get_next_line(fd);
		printf("end gnl\n%s", line);
		height++;
		if (line == 0)
			break ;
	}
	data->height = height;
	data->width = ft_strlen(get_next_line(fd));
	close(fd);
	return (data);
}

int	read_file(char *file_name)
{
	fdf	*data;
	
	data = get_params(file_name);
	printf("%d\n%d\n", data->height, data->width);
	return (0);
}
