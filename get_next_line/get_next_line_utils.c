/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbonnet <nbonnet@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 15:23:48 by nbonnet           #+#    #+#             */
/*   Updated: 2024/11/07 14:15:00 by nbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen1(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_find_nl(char *rest)
{
	int	i;

	if (!rest)
		return (NULL);
	i = 0;
	while (rest[i] != '\0')
	{
		if (rest[i] == '\n')
			return (&rest[i]);
		i++;
	}
	return (NULL);
}

char	*ft_strcat1(char	*updated_rest, char *rest, char *buf, int len)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (rest != NULL)
	{
		while (rest[i] != '\0')
		{
			updated_rest[i] = rest[i];
			i++;
		}
	}
	while (buf[j] != '\0' && j < len)
	{
		updated_rest[i + j] = buf[j];
		j++;
	}
	updated_rest[i + j] = '\0';
	return (updated_rest);
}

char	*ft_find_line(char *rest)
{
	int		len;
	char	*temp;
	char	*line;

	if (!rest || !*rest)
		return (NULL);
	temp = ft_find_nl(rest);
	if (temp != NULL)
		len = temp - rest + 1;
	else
		len = ft_strlen1(rest);
	line = malloc(sizeof(char) * (len + 1));
	if (!line)
		return (NULL);
	line = ft_strcat1(line, NULL, rest, len);
	return (line);
}

char	*ft_find_rest(char *rest)
{
	int		len;
	char	*start;
	char	*new_rest;

	if (!rest)
		return (NULL);
	start = ft_find_nl(rest);
	if (!start)
	{
		free(rest);
		return (NULL);
	}
	start = start + 1;
	len = ft_strlen1(start);
	new_rest = malloc(sizeof(char) * (len + 1));
	if (!new_rest)
	{
		free(rest);
		return (NULL);
	}
	new_rest = ft_strcat1(new_rest, NULL, start, len);
	free(rest);
	return (new_rest);
}
