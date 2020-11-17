/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kroyce <kroyce@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 23:26:12 by kroyce            #+#    #+#             */
/*   Updated: 2020/11/07 01:06:52 by kroyce           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#define BUFF_SIZE 1
int 	get_next_line(int fd, char **line);
size_t	ft_strlen(const char *str);
char 	*ft_strdup(const char *str);
char 	*ft_strjoin(const char *s1, const char *s2);
char	*ft_strchr(const char *str, int c);
size_t 	ft_strcpy(char *dst, const char *src);
#endif