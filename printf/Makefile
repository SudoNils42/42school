# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nbonnet <nbonnet@student.42lausanne.ch>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/14 10:57:50 by nbonnet           #+#    #+#              #
#    Updated: 2024/10/15 16:35:46 by nbonnet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Werror -Wextra

SRCS = ft_printf.c ft_un.c ft_hexa.c ft_hexa_up.c ft_hexa_p.c

OBJS = $(SRCS:.c=.o)

NAME = libftprintf.a

CHEMIN = ./libft

LIBFT = $(CHEMIN)/libft.a

all: $(LIBFT) $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	cp $(LIBFT) $(NAME)
	ar rcs $(NAME) $(OBJS)


$(LIBFT):
	make -C $(CHEMIN)

clean:
	rm -rf $(OBJS)
	make clean -C $(CHEMIN)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(CHEMIN)

re: fclean all

.PHONY: all clean fclean re
