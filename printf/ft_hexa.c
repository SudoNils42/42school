/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbonnet <nbonnet@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 11:22:53 by nbonnet           #+#    #+#             */
/*   Updated: 2024/10/15 16:01:56 by nbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_h1(void)
{
	char	*str;

	str = malloc(sizeof(char) * 2);
	if (!str)
		return (0);
	str[0] = '0';
	str[1] = '\0';
	return (str);
}

static int	ft_h2(unsigned int n, int rest)
{
	int	i;

	i = 0;
	while (n != 0)
	{
		rest = n % 16;
		if (rest > 9)
			rest = rest + 87;
		n = n / 16;
		i++;
	}
	return (i);
}

static char	*ft_h3(unsigned int n, int i, int rest, char *str)
{
	while (n != 0)
	{
		rest = n % 16;
		if (rest > 9)
			rest = rest + 87;
		else
			rest = rest + '0';
		str[i] = rest;
		n = n / 16;
		i--;
	}
	return (str);
}

char	*ft_hexa(unsigned int n)
{
	int				i;
	int				rest;
	char			*str;
	unsigned int	nbr;

	nbr = n;
	i = 0;
	rest = 0;
	if (n == 0)
		return (ft_h1());
	i = ft_h2(n, rest);
	str = malloc(sizeof(char) * (i + 1));
	if (!str)
		return (0);
	n = nbr;
	str[i] = '\0';
	i--;
	ft_h3(n, i, rest, str);
	return (str);
}
