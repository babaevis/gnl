/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kroyce <kroyce@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 23:23:43 by kroyce            #+#    #+#             */
/*   Updated: 2020/11/07 00:05:12 by kroyce           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t  ft_strlen(const char *str)
{
	size_t i;

	if (!str)
		return 0;
	i = 0;
	while (str[i] != 0)
	{
		i++;
	}
	return (i);
}

char    *ft_strdup(const char *str)
{
	char    *res;
	int     size;
	int     i;

	i = 0;
	size = ft_strlen(str);
	if (!(res = (char *)malloc(size + 1)))
		return (NULL);
	while (str[i])
	{
		res[i] = str[i];
		i++;
	}
	res[i] = 0;
	return (res);
}

char    *ft_strjoin(const char *s1, const char *s2)
{
	char    *res;
	int     i;

	i = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	if (!(res = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1)))
		return (NULL);
	while (*s1)
	{
		res[i] = *s1++;
		i++;
	}
	while (*s2)
	{
		res[i] = *s2++;
		i++;
	}
	res[i] = 0;
	return (res);
}

char    *ft_strchr(const char *s, int c)
{
	while (*s != c && *s != 0)
		s++;
	if (*s == c)
		return ((char *)s);
	return (NULL);
}

size_t  ft_strcpy(char *dst, const char *src)
{
	size_t i;

	i = 0;
	if (src == NULL)
		return (0);
	if (dst == NULL)
		return (ft_strlen(src));
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = 0;
	return (ft_strlen(src));
}
