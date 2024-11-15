/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbonnet <nbonnet@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 17:49:55 by nbonnet           #+#    #+#             */
/*   Updated: 2024/11/15 17:36:31 by nbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <math.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <mlx.h>
# include "libft/libft.h"
# include "printf/ft_printf.h"
# include "get_next_line/get_next_line.h"
#include <fcntl.h>

typedef struct s_game
{
	void	*mlx;
	void	*window;
	void	*wall;
	void	*ground;
	void	*beer;
	void	*exit;
	void	*player;
	int		width;
	int		height;
	int		fd;
	char	*line;
	int		x;
	int		y;
	int		i;
	int		player_x;
	int		player_y;
	int		count_line;
	char	**map;
	int		nbr_move;
	int		len_map;
}	t_game;

int	ft_check_map(t_game *game);
int	ft_check_wall(t_game *game);
int	ft_valid_path(t_game *game);
void	ft_fill_map(char **argv, t_game *game);


#endif
