/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean_all.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbonnet <nbonnet@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 11:08:02 by nbonnet           #+#    #+#             */
/*   Updated: 2024/11/22 16:40:09 by nbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free_map(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->count_line)
	{
		if (game->map[i])
		{
			free(game->map[i]);
			game->map[i] = NULL;
		}
		i++;
	}
	free(game->map);
	game->map = NULL;
}

void	ft_clean_up(t_game *game)
{
	ft_free_map(game);
	mlx_destroy_image(game->mlx, game->wall);
	mlx_destroy_image(game->mlx, game->ground);
	mlx_destroy_image(game->mlx, game->beer);
	mlx_destroy_image(game->mlx, game->exit);
	mlx_destroy_image(game->mlx, game->player);
	mlx_destroy_image(game->mlx, game->scoreboard);
	mlx_destroy_window(game->mlx, game->window);
	game->mlx = NULL;
	free(game->mlx);
	game->line = NULL;
	free(game->line);
	game->steps = NULL;
	free(game->steps);
}
