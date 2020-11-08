/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kroyce <kroyce@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 18:08:54 by kroyce            #+#    #+#             */
/*   Updated: 2020/11/08 18:36:59 by kroyce           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(int fd, char **line)
{
	char	buff[BUFF_SIZE + 1];
	int		bytes;
	char	*ptr;

	bytes = 0;
	while ((bytes = read(fd, buff, BUFF_SIZE)))
	{
		buff[bytes] = '\0';
		if ((ptr = ft_strchr(buff, '\n')))
		{
			*ptr = '\0';
			ptr++;
		}
		*line = ft_strjoin(*line ,buff);
	}
	return 0;
}

int main()
{
	int fd = open("t.txt", O_RDONLY);
	char *str;
	int i = 0;
	get_next_line(fd, &str);
	printf("%s\n", str);
//	get_next_line(fd, &str);
//	printf("%s\n", str);
	return 0;
}