/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbonnet <nbonnet@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 15:23:45 by nbonnet           #+#    #+#             */
/*   Updated: 2024/11/07 14:00:11 by nbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin1(char *rest, char *buf)
{
	int		len;
	char	*updated_rest;

	len = ft_strlen1(rest) + ft_strlen1(buf);
	updated_rest = malloc(sizeof(char) * (len + 1));
	if (!updated_rest)
	{
		free(rest);
		return (NULL);
	}
	updated_rest = ft_strcat1(updated_rest, rest, buf, len);
	free(rest);
	return (updated_rest);
}

char	*ft_read_until_nl(int fd, char *buf, char *rest)
{
	int	bytes_readed;

	bytes_readed = 1;
	while (ft_find_nl(rest) == NULL && bytes_readed != 0)
	{
		bytes_readed = read(fd, buf, BUFFER_SIZE);
		if (bytes_readed == -1)
		{
			free(rest);
			free(buf);
			return (NULL);
		}
		buf[bytes_readed] = '\0';
		rest = ft_strjoin1(rest, buf);
	}
	free(buf);
	return (rest);
}

char	*get_next_line(int fd)
{
	static char	*rest;
	char		*line;
	char		*buf;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	rest = ft_read_until_nl(fd, buf, rest);
	line = ft_find_line(rest);
	rest = ft_find_rest(rest);
	return (line);
}
