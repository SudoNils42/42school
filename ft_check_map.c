/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbonnet <nbonnet@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 16:18:57 by nbonnet           #+#    #+#             */
/*   Updated: 2024/11/16 15:45:43 by nbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_map(t_game *game)
{
	int	i;
	int	j;
	int	flag_E;
	int	flag_C;
	int	flag_P;

	flag_E = 0;
	flag_C = 0;
	flag_P = 0;
	i = 0;
	while (i < game->count_line)
	{
		if (ft_strlen(game->map[i]) != game->len_map)
			return (1);
		else
			i++;
	}
	i = 0;
	while (i < game->count_line)
	{
		j = 0;
		while (game->map[i][j] != game->len_map - 1)
		{
			if (game->map[i][j] == 'E')
				flag_E++;
			else if (game->map[i][j] == 'C')
				flag_C++;
			else if (game->map[i][j] == 'P')
				flag_P++;
			else if (game->map[i][j] != '1' && game->map[i][j] != '0')
				return (1);
			j++;
		}
		i++;
	}
	if (flag_E != 1 || flag_P != 1 || flag_C < 1)
		return (1);
	return (0);
}

int	ft_check_wall(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (game->map[0][j] != '\0' && game->map[0][j] != '\n')
	{
		if (game->map[0][j] != '1')
			return (1);
		else
			j++;
	}
	j = 0;
	while (game->map[game->count_line - 1][j] != '\0' && game->map[game->count_line - 1][j] != '\n')
	{
		if (game->map[game->count_line - 1][j] != '1')
			return (1);
		else
			j++;
	}
	i = 1;
	while (i < game->count_line - 1)
	{
		if (game->map[i][0] != '1' || game->map[i][game->len_map - 2] != '1')
			return (1);
		else
			i++;
	}
	return (0);
}
