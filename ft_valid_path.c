/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbonnet <nbonnet@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 17:34:09 by nbonnet           #+#    #+#             */
/*   Updated: 2024/11/16 16:19:33 by nbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_replace_C(t_game *game, int x, int y)
{
	if (x < 0 || y < 0 || y >= game->count_line || x >= game->len_map - 1)
		return ;
	if (game->map[y][x] == '1' || game->map[y][x] == '2' || game->map[y][x] == 'E')
		return ;
	game->map[y][x] = '2';
	ft_replace_C(game, x + 1, y);
	ft_replace_C(game, x - 1, y);
	ft_replace_C(game, x, y + 1);
	ft_replace_C(game, x, y - 1);
}

void	ft_replace_E(t_game *game, int x, int y)
{
	if (x < 0 || y < 0 || y >= game->count_line || x >= game->len_map - 1)
		return ;
	if (game->map[y][x] == '1' || game->map[y][x] == '2')
		return ;
	game->map[y][x] = '2';
	ft_replace_E(game, x - 1, y);
	ft_replace_E(game, x + 1, y);
	ft_replace_E(game, x, y + 1);
	ft_replace_E(game, x, y - 1);
}

int	ft_valid_path(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	ft_replace_C(game, game->player_x / 32, game->player_y / 32);
	while (i < game->count_line)
	{
		j = 0;
		while (j < game->len_map - 1)
		{
			if (game->map[i][j] == 'C')
				return (1);
			j++;
		}
		i++;
	}
	ft_fill_map(game->argv, game);
	i = 0;
	j = 0;
	ft_replace_E(game, game->player_x / 32, game->player_y / 32);
	while (i < game->count_line)
	{
		j = 0;
		while (j < game->len_map - 1)
		{
			if (game->map[i][j] == 'E')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
