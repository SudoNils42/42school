/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_other.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbonnet <nbonnet@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 20:40:13 by nbonnet           #+#    #+#             */
/*   Updated: 2024/11/22 16:44:20 by nbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_close_window(t_game *game)
{
	ft_clean_up(game);
	ft_printf("You left the bar\n");
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
	game->line = get_next_line(game->fd);
	while (game->line != NULL)
	{
		game->len_map = ft_strlen(game->line);
		game->map[game->count_line]
			= malloc(sizeof(char) * (game->len_map + 1));
		if (!game->map[game->count_line])
		{
			ft_free_map(game);
			close(game->fd);
			return ;
		}
		ft_strlcpy(game->map[game->count_line], game->line, game->len_map + 1);
		game->count_line++;
		free(game->line);
		game->line = get_next_line(game->fd);
	}
	game->map[game->count_line] = NULL;
	close(game->fd);
}
