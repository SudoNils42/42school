/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_com_reverse_rotate.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbonnet <nbonnet@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 18:12:54 by nbonnet           #+#    #+#             */
/*   Updated: 2024/11/29 14:58:21 by nbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate_a(t_var *var)
{
	int	i;
	int	temp;

	if (var->size_a <= 1)
		return ;
	temp = var->a[var->size_a - 1];
	i = var->size_a - 1;
	while (i > 0)
	{
		var->a[i] = var->a[i - 1];
		i--;
	}
	var->a[0] = temp;
	ft_printf("rra\n");
}

void	reverse_rotate_b(t_var *var)
{
	int	i;
	int	temp;

	if (var->size_b <= 1)
		return ;
	temp = var->b[var->size_b - 1];
	i = var->size_b - 1;
	while (i > 0)
	{
		var->b[i] = var->b[i - 1];
		i--;
	}
	var->b[0] = temp;
	ft_printf("rrb\n");
}

void	reverse_rotate_ab(t_var *var)
{
	int	i;
	int	temp;

	if (var->size_a <= 1)
		return ;
	temp = var->a[var->size_a - 1];
	i = var->size_a - 1;
	while (i > 0)
	{
		var->a[i] = var->a[i - 1];
		i--;
	}
	var->a[0] = temp;
		if (var->size_b <= 1)
		return ;
	temp = var->b[var->size_b - 1];
	i = var->size_b - 1;
	while (i > 0)
	{
		var->b[i] = var->b[i - 1];
		i--;
	}
	var->b[0] = temp;
	ft_printf("rrr\n");
}
