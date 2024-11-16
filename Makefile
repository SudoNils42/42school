# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nbonnet <nbonnet@student.42lausanne.ch>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/05 11:32:19 by nbonnet           #+#    #+#              #
#    Updated: 2024/11/16 15:10:52 by nbonnet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

PATH_GNL = ./get_next_line

PATH_MLX = ./minilibx_opengl_20191021
MLX = $(PATH_MLX)/libmlx.a

PATH_LIBFT = ./libft
LIBFT = $(PATH_LIBFT)/libft.a

PATH_PRINTF = ./printf
PRINTF = $(PATH_PRINTF)/libftprintf.a

CC = cc
CFLAGS = -Wall -Werror -Wextra -I$(PATH_MLX)
SRCS = $(PATH_GNL)/get_next_line_utils.c $(PATH_GNL)/get_next_line.c ft_so_long.c ft_check_map.c ft_valid_path.c
OBJS = $(SRCS:.c=.o)

all: $(LIBFT) $(PRINTF) $(MLX) $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(PRINTF) $(MLX) -framework OpenGL -framework AppKit -o $(NAME)

$(MLX):
	make -C $(PATH_MLX)

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
