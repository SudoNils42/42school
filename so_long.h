/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbonnet <nbonnet@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 17:49:55 by nbonnet           #+#    #+#             */
/*   Updated: 2024/11/22 16:42:34 by nbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <unistd.h>
# include <mlx.h>
# include "libft/libft.h"
# include "printf/ft_printf.h"
# include "get_next_line/get_next_line.h"
# include <fcntl.h>

typedef struct s_game
{
	void	*mlx;
	void	*window;
	void	*wall;
	void	*ground;
	void	*beer;
	void	*exit;
	void	*player;
	void	*scoreboard;
	int		width;
	int		height;
	int		width_s;
	int		height_s;
	int		fd;
	char	*line;
	int		x;
	int		y;
	int		i;
	int		j;
	int		player_x;
	int		player_y;
	int		count_line;
	char	**map;
	int		nbr_move;
	int		len_map;
	char	**argv;
	int		flag_e;
	int		flag_c;
	int		flag_p;
	int		check_beer;
	int		len_line;
	char	*steps;
}	t_game;

int		ft_check_map(t_game *game);
int		ft_check_map2(t_game *game);
int		ft_check_wall(t_game *game);
void	ft_replace_C(t_game *game, int x, int y);
void	ft_replace_E(t_game *game, int x, int y);
int		ft_valid_path(t_game *game);
int		ft_valid_path2(t_game *game);
void	ft_fill_map(char **argv, t_game *game);
int		ft_check_beer(t_game *game);
void	ft_fill_map(char **argv, t_game *game);
int		ft_close_window(t_game *game);
void	ft_left(t_game *game);
void	ft_left2(t_game *game);
void	ft_up(t_game *game);
void	ft_up2(t_game *game);
int		ft_movements(int keycode, t_game *game);
void	ft_right(t_game *game);
void	ft_right2(t_game *game);
void	ft_down(t_game *game);
void	ft_down2(t_game *game);
void	ft_clean_up(t_game *game);
void	ft_free_map(t_game *game);
#endif
