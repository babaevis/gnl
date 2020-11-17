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

static void	ft_strclr(char *s)
{
	if (s)
		while (*s)
			*s++ = '\0';
}

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
	char	*tmp;

	len = 0;
	if (reminder)
	{
		tmp = reminder;
		while (tmp[len] != '\0' && tmp[len] != '\n')
			len++;
		if (tmp[len] == '\n')
		{
			*line = ft_substr(tmp, 0, len);
			ft_strcpy(reminder, tmp + len + 1);
			return (1);
		}
		else if (tmp[len] == '\0')
		{
			*line = ft_substr(tmp, 0, len);
			ft_strclr(reminder);
			return (0);
		}
	}
	if (!ft_strlen(*line))
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
		reminder = ft_strjoin(reminder, buff);
		free(tmp);
		if (ft_strchr(buff, '\n'))
			break ;
	}
	return (make_line(line, reminder));
}
#include <stdio.h>
int main(){
	int fd = open("/Users/kroyce/qwert/t.txt", O_RDONLY);
	char *str;
	while (get_next_line(fd, &str)){
		printf("%s\n", str);
		free(str);
	}
	free(str);
	return 0;
}
