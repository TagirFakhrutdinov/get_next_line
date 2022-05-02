/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kflorett <kflorett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 18:16:19 by kflorett          #+#    #+#             */
/*   Updated: 2021/11/18 14:22:15 by kflorett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_linelen(const char *str)
{
	int	i;

	i = 0;
	if (str != 0)
	{
		while (str[i] != '\0')
		{
			if (str[i] == '\n')
				return (i);
			i++;
		}
	}
	return (-1);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (str == 0)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	char	*tmp;

	if (s == (void *)0)
		return ((void *)0);
	if (len > ft_strlen(s))
		len = ft_strlen(s);
	str = (char *)malloc((len + 1) * sizeof(char));
	if (str == ((void *)0))
		return ((void *)0);
	tmp = str;
	if (start < ft_strlen(s))
	{
		while (start-- != 0)
			s++;
		while (len-- != 0)
			*str++ = *s++;
	}
	*str = '\0';
	return (tmp);
}

char	*ft_strdup(const char *str)
{
	char	*copy;
	char	*tmp;
	size_t	len;

	len = ft_strlen(str);
	copy = (char *)malloc((len + 1) * sizeof(char));
	if (copy == ((void *)0))
		return ((void *)0);
	tmp = copy;
	while (*str != '\0')
	{
		*copy = *str;
		copy++;
		str++;
	}
	*copy = '\0';
	return (tmp);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_str;
	char	*tmp_str;
	char	*tmp_buf;
	int		len1;
	int		len2;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	new_str = (char *)malloc((len1 + len2 + 1) * sizeof(char));
	if (new_str == ((void *)0))
		return ((void *)0);
	tmp_str = new_str;
	tmp_buf = (char *)s1;
	if (s1 != 0)
	{
		while (*s1 != '\0')
			*new_str++ = *s1++;
	}
	while (*s2 != '\0')
		*new_str++ = *s2++;
	*new_str = '\0';
	if (s1 != 0)
		free((char *)tmp_buf);
	return (tmp_str);
}
