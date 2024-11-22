/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbonnet <nbonnet@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 17:34:09 by nbonnet           #+#    #+#             */
/*   Updated: 2024/11/22 16:43:22 by nbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_replace_c(t_game *game, int x, int y)
{
	if (x < 0 || y < 0 || y >= game->count_line || x >= game->len_map - 1)
		return ;
	if (game->map[y][x] == '1' || game->map[y][x] == '2'
	|| game->map[y][x] == 'E')
		return ;
	game->map[y][x] = '2';
	ft_replace_c(game, x + 1, y);
	ft_replace_c(game, x - 1, y);
	ft_replace_c(game, x, y + 1);
	ft_replace_c(game, x, y - 1);
}

void	ft_replace_e(t_game *game, int x, int y)
{
	if (x < 0 || y < 0 || y >= game->count_line || x >= game->len_map - 1)
		return ;
	if (game->map[y][x] == '1' || game->map[y][x] == '2')
		return ;
	game->map[y][x] = '2';
	ft_replace_e(game, x - 1, y);
	ft_replace_e(game, x + 1, y);
	ft_replace_e(game, x, y + 1);
	ft_replace_e(game, x, y - 1);
}

int	ft_valid_path2(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->count_line)
	{
		game->j = 0;
		while (game->j < game->len_map - 1)
		{
			if (game->map[i][game->j] == 'C')
				return (1);
			game->j++;
		}
		i++;
	}
	return (0);
}

int	ft_valid_path(t_game *game)
{
	int	i;

	i = 0;
	game->j = 0;
	ft_replace_c(game, game->player_x / 32, game->player_y / 32);
	game->j = ft_valid_path2(game);
	if (game->j == 1)
		return (1);
	ft_free_map(game);
	ft_fill_map(game->argv, game);
	i = 0;
	game->j = 0;
	ft_replace_e(game, game->player_x / 32, game->player_y / 32);
	while (i < game->count_line)
	{
		game->j = 0;
		while (game->j < game->len_map - 1)
		{
			if (game->map[i][game->j] == 'E')
				return (1);
			game->j++;
		}
		i++;
	}
	return (0);
}
