/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbonnet <nbonnet@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 15:23:51 by nbonnet           #+#    #+#             */
/*   Updated: 2024/11/07 15:34:37 by nbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

char	*get_next_line(int fd);
int		ft_strlen1(char *s);
char	*ft_find_nl(char *rest);
char	*ft_strcat1(char	*updated_rest, char *rest, char *buf, int len);
char	*ft_find_line(char *rest);
char	*ft_find_rest(char *rest);
char	*ft_strjoin1(char *rest, char *buf);
char	*ft_read_until_nl(int fd, char *buf, char *rest);
#endif
