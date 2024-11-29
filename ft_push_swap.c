/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbonnet <nbonnet@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 13:35:01 by nbonnet           #+#    #+#             */
/*   Updated: 2024/11/29 17:11:15 by nbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoll(t_var *var, const char *str)
{
	int	i;

	i = 0;
	var->sign = 1;
	var->n = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		i++;
	if (str[i] == '-')
	{
		var->sign *= -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		var->n = (var->n * 10) + (str[i] - 48);
		i++;
	}
	if (var->n > 2147483647 || var->n < -2147483648)
		return (0);
	if (str[i] != '\0')
		return (0);
	return (var->sign * var->n);
}
int	is_sorted(t_var *var)
{
	int	i;

	i = 0;
	while (i < var->size_a - 1)
	{
		if (var->a[i] > var->a[i + 1])
			return (1);
		i++;
	}
	return (0);
}


int	check_double(t_var *var)
{
	int	i;
	int	j;

	i = 0;
	while (i < var->tot_nbr)
	{
		j = i + 1;
		while (j < var->tot_nbr)
		{
			if (var->a[i] == var->a[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int main(int ac, char **av)
{
	t_var var;

	if (ac == 1)
		return (0);
	if (ac == 2)
	{
		var.tab = ft_split(av[1], ' ');
		if (!var.tab)
			return (0);
		var.tot_nbr = 0;
		while (var.tab[var.tot_nbr] != NULL)
			var.tot_nbr++;
	}
	else
	{
		var.tot_nbr = ac - 1;
		var.tab = av + 1;
	}
	var.i = 0;
	var.a = malloc(sizeof(int) * var.tot_nbr);
	if (!var.a)
		return (0);
	var.b = malloc(sizeof(int) * var.tot_nbr);
	if (!var.b)
		return (0);

	while (var.i < var.tot_nbr)
	{
		var.a[var.i] = ft_atoll(&var, var.tab[var.i]);
		if (ft_atoll(&var, var.tab[var.i]) == 0 && var.a[var.i] != '0')
		{
			ft_printf("Error\n");
			return (0);
		}
		var.i++;
	}
	if (check_double(&var) == 1)
	{
		ft_printf("Error\n");
		return (0);
	}
	var.size_a = var.tot_nbr;
	var.size_b = 0;
	ft_printf("stack a:\n");
	var.i = 0;
	while (var.i < var.tot_nbr)
	{
		ft_printf("%d\n", var.a[var.i]);
		var.i++;
	}
	var.i = 0;
	ft_printf("stack b:\n");
	while (var.b[var.i])
	{
		ft_printf("%d\n", var.b[var.i]);
		var.i++;
	}
	return (0);
}
