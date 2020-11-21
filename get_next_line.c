/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kroyce <kroyce@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 18:08:54 by kroyce            #+#    #+#             */
/*   Updated: 2020/11/17 22:21:30 by kroyce           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_strchr(const char *s, int c)
{
	while (*s != c && *s != 0)
		s++;
	if (*s == c)
		return ((char *)s);
	return (NULL);
}

static int	make_line(char **line, char *reminder)
{
	int		len;

	len = 0;
	if (reminder)
	{
		while (reminder[len] != '\0' && reminder[len] != '\n')
			len++;
		if (reminder[len] == '\n')
		{
			if (!(*line = ft_substr(reminder, 0, len)))
				return (-1);
			ft_strcpy(reminder, reminder + len + 1);
			return (1);
		}
		else if (reminder[len] == '\0')
		{
			if (!(*line = ft_substr(reminder, 0, len)))
				return (-1);
			free(reminder);
			return (0);
		}
	}
	*line = ft_strdup("\0");
	return (0);
}

int			get_next_line(int fd, char **line)
{
	static char *reminder;
	char		buff[BUFF_SIZE + 1];
	int			bytes;
	char		*tmp;

	if (fd < 0 || BUFF_SIZE <= 0)
		return (-1);
	while ((bytes = read(fd, buff, BUFF_SIZE)))
	{
		if (bytes < 0)
			return (-1);
		buff[bytes] = '\0';
		if (reminder == NULL)
			reminder = ft_strdup("\0");
		tmp = reminder;
		if (!(reminder = ft_strjoin(reminder, buff)))
			return (-1);
		free(tmp);
		if (ft_strchr(buff, '\n'))
			break ;
	}
	return (make_line(line, reminder));
}
