/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbonnet <nbonnet@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 16:18:57 by nbonnet           #+#    #+#             */
/*   Updated: 2024/11/19 15:52:12 by nbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_map2(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->count_line)
	{
		j = 0;
		while (j < game->len_map - 1)
		{
			if (game->map[i][j] == 'E')
				game->flag_e++;
			else if (game->map[i][j] == 'C')
				game->flag_c++;
			else if (game->map[i][j] == 'P')
				game->flag_p++;
			else if (game->map[i][j] != '1' && game->map[i][j] != '0')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_check_map(t_game *game)
{
	int	i;
	int	j;

	game->flag_e = 0;
	game->flag_c = 0;
	game->flag_p = 0;
	i = 0;
	while (i < game->count_line)
	{
		if (ft_strlen(game->map[i]) != game->len_map)
			return (1);
		i++;
	}
	j = ft_check_map2(game);
	if (j == 1)
		return (1);
	if (game->flag_e != 1 || game->flag_p != 1 || game->flag_c < 1)
		return (1);
	return (0);
}

int	ft_check_wall(t_game *game)
{
	int	i;
	int	j;

	j = 0;
	while (game->map[0][j] != '\0' && game->map[0][j] != '\n')
	{
		if (game->map[0][j] != '1')
			return (1);
		j++;
	}
	j = 0;
	while (game->map[game->count_line - 1][j] != '\0'
		&& game->map[game->count_line - 1][j] != '\n')
	{
		if (game->map[game->count_line - 1][j] != '1')
			return (1);
		j++;
	}
	i = 0;
	while (i++ < game->count_line - 1)
	{
		if (game->map[i][0] != '1' || game->map[i][game->len_map - 2] != '1')
			return (1);
	}
	return (0);
}
