/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_so_long.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbonnet <nbonnet@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 11:19:52 by nbonnet           #+#    #+#             */
/*   Updated: 2024/11/22 16:41:36 by nbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_start1(t_game *game, int argc, char **argv)
{
	game->len_line = 0;
	game->count_line = 0;
	if (argc != 2
		|| ft_strncmp(argv[1] + ft_strlen(argv[1]) - 4, ".ber", 4) != 0)
	{
		ft_printf("Error\nInvalid input\n");
		ft_clean_up(game);
		return (0);
	}
	game->fd = open(argv[1], O_RDONLY);
	game->line = get_next_line(game->fd);
	while (game->line != NULL)
	{
		game->count_line++;
		if (game->len_line == 0)
			game->len_line = ft_strlen(game->line) - 1;
		free(game->line);
		game->line = get_next_line(game->fd);
	}
	if (game->line)
		free(game->line);
	close(game->fd);
	return (1);
}

void	ft_start2(t_game *game, char **argv)
{
	game->width = 32;
	game->height = 32;
	game->width_s = 30;
	game->height_s = 20;
	game->mlx = mlx_init();
	game->window = mlx_new_window(game->mlx, (32 * game->len_line),
			(32 * game->count_line), "Welcome in my bar !");
	game->wall = mlx_xpm_file_to_image(game->mlx,
			"assets/wall.xpm", &game->width, &game->height);
	game->ground = mlx_xpm_file_to_image(game->mlx,
			"assets/ground.xpm", &game->width, &game->height);
	game->beer = mlx_xpm_file_to_image(game->mlx,
			"assets/beer.xpm", &game->width, &game->height);
	game->exit = mlx_xpm_file_to_image(game->mlx,
			"assets/exit.xpm", &game->width, &game->height);
	game->player = mlx_xpm_file_to_image(game->mlx,
			"assets/player.xpm", &game->width, &game->height);
	game->scoreboard = mlx_xpm_file_to_image(game->mlx,
			"assets/scoreboard.xpm", &game->width_s, &game->height_s);
	game->y = 0;
	game->nbr_move = 0;
	game->argv = argv;
}

void	ft_print_map2(t_game *game)
{
	if (game->line[game->i] == '1')
		mlx_put_image_to_window(game->mlx, game->window,
			game->wall, game->x, game->y);
	else if (game->line[game->i] == '0')
		mlx_put_image_to_window(game->mlx, game->window,
			game->ground, game->x, game->y);
	else if (game->line[game->i] == 'C')
		mlx_put_image_to_window(game->mlx, game->window,
			game->beer, game->x, game->y);
	else if (game->line[game->i] == 'E')
		mlx_put_image_to_window(game->mlx, game->window,
			game->exit, game->x, game->y);
	else if (game->line[game->i] == 'P')
	{
		mlx_put_image_to_window(game->mlx, game->window,
			game->player, game->x, game->y);
		game->player_x = game->x;
		game->player_y = game->y;
	}
	game->i++;
	game->x += game->width;
}

void	ft_print_map(t_game *game, char **argv)
{
	game->fd = open(argv[1], O_RDONLY);
	game->line = get_next_line(game->fd);
	while (game->line != NULL)
	{
		game->x = 0;
		game->i = 0;
		while (game->line[game->i] != '\0' && game->line[game->i] != '\n')
			ft_print_map2(game);
		game->len_line = game->i;
		game->count_line++;
		game->y += game->height;
		free(game->line);
		game->line = get_next_line(game->fd);
	}
	if (game->line)
		free(game->line);
	close(game->fd);
}

int	main(int argc, char **argv)
{
	t_game	game;
	int		i;

	i = ft_start1(&game, argc, argv);
	if (i == 0)
		return (0);
	ft_start2(&game, argv);
	ft_print_map(&game, argv);
	ft_fill_map(argv, &game);
	if (ft_check_map(&game) == 1 || ft_check_wall(&game) == 1
		|| ft_valid_path(&game) == 1)
	{
		ft_printf("Error\nInvalid map\n");
		ft_clean_up(&game);
		return (0);
	}
	ft_free_map(&game);
	ft_fill_map(argv, &game);
	mlx_key_hook(game.window, ft_movements, &game);
	mlx_hook(game.window, 17, 1L << 2, ft_close_window, &game);
	mlx_loop(game.mlx);
}
