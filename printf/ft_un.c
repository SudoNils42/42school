/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_un.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbonnet <nbonnet@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 17:14:38 by nbonnet           #+#    #+#             */
/*   Updated: 2024/10/15 12:42:43 by nbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	char	*ft_itoa2_un(void)
{
	char	*dst;

	dst = (char *)malloc(sizeof(char) * 2);
	if (!dst)
		return (0);
	dst[0] = '0';
	dst[1] = '\0';
	return (dst);
}

static int	nbrlen_un(unsigned int n)
{
	int	i;

	i = 0;
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_un(unsigned int n)
{
	unsigned int		i;
	char				*dst;

	if (n == 0)
		return (ft_itoa2_un());
	i = nbrlen_un(n);
	dst = (char *)malloc(sizeof(char) * (i + 1));
	if (!dst)
		return (0);
	dst[i] = '\0';
	i = i - 1;
	while (n != 0)
	{
		dst[i] = (n % 10) + '0';
		n = n / 10;
		i--;
	}
	return (dst);
}
