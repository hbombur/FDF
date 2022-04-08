/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_F.C                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbombur <hbombur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 13:50:12 by hbombur           #+#    #+#             */
/*   Updated: 2022/04/08 14:16:34 by hbombur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_height(char *file_name)
{
	char	*line;
	int		fd;
	int		height;
	
	fd = open(file_name, O_RDONLY, 0);
	height = 0;
	while(line)
	{
		
		height++;
	}
	
}

int	read_file(fdf *data)
{
	data->height = get_height(file_name);
}