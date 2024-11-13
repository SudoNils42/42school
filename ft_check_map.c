/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbonnet <nbonnet@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 16:18:57 by nbonnet           #+#    #+#             */
/*   Updated: 2024/11/13 18:51:58 by nbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_map(t_game *game)
{
	int	i;
	int	j;
	int	flag_E;
	int	flag_C;
	int	flag_P;

	flag_E = 0;
	flag_C = 0;
	flag_P = 0;
	i = 0;
	while (i < game->count_line)
	{
		if (ft_strlen(game->map[i]) != game->len_map)
			return (1);
		else
			i++;
	}
	i = 0;
	while (i < game->count_line)
	{
		j = 0;
		while (game->map[i][j] != '\0')
		{
			if (game->map[i][j] == 'E')
				flag_E++;
			else if (game->map[i][j] == 'C')
				flag_C++;
			else if (game->map[i][j] == 'P')
				flag_P++;
			j++;
		}
		i++;
	}
	if (flag_E != 1 || flag_P != 1 || flag_C < 1)
		return (1);
	return (0);
}

