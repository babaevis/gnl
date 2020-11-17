/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kroyce <kroyce@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 23:26:12 by kroyce            #+#    #+#             */
/*   Updated: 2020/11/17 19:33:40 by kroyce           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# define BUFF_SIZE 32

char	*ft_substr(const char *str, unsigned int start, size_t len);
size_t	ft_strlen(const char *str);
char	*ft_strdup(const char *str);
char	*ft_strjoin(const char *s1, const char *s2);
size_t	ft_strcpy(char *dst, const char *src);
int		get_next_line(int fd, char **line);
#endif
