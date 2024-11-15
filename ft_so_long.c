/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_so_long.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbonnet <nbonnet@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 11:19:52 by nbonnet           #+#    #+#             */
/*   Updated: 2024/11/15 17:42:10 by nbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_close_window(void)
{
		printf("You left the bar\n");
		exit(0);
}

int	ft_check_beer(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->count_line)
	{
		j = 0;
		while (game->map[i][j] != '\0')
		{
			if (game->map[i][j] == 'C')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	ft_fill_map(char **argv, t_game *game)
{
	game->fd = open(argv[1], O_RDONLY);
	game->map = malloc(sizeof(char *) * (game->count_line + 1));
	if (!game->map)
		return ;
	game->count_line = 0;
	while ((game->line = get_next_line(game->fd)) != NULL)
	{
		game->len_map = ft_strlen(game->line);
		game->map[game->count_line] = malloc(sizeof(char) * (game->len_map + 1));
		if (!game->map)
			return ;
		ft_strlcpy(game->map[game->count_line], game->line, game->len_map + 1);
		game->count_line++;
		free(game->line);
	}
	close(game->fd);
}
int	ft_movements(int keycode, t_game *game)
{
	int check_beer;

	check_beer = 1;
	if (keycode == 13 && game->map[game->player_y / 32 - 1][game->player_x / 32] != '1')
	{
		if (game->map[game->player_y / 32 - 1][game->player_x / 32] == 'E')
		{
			check_beer = ft_check_beer(game);
			if (check_beer == 0)
			{
				game->nbr_move++;
				printf("Move up,    total steps: %d\n", game->nbr_move);
				mlx_put_image_to_window(game->mlx, game->window, game->ground, game->player_x, game->player_y);
				game->player_y -= 32;
				mlx_put_image_to_window(game->mlx, game->window, game->player, game->player_x, game->player_y);
				printf("Congratulations, you are drunk\n");
				exit (0);
			}
		}
		else
		{
			game->nbr_move++;
			printf("Move up,    total steps: %d\n", game->nbr_move);
			mlx_put_image_to_window(game->mlx, game->window, game->ground, game->player_x, game->player_y);
			game->player_y -= 32;
			mlx_put_image_to_window(game->mlx, game->window, game->player, game->player_x, game->player_y);
		}
		if (game->map[game->player_y / 32][game->player_x / 32] == 'C')
			game->map[game->player_y / 32][game->player_x / 32] = '0';
	}
	else if (keycode == 0 && game->map[game->player_y / 32][game->player_x / 32 - 1] != '1')
	{
		if (game->map[game->player_y / 32][game->player_x / 32 - 1] == 'E')
		{
			check_beer = ft_check_beer(game);
			if (check_beer == 0)
			{
				game->nbr_move++;
				printf("Move left,  total steps: %d\n", game->nbr_move);
				mlx_put_image_to_window(game->mlx, game->window, game->ground, game->player_x, game->player_y);
				game->player_x -= 32;
				mlx_put_image_to_window(game->mlx, game->window, game->player, game->player_x, game->player_y);
				printf("Congratulations, you are drunk\n");
				exit (0);
			}

		}
		else
		{
			game->nbr_move++;
			printf("Move left,  total steps: %d\n", game->nbr_move);
			mlx_put_image_to_window(game->mlx, game->window, game->ground, game->player_x, game->player_y);
			game->player_x -= 32;
			mlx_put_image_to_window(game->mlx, game->window, game->player, game->player_x, game->player_y);
		}
			if (game->map[game->player_y / 32][game->player_x / 32] == 'C')
			game->map[game->player_y / 32][game->player_x / 32] = '0';

	}
	else if (keycode == 1 && game->map[game->player_y / 32 + 1][game->player_x / 32] != '1')
	{
		if (game->map[game->player_y / 32 + 1][game->player_x / 32] == 'E')
		{
			check_beer = ft_check_beer(game);
			if (check_beer == 0)
			{
				game->nbr_move++;
				printf("Move down,  total steps: %d\n", game->nbr_move);
				mlx_put_image_to_window(game->mlx, game->window, game->ground, game->player_x, game->player_y);
				game->player_y += 32;
				mlx_put_image_to_window(game->mlx, game->window, game->player, game->player_x, game->player_y);
				printf("Congratulations, you are drunk\n");
				exit (0);
			}
		}
		else
		{
			game->nbr_move++;
			printf("Move down,  total steps: %d\n", game->nbr_move);
			mlx_put_image_to_window(game->mlx, game->window, game->ground, game->player_x, game->player_y);
			game->player_y += 32;
			mlx_put_image_to_window(game->mlx, game->window, game->player, game->player_x, game->player_y);
		}
		if (game->map[game->player_y / 32][game->player_x / 32] == 'C')
			game->map[game->player_y / 32][game->player_x / 32] = '0';
	}
	else if (keycode == 2 && game->map[game->player_y / 32][game->player_x / 32 + 1] != '1')
	{
		if (game->map[game->player_y / 32][game->player_x / 32 + 1] == 'E')
		{
			check_beer = ft_check_beer(game);
			if (check_beer == 0)
			{
				game->nbr_move++;
				printf("Move right, total steps: %d\n", game->nbr_move);
				mlx_put_image_to_window(game->mlx, game->window, game->ground, game->player_x, game->player_y);
				game->player_x += 32;
				mlx_put_image_to_window(game->mlx, game->window, game->player, game->player_x, game->player_y);
				printf("Congratulations, you are drunk\n");
				exit (0);
			}
		}
		else
		{
			game->nbr_move++;
			printf("Move right, total steps: %d\n", game->nbr_move);
			mlx_put_image_to_window(game->mlx, game->window, game->ground, game->player_x, game->player_y);
			game->player_x += 32;
			mlx_put_image_to_window(game->mlx, game->window, game->player, game->player_x, game->player_y);
		}
		if (game->map[game->player_y / 32][game->player_x / 32] == 'C')
			game->map[game->player_y / 32][game->player_x / 32] = '0';
	}
	else if (keycode == 53)
	{
		printf("You left the bar\n");
		exit(0);
	}

	return (0);
}

int	main(int argc, char **argv)
{
	t_game	game;
	int	len_line;

	len_line = 0;
	game.count_line = 0;
	if (argc != 2 || ft_strncmp(argv[1] + strlen(argv[1]) - 4, ".ber", 4) != 0)
	{
		printf("Error\nInvalid input\n");
		return (0);
	}

	game.fd = open(argv[1], O_RDONLY);
	while ((game.line = get_next_line(game.fd)) != NULL)
	{
		game.count_line++;
		if (len_line == 0)
			len_line = ft_strlen(game.line) - 1;
		free(game.line);
	}
	close(game.fd);
	game.width = 32;
	game.height = 32;
	game.mlx = mlx_init();
	game.window = mlx_new_window(game.mlx, (32 * len_line), (32 * game.count_line), "Welcome in my bar !");
	game.wall = mlx_xpm_file_to_image(game.mlx, "assets/wall.xpm", &game.width, &game.height);
	game.ground = mlx_xpm_file_to_image(game.mlx, "assets/ground.xpm", &game.width, &game.height);
	game.beer = mlx_xpm_file_to_image(game.mlx, "assets/beer.xpm", &game.width, &game.height);
	game.exit = mlx_xpm_file_to_image(game.mlx, "assets/exit.xpm", &game.width, &game.height);
	game.player = mlx_xpm_file_to_image(game.mlx, "assets/player.xpm", &game.width, &game.height);
	game.y = 0;
	game.fd = open(argv[1], O_RDONLY);
	game.nbr_move = 0;
	while ((game.line = get_next_line(game.fd)) != NULL)
	{
		game.x = 0;
		game.i = 0;
		while (game.line[game.i] != '\0' && game.line[game.i] != '\n')
		{
			if (game.line[game.i] == '1')
				mlx_put_image_to_window(game.mlx, game.window, game.wall, game.x, game.y);
			else if (game.line[game.i] == '0')
				mlx_put_image_to_window(game.mlx, game.window, game.ground, game.x, game.y);
			else if (game.line[game.i] == 'C')
				mlx_put_image_to_window(game.mlx, game.window, game.beer, game.x, game.y);
			else if (game.line[game.i] == 'E')
				mlx_put_image_to_window(game.mlx, game.window, game.exit, game.x, game.y);
			else if (game.line[game.i] == 'P')
			{
				mlx_put_image_to_window(game.mlx, game.window, game.player, game.x, game.y);
				game.player_x = game.x;
				game.player_y = game.y;
			}
			game.i++;
			game.x += game.width;
		}
		len_line = game.i;
		game.count_line++;
		game.y += game.height;
		free(game.line);
	}
	close(game.fd);
	ft_fill_map(argv, &game);
	if (ft_check_map(&game) == 1 || ft_check_wall(&game) == 1 || ft_valid_path(&game) == 1)
	{
		printf("Error\nInvalid map\n");
		return (0);
	}
	mlx_key_hook(game.window, ft_movements, &game);
	mlx_hook(game.window, 17, 1L << 2, ft_close_window, NULL);
	mlx_loop(game.mlx);
}
