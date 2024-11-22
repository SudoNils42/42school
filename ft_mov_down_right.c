/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mov_down_right.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbonnet <nbonnet@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 20:46:52 by nbonnet           #+#    #+#             */
/*   Updated: 2024/11/22 16:47:48 by nbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_down2(t_game *game)
{
	game->nbr_move++;
	mlx_put_image_to_window(game->mlx, game->window,
		game->scoreboard, 35, 5);
	game->steps = ft_itoa(game->nbr_move);
	mlx_string_put(game->mlx, game->window,
		40, 20, 0xFFFDF, game->steps);
	free(game->steps);
	ft_printf("Move down,  total steps: %d\n", game->nbr_move);
	mlx_put_image_to_window(game->mlx, game->window,
		game->ground, game->player_x, game->player_y);
	game->player_y += 32;
	mlx_put_image_to_window(game->mlx, game->window,
		game->player, game->player_x, game->player_y);
}

void	ft_down(t_game *game)
{
	if (game->map[game->player_y / 32 + 1][game->player_x / 32] == 'E')
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
			ft_printf("Move down,  total steps: %d\n", game->nbr_move);
			mlx_put_image_to_window(game->mlx, game->window,
				game->ground, game->player_x, game->player_y);
			game->player_y += 32;
			mlx_put_image_to_window(game->mlx, game->window,
				game->player, game->player_x, game->player_y);
			ft_printf("Congratulations, you are drunk\n");
			exit (0);
		}
	}
	else
		ft_down2(game);
	if (game->map[game->player_y / 32][game->player_x / 32] == 'C')
		game->map[game->player_y / 32][game->player_x / 32] = '0';
}

void	ft_right2(t_game *game)
{
	game->nbr_move++;
	mlx_put_image_to_window(game->mlx, game->window,
		game->scoreboard, 35, 5);
	game->steps = ft_itoa(game->nbr_move);
	mlx_string_put(game->mlx, game->window,
		40, 20, 0xFFFDF, game->steps);
	free(game->steps);
	ft_printf("Move right, total steps: %d\n", game->nbr_move);
	mlx_put_image_to_window(game->mlx, game->window,
		game->ground, game->player_x, game->player_y);
	game->player_x += 32;
	mlx_put_image_to_window(game->mlx, game->window,
		game->player, game->player_x, game->player_y);
}

void	ft_right(t_game *game)
{
	if (game->map[game->player_y / 32][game->player_x / 32 + 1] == 'E')
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
			ft_printf("Move right, total steps: %d\n", game->nbr_move);
			mlx_put_image_to_window(game->mlx, game->window,
				game->ground, game->player_x, game->player_y);
			game->player_x += 32;
			mlx_put_image_to_window(game->mlx, game->window,
				game->player, game->player_x, game->player_y);
			ft_printf("Congratulations, you are drunk\n");
			exit (0);
		}
	}
	else
		ft_right2(game);
	if (game->map[game->player_y / 32][game->player_x / 32] == 'C')
		game->map[game->player_y / 32][game->player_x / 32] = '0';
}

int	ft_movements(int keycode, t_game *game)
{
	game->check_beer = 1;
	if (keycode == 13
		&& game->map[game->player_y / 32 - 1][game->player_x / 32] != '1')
		ft_up(game);
	else if (keycode == 0
		&& game->map[game->player_y / 32][game->player_x / 32 - 1] != '1')
		ft_left(game);
	else if (keycode == 1
		&& game->map[game->player_y / 32 + 1][game->player_x / 32] != '1')
		ft_down(game);
	else if (keycode == 2
		&& game->map[game->player_y / 32][game->player_x / 32 + 1] != '1')
		ft_right(game);
	else if (keycode == 53)
	{
		ft_clean_up(game);
		ft_printf("You left the bar\n");
		exit(0);
	}
	return (0);
}
