/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbonnet <nbonnet@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 11:48:58 by nbonnet           #+#    #+#             */
/*   Updated: 2024/10/15 16:35:40 by nbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft/libft.h"
# include <stdlib.h>
# include <stdarg.h>

int		ft_printf(const char *s, ...);
char	*ft_un(unsigned int n);
char	*ft_hexa(unsigned int n);
char	*ft_hexa_up(unsigned int n);
char	*ft_hexa_p(void *p);
#endif
