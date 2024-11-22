/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_up_left.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbonnet <nbonnet@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 20:44:00 by nbonnet           #+#    #+#             */
/*   Updated: 2024/11/22 16:47:11 by nbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_up2(t_game *game)
{
	game->nbr_move++;
	mlx_put_image_to_window(game->mlx, game->window,
		game->scoreboard, 35, 5);
	game->steps = ft_itoa(game->nbr_move);
	mlx_string_put(game->mlx, game->window,
		40, 20, 0xFFFDF, game->steps);
	free(game->steps);
	ft_printf("Move up,    total steps: %d\n", game->nbr_move);
	mlx_put_image_to_window(game->mlx, game->window,
		game->ground, game->player_x, game->player_y);
	game->player_y -= 32;
	mlx_put_image_to_window(game->mlx, game->window,
		game->player, game->player_x, game->player_y);
}

void	ft_up(t_game *game)
{
	if (game->map[game->player_y / 32 - 1][game->player_x / 32] == 'E')
	{
		game->check_beer = ft_check_beer(game);
		if (game->check_beer == 0)
		{
			game->nbr_move++;
			mlx_put_image_to_window(game->mlx, game->window,
				game->scoreboard, 35, 5);
			game->steps = ft_itoa(game->nbr_move);
			mlx_string_put(game->mlx, game->window,
				40, 20, 0xFFFDF, game->steps);
			ft_printf("Move up,    total steps: %d\n", game->nbr_move);
			mlx_put_image_to_window(game->mlx, game->window,
				game->ground, game->player_x, game->player_y);
			game->player_y -= 32;
			mlx_put_image_to_window(game->mlx, game->window,
				game->player, game->player_x, game->player_y);
			ft_printf("Congratulations, you are drunk\n");
			exit (0);
		}
	}
	else
		ft_up2(game);
	if (game->map[game->player_y / 32][game->player_x / 32] == 'C')
		game->map[game->player_y / 32][game->player_x / 32] = '0';
}

void	ft_left2(t_game *game)
{
	game->nbr_move++;
	mlx_put_image_to_window(game->mlx, game->window,
		game->scoreboard, 35, 5);
	game->steps = ft_itoa(game->nbr_move);
	mlx_string_put(game->mlx, game->window,
		40, 20, 0xFFFDF, game->steps);
	free(game->steps);
	ft_printf("Move left,  total steps: %d\n", game->nbr_move);
	mlx_put_image_to_window(game->mlx, game->window,
		game->ground, game->player_x, game->player_y);
	game->player_x -= 32;
	mlx_put_image_to_window(game->mlx, game->window,
		game->player, game->player_x, game->player_y);
}

void	ft_left(t_game *game)
{
	if (game->map[game->player_y / 32][game->player_x / 32 - 1] == 'E')
	{
		game->check_beer = ft_check_beer(game);
		if (game->check_beer == 0)
		{
			game->nbr_move++;
			mlx_put_image_to_window(game->mlx, game->window,
				game->scoreboard, 35, 5);
			game->steps = ft_itoa(game->nbr_move);
			mlx_string_put(game->mlx, game->window,
				40, 20, 0xFFFDF, game->steps);
			ft_printf("Move left,  total steps: %d\n", game->nbr_move);
			mlx_put_image_to_window(game->mlx, game->window,
				game->ground, game->player_x, game->player_y);
			game->player_x -= 32;
			mlx_put_image_to_window(game->mlx, game->window,
				game->player, game->player_x, game->player_y);
			ft_printf("Congratulations, you are drunk\n");
			exit (0);
		}
	}
	else
		ft_left2(game);
	if (game->map[game->player_y / 32][game->player_x / 32] == 'C')
		game->map[game->player_y / 32][game->player_x / 32] = '0';
}
