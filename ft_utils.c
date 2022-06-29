/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbombur <hbombur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 16:54:49 by hbombur           #+#    #+#             */
/*   Updated: 2022/06/29 19:04:48 by hbombur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	min;
	int	num;

	min = 1;
	num = 0;
	i = 0;
	while ((str[i] == ' ') || (str[i] == '\t') || (str[i] == '\n') || (str[i]
			== '\v') || (str[i] == '\f') || (str[i] == '\r'))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str [i] == '-')
			min = -min;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10;
		num = num + (str[i] - '0');
		i++;
	}
	return (num * min);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	l_str;
	size_t	l;
	char	*dst;

	l = 0;
	if (s == 0)
		return (NULL);
	l_str = ft_strlen(s);
	if (len > l_str - start)
		len = l_str - start;
	dst = (char *)malloc (len + 1);
	if (!dst)
		return (NULL);
	while (s && l < len && start < l_str)
		dst[l++] = s[start++];
	dst[l] = '\0';
	return (dst);
}

void	ft_bzero(void *str, size_t n)
{
	char	*tmp;
	size_t	i;

	if (!n)
		return ;
	tmp = str;
	i = 0;
	while (i < n)
		*(tmp + i++) = 0;
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
