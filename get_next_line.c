/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbombur <hbombur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 20:08:07 by hbombur           #+#    #+#             */
/*   Updated: 2022/06/12 21:44:36 by hbombur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static char	*ft_freestring(char **s)
{
	if (!s || !*s)
		return (NULL);
	free(*s);
	*s = 0;
	return (NULL);
}

static char	*write_after_n(char *end_of_line)
{
	char	*line;
	int		i;
	int		j;

	j = 0;
	i = 0;
	line = 0;
	while (end_of_line[i] != '\n' && (end_of_line[i] != '\0'))
		i++;
	line = malloc((ft_strlen(end_of_line) - i + 2) * sizeof(char));
	if (!line)
		return (0);
	if (end_of_line[i] == '\n')
		i++;
	while (end_of_line[i])
		line[j++] = end_of_line[i++];
	line[j] = '\0';
	ft_freestring(&end_of_line);
	if (line[0] == '\0')
	{
		ft_freestring(&line);
		return (0);
	}
	return (line);
}

static char	*write_before_n(char *end_of_line)
{
	int		i;
	char	*itm;
	int		j;

	i = 0;
	j = 0;
	itm = 0;
	while (end_of_line[i] != '\n' && end_of_line[i] != '\0')
		i++;
	itm = malloc((i + 2) * sizeof(char));
	if (!itm)
		return (0);
	i = 0;
	while (end_of_line[i] != '\n' && end_of_line[i] != '\0')
		itm[j++] = end_of_line[i++];
	if (end_of_line[i] == '\n')
		itm[j++] = end_of_line[i];
	itm[j] = '\0';
	if (itm[0] == '\0')
	{
		ft_freestring(&itm);
		return (0);
	}
	return (itm);
}

static char	*file_read(int fd, char *end_of_line, char *buff)
{
	char	*tmp;
	int		read_byte;
	int		flag;

	read_byte = 1;
	tmp = 0;
	flag = 0;
	while (read_byte && !(ft_strchr(end_of_line, '\n')))
	{
		read_byte = read(fd, buff, BUFFER_SIZE);
		if (read_byte < 0 || !buff)
		{
			ft_freestring(&end_of_line);
			return (0);
		}
		buff[read_byte] = '\0';
		if (end_of_line != 0)
			tmp = end_of_line;
		if (!end_of_line)
			end_of_line = ft_strdup(buff);
		else
			end_of_line = ft_strjoin(end_of_line, buff);
		ft_freestring(&tmp);
	}
	return (end_of_line);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*end_of_line[OPEN_MAX + 1];
	char		*buff;

	line = NULL;
	if (!*end_of_line)
		*end_of_line = NULL;
	if (fd < 0 || read(fd, 0, 0) < 0 || BUFFER_SIZE < 1)
		return (NULL);
	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	end_of_line[fd] = file_read(fd, (end_of_line[fd]), buff);
	ft_freestring(&buff);
	line = write_before_n(end_of_line[fd]);
	if (!line)
		return (ft_freestring(&end_of_line[fd]));
	end_of_line[fd] = write_after_n(end_of_line[fd]);
	return (line);
}
