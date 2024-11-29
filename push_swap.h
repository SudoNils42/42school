/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbonnet <nbonnet@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 13:38:57 by nbonnet           #+#    #+#             */
/*   Updated: 2024/11/29 16:23:27 by nbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"
# include "printf/ft_printf.h"
# include <stdlib.h>
# include <unistd.h>

typedef struct s_var
{
	int	i;
	int	tot_nbr;
	int	*a;
	int	*b;
	int	size_a;
	int	size_b;
	char	**tab;
	int	sign;
	long long	n;
} t_var;

void	swap_a(t_var *var);
void	swap_b(t_var *var);
void	swap_ss(t_var *var);
void	push_a(t_var *var);
void	push_b(t_var *var);
void	rotate_a(t_var *var);
void	rotate_b(t_var *var);
void	rotate_ab(t_var *var);
void	reverse_rotate_a(t_var *var);
void	reverse_rotate_b(t_var *var);
void	reverse_rotate_ab(t_var *var);

#endif
