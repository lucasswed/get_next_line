/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas-ma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 10:49:23 by lucas-ma          #+#    #+#             */
/*   Updated: 2021/10/29 16:13:02 by lucas-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*gnl_trim(char **stor, char **buf, int len)
{
	char	*ret;
	char	*temp;
	int		i;

	if (*stor)
		i = ft_strlen(*stor);
	else
		i = 0;
	ret = malloc((len + i + 1) * sizeof(char));
	if (!ret)
		return (0);
	ft_memcpy(ret, *stor, i);
	ft_memcpy(ret + i, *buf, len);
	ret[len + i] = '\0';
	temp = ft_strdup((*buf) + len);
	if (*stor)
		free(*stor);
	*stor = temp;
	return (ret);
}

static char	*gnl_get(char **stor, int len)
{
	char	*ret;
	char	*temp;
	int		i;

	ret = malloc((len + 1) * sizeof(char));
	if (!ret)
		return (NULL);
	i = 0;
	while (i != len)
	{
		ret[i] = (*stor)[i];
		i++;
	}
	ret[i] = '\0';
	temp = ft_strdup(*stor + i);
	free(*stor);
	(*stor) = temp;
	return (ret);
}

static char	*gnl_main(char **stor, char **buf, int r)
{
	char	*ret;
	char	*temp;

	ret = NULL;
	if (r <= 0)
	{
		if (r == 0 && *stor)
		{
			ret = (*stor);
			(*stor) = NULL;
		}
		return (ret);
	}
	(*buf)[r] = '\0';
	temp = ft_strchr(*buf, '\n');
	if (temp)
		ret = gnl_trim(stor, buf, (temp - *buf) + 1);
	else
	{
		temp = ft_strjoin(*stor, *buf);
		if (*stor)
			free(*stor);
		*stor = temp;
	}
	return (ret);
}

char	*get_next_line(int fd)
{
	static char	*storage[1024];
	char		*line;
	char		*buffer;
	int			r;

	if ((read(fd, 0, 0) == -1) || fd < 0 || fd > 1024 || BUFFER_SIZE <= 0)
		return (NULL);
	r = 1;
	line = NULL;
	buffer = ft_strchr(storage[fd], '\n');
	if (!buffer)
	{
		buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
		if (!buffer)
			return (0);
		while (line == NULL && r > 0)
		{
			r = read(fd, buffer, BUFFER_SIZE);
			line = gnl_main(&storage[fd], &buffer, r);
		}
		free(buffer);
	}
	else
		line = gnl_get(&storage[fd], (buffer - storage[fd]) + 1);
	return (line);
}
