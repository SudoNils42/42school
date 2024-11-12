/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbonnet <nbonnet@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 11:03:32 by nbonnet           #+#    #+#             */
/*   Updated: 2024/10/15 16:58:40 by nbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <stdarg.h>
#include "ft_printf.h"

static int	ft_printcs(int j, int i, const char *s, va_list va)
{
	char	*str;

	if (s[i] == 'c')
	{
		ft_putchar_fd((char)va_arg(va, int), 1);
		j++;
	}
	else if (s[i] == 's')
	{
		str = va_arg(va, char *);
		if (str != NULL)
		{
			ft_putstr_fd(str, 1);
			j = j + ft_strlen(str);
		}
		else
		{
			write(1, "(null)", 6);
			j = j + 6;
		}
	}
	return (j);
}

static int	ft_printidu(int j, int i, const char *s, va_list va)
{
	char	*str;

	if (s[i] == 'i' || s[i] == 'd')
	{
		str = ft_itoa(va_arg(va, int));
		if (str != NULL)
		{
			ft_putstr_fd(str, 1);
			j = j + ft_strlen(str);
			free(str);
		}
	}
	else if (s[i] == 'u')
	{
		str = ft_un(va_arg(va, unsigned int));
		if (str != NULL)
		{
			ft_putstr_fd(str, 1);
			j = j + ft_strlen(str);
			free(str);
		}
	}
	return (j);
}

static int	ft_printxx(int j, int i, const char *s, va_list va)
{
	char	*str;

	if (s[i] == 'x')
	{
		str = ft_hexa(va_arg(va, unsigned int));
		if (str != NULL)
		{
			ft_putstr_fd(str, 1);
			j = j + ft_strlen(str);
			free(str);
		}
	}
	else if (s[i] == 'X')
	{
		str = ft_hexa_up(va_arg(va, unsigned int));
		if (str != NULL)
		{
			ft_putstr_fd(str, 1);
			j = j + ft_strlen(str);
			free(str);
		}
	}
	return (j);
}

static int	ft_printpp(int j, int i, const char *s, va_list va)
{
	char	*str;

	if (s[i] == '%')
	{
		write(1, "%%", 1);
		j++;
	}
	else if (s[i] == 'p')
	{
		str = ft_hexa_p(va_arg(va, void *));
		if (str != NULL)
		{
			write(1, "0x", 2);
			ft_putstr_fd(str, 1);
			j = j + 2 + ft_strlen(str);
			free(str);
		}
	}
	return (j);
}

int	ft_printf(const char *s, ...)
{
	int		i;
	int		j;
	va_list	va;

	va_start(va, s);
	i = -1;
	j = 0;
	while (s[++i] != '\0')
	{
		if (s[i] == '%')
		{
			i++;
			j = ft_printcs(j, i, s, va);
			j = ft_printidu(j, i, s, va);
			j = ft_printxx(j, i, s, va);
			j = ft_printpp(j, i, s, va);
		}
		else
		{
			write(1, &s[i], 1);
			j++;
		}
	}
	va_end(va);
	return (j);
}
