# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nbonnet <nbonnet@student.42lausanne.ch>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/05 11:32:19 by nbonnet           #+#    #+#              #
#    Updated: 2024/11/29 17:00:20 by nbonnet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

PATH_LIBFT = ./libft
LIBFT = $(PATH_LIBFT)/libft.a

PATH_PRINTF = ./printf
PRINTF = $(PATH_PRINTF)/libftprintf.a

CC = cc
CFLAGS = -Wall -Werror -Wextra -g
SRCS = ft_push_swap.c ft_com_swap_push.c ft_com_rotate.c ft_com_reverse_rotate.c
OBJS = $(SRCS:.c=.o)

all: $(LIBFT) $(PRINTF) $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(PRINTF) -o $(NAME)

$(LIBFT):
	make -C $(PATH_LIBFT)

$(PRINTF):
	make -C $(PATH_PRINTF)

clean:
	rm -rf $(OBJS)
	make clean -C $(PATH_LIBFT)
	make clean -C $(PATH_PRINTF)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(PATH_LIBFT)
	make fclean -C $(PATH_PRINTF)

re: fclean all

.PHONY: all clean fclean re
