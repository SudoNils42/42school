/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbonnet <nbonnet@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 17:34:09 by nbonnet           #+#    #+#             */
/*   Updated: 2024/11/15 17:58:36 by nbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_valid_path(t_game *game)
{
	int	collected_beer;

	collected_beer = 0;



	if (collected_beer != ft_count_beer(&game))
		return (1);
	return (0);
}

int	ft_count_beer(t_game *game)
{
	int	i;
	int	j;
	int count_beer;

	i = 0;
	j = 0;
	count_beer = 0;
	while (j < game->count_line)
	{
		i = 0;
		while (game->map[j][i] != '\n' || game->map[j][i] != '\0')
		{
			if (game->map[j][i] == 'C')
				count_beer++;
			i++;
		}
		j++;
	}
	return (count_beer);
}
