#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dzui <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/25 19:37:51 by dzui              #+#    #+#              #
#    Updated: 2016/11/25 19:37:58 by dzui             ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = filler
 
SRC = filler.c \
	ft_find_path.c \
	ft_free.c \
	ft_get_data.c \
	ft_place_figure_1.c \
	ft_place_figure_2.c \
	ft_write_map_figure.c \
	ft_write_path_map_corner.c \
	ft_write_path_map.c \

OBJ = $(SRC:.c=.o)
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): libft/libft.a $(OBJ)
	gcc $(OBJ) libft/libft.a -I libft -o $(NAME)

%.o: %.c filler.h
	gcc $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJ)
	make clean -C libft

fclean: clean
	rm -f $(NAME)
	rm -f libft/libft.a
re: fclean all

libft/libft.a:
	make -C libft