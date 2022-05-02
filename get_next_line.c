/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kflorett <kflorett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 18:16:16 by kflorett          #+#    #+#             */
/*   Updated: 2021/11/18 14:21:16 by kflorett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*ft_new_buf(char *buf, char *line)
{
	int		len;
	char	*ptr;
	char	*temp;

	ptr = buf;
	if (ft_strlen(buf) == ft_strlen(line))
	{
		free(ptr);
		return ((void *)0);
	}
	len = ft_linelen(buf);
	temp = ft_strdup(buf);
	free(ptr);
	buf = ft_substr(temp, len + 1, ft_strlen(temp) - len - 1);
	free(temp);
	return (buf);
}

char	*ft_new_line(char *buf)
{
	int		len;
	char	*line;

	len = ft_linelen(buf);
	if (len == -1)
		len = ft_strlen(buf);
	line = ft_substr(buf, 0, len + 1);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*buf;
	char		*temp;
	char		*line;
	int			len;

	temp = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (temp == (void *)0)
		return ((void *)0);
	len = 1;
	while (ft_linelen(buf) == -1 && len != 0)
	{
		len = read(fd, temp, BUFFER_SIZE);
		if (len == -1 || (len == 0 && buf == 0))
		{
			free(temp);
			return ((void *)0);
		}
		temp[len] = '\0';
		buf = ft_strjoin(buf, temp);
	}
	free(temp);
	line = ft_new_line(buf);
	buf = ft_new_buf(buf, line);
	return (line);
}
