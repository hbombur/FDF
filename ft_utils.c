/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbombur <hbombur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 16:54:49 by hbombur           #+#    #+#             */
/*   Updated: 2022/06/29 13:51:36 by hbombur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	num;
	int	min;

	i = 0;
	min = 1;
	num = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == 45)
	{
		min = -1;
		i++;
	}
	else if (str[i] == 43)
		i++;
	while (str[i] >= 48 && str[i] <= 57)
	{
		num = num * 10;
		num = num + (str[i] - 48);
		i++;
	}
	num = num * min;
	return (num);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	lenstr;
	size_t	l;
	char	*dst;

	l = 0;
	if (s == 0)
		return (NULL);
	lenstr = ft_strlen(s);
	if (len > lenstr - start)
		len = lenstr - start;
	dst = (char *)malloc (len + 1);
	if (!dst)
		return (NULL);
	while (s && l < len && start < lenstr)
		dst[l++] = s[start++];
	dst[l] = '\0';
	return (dst);
}

void	*ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*c;

	c = s;
	i = 0;
	while (i < n)
	{
		c[i] = '\0';
		i++;
	}
	return (c);
}

char	**ft_free(char **arr)
{
	size_t	n;

	n = 0;
	while (arr[n] != NULL)
		free(arr[n++]);
	free(arr);
	return (NULL);
}

int	ft_perror(char *error)
{
	perror(error);
	exit(0);
}
