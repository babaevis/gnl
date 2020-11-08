/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kroyce <kroyce@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 18:08:54 by kroyce            #+#    #+#             */
/*   Updated: 2020/11/08 20:39:22 by kroyce           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*check_reminder(char *reminder, char **line)
{
	char *ptr;

	ptr = NULL;
	if (reminder)
	{
		if ((ptr = ft_strchr(reminder, '\n')))
		{
			*ptr = '\0';
			*line = ft_strdup(reminder);
			ft_strcpy(reminder, ptr + 1);
		}
		else
		{
			*line = ft_strdup(reminder);
			free(reminder);
		}
	}
	return ptr;
}

int		get_next_line(int fd, char **line)
{
	static char *reminder;
	char		buff[BUFF_SIZE + 1];
	int			bytes;
	char		*ptr;
	char 		*tmp;

	*line = ft_strdup("\0");
	check_reminder(reminder, line);
	while ((bytes = read(fd, buff, BUFF_SIZE)))
	{
		if (bytes == -1)
			return (-1);
		buff[bytes] = '\0';
		if ((ptr = ft_strchr(buff, '\n')))
		{
			*ptr = '\0';
			*line = ft_strjoin(*line ,buff);
			reminder = ft_strdup(ptr + 1);
			return (1);
		}
		tmp = *line;
		*line = ft_strjoin(*line, buff);
		free(tmp);
	}
	return (0);
}

int main()
{
	int fd = open("t.txt", O_RDONLY);
	char *str;
	int i = 0;
	while (get_next_line(fd, &str)) {
		printf("%s\n", str);
		free(str);
	}
	printf("%s\n", str);
	return 0;
}