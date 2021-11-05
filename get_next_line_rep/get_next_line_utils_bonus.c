/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas-ma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 10:37:09 by lucas-ma          #+#    #+#             */
/*   Updated: 2021/10/28 14:22:37 by lucas-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strdup(const char *src)
{
	char	*str;
	int		len;
	int		index;

	if (src)
	{
		index = 0;
		len = ft_strlen(src);
		if (!len)
			return (NULL);
		str = malloc((len + 1) * sizeof(char));
		if (!str)
			return (NULL);
		while (src[index])
		{
			str[index] = src[index];
			index++;
		}
		str[index] = '\0';
		return (str);
	}
	return (NULL);
}

char	*ft_strchr(const char *str, int c)
{
	int	index;

	if (str)
	{
		index = 0;
		if (str[index] == (char)c)
			return ((char *)str);
		while (str[index++])
			if (str[index] == (char)c)
				return ((char *)str + index);
	}
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	char	*temp;
	int		total_len;
	int		i;
	int		j;

	if (!s1 && s2)
		return (ft_strdup(s2));
	else if (!s2 && s1)
		return (ft_strdup(s1));
	total_len = ft_strlen(s1) + ft_strlen(s2);
	str = malloc((total_len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	temp = str;
	i = ft_strlen(s1);
	j = ft_strlen(s2);
	ft_memcpy(temp, s1, i);
	ft_memcpy(temp + i, s2, j);
	temp[i + j] = '\0';
	return (str);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*dstptr;
	char	*srcptr;

	dstptr = (char *)(dst);
	srcptr = (char *)(src);
	if (dstptr && srcptr)
	{
		while (n--)
			*dstptr++ = *srcptr++;
	}
	return (dst);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}
