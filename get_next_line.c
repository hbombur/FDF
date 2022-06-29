/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbombur <hbombur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 20:08:07 by hbombur           #+#    #+#             */
/*   Updated: 2022/06/29 19:06:25 by hbombur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	*end_line(char *end_line)
{
	int		i;
	int		j;
	int		len;
	char	*line;

	i = 0;
	j = 0;
	len = ft_strlen(end_line);
	while (end_line[i] && end_line[i] != '\n')
		i++;
	if (!end_line[i])
	{
		free(end_line);
		return (NULL);
	}
	line = malloc(sizeof(char) * ((len - i) + 1));
	if (!line)
		return (NULL);
	i++;
	while (end_line[i])
		line[j++] = end_line[i++];
	line[j] = '\0';
	free(end_line);
	return (line);
}

char	*fd_reader(int fd, char *end_line)
{
	char	*buf;
	int		byte_read;

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buf == NULL)
		return (NULL);
	buf[0] = '\0';
	byte_read = 1;
	while (!(ft_strchr(buf, '\n')) && byte_read)
	{
		byte_read = read(fd, buf, BUFFER_SIZE);
		if (byte_read == -1)
		{
			free(buf);
			return (NULL);
		}
		buf[byte_read] = '\0';
		end_line = ft_strjoin(end_line, buf);
	}
	free(buf);
	return (end_line);
}

char	*get_next_line(int fd)
{
	static char	*reminder;
	char		*line;
	int			i;

	line = NULL;
	i = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	reminder = fd_reader(fd, reminder);
	if (!reminder)
		return (NULL);
	if (*reminder)
	{
		while (reminder[i] && reminder[i] != '\n')
			i++;
		line = malloc(sizeof(char) * (i + 2));
		if (!line)
			return (NULL);
		line = ft_strcpy(line, reminder);
	}
	reminder = end_line(reminder);
	return (line);
}
