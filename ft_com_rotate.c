/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_com_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbonnet <nbonnet@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 18:12:59 by nbonnet           #+#    #+#             */
/*   Updated: 2024/11/29 14:49:35 by nbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_var *var)
{
	int	i;
	int	temp;

	i = 0;
	if (var->size_a <= 1)
		return ;
	temp = var->a[0];
	while (i < var->size_a - 1)
	{
		var->a[i] = var->a[i + 1];
		i++;
	}
	var->a[var->size_a - 1] = temp;
	ft_printf("ra\n");
}

void	rotate_b(t_var *var)
{
	int	i;
	int	temp;

	i = 0;
	if (var->size_b <= 1)
		return ;
	temp = var->b[0];
	while (i < var->size_b - 1)
	{
		var->b[i] = var->b[i + 1];
		i++;
	}
	var->b[var->size_b - 1] = temp;
	ft_printf("rb\n");
}

void	rotate_ab(t_var *var)
{
	int	i;
	int	temp;

	i = 0;
	if (var->size_a <= 1)
		return ;
	temp = var->a[0];
	while (i < var->size_a - 1)
	{
		var->a[i] = var->a[i + 1];
		i++;
	}
	var->a[var->size_a - 1] = temp;
	i = 0;
	if (var->size_b <= 1)
		return ;
	temp = var->b[0];
	while (i < var->size_b - 1)
	{
		var->b[i] = var->b[i + 1];
		i++;
	}
	var->b[var->size_b - 1] = temp;
	ft_printf("rr\n");
}
