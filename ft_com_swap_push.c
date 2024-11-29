/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_com_swap_push.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbonnet <nbonnet@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 17:28:13 by nbonnet           #+#    #+#             */
/*   Updated: 2024/11/29 14:36:59 by nbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_var *var)
{
	int	temp;

	if (!var->a[0] || !var->a[1])
		return ;
	ft_printf("sa\n");
	temp = var->a[0];
	var->a[0] = var->a[1];
	var->a[1] = temp;
}
void	swap_b(t_var *var)
{
	int	temp;

	if (!var->b[0] || !var->b[1])
		return ;
	ft_printf("sb\n");
	temp = var->b[0];
	var->b[0] = var->b[1];
	var->b[1] = temp;
}
void	swap_ss(t_var *var)
{
	if (!var->a[0] || !var->a[1] || !var->b[0] || !var->b[1])
		return ;
	ft_printf("ss\n");
	swap_a(var);
	swap_b(var);
}
void	push_a(t_var *var)
{
	int	i;

	if (!var->b[0])
		return ;
	ft_printf("pa\n");
	i = var->size_a;
	while (i > 0)
	{
		var->a[i] = var->a[i - 1];
		i--;
	}
	var->a[0] = var->b[0];
	var->size_a++;
	i = 0;
	while (i < var->size_b - 1)
	{
		var->b[i] = var->b[i + 1];
		i++;
	}
	var->size_b--;
}

void	push_b(t_var *var)
{
	int	i;

	if (!var->a[0])
		return ;
	ft_printf("pb\n");
	i = var->size_b;
	while (i > 0)
	{
		var->b[i] = var->b[i - 1];
		i--;
	}
	var->b[0] = var->a[0];
	var->size_b++;
	i = 0;
	while (i < var->size_a - 1)
	{
		var->a[i] = var->a[i + 1];
		i++;
	}
	var->size_a--;
}
