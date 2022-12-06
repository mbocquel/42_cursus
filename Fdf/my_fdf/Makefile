# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/06 10:48:53 by mbocquel          #+#    #+#              #
#    Updated: 2022/12/06 12:06:11 by mbocquel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SOURCES = main.c 

HEADERS = .

OBJECTS = $(SOURCES:.c=.o)

NAME = fdf

CC = cc

CFLAGS = -Wall -Wextra -Werror -MMD -MP

RM = rm -f

LIBFT_DIR = libft/

MINILIBX_DIR = mlx_linux/

OMLX = -I/usr/include -Imlx_linux

CLIB = -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz \
		-Llibft -lft

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(OMLX) -O3 -c $< -o $@

$(NAME):	$(OBJECTS) $(LIBFT_DIR)libft.a $(MINILIBX_DIR)libmlx_linux.a
			$(CC) $(CFLAGS) $(OBJECTS) $(CLIB) -o $(NAME)

$(MINILIBX_DIR)libmlx_linux.a: 
	make -C $(MINILIBX_DIR)

$(LIBFT_DIR)libft.a: 
	make -C $(LIBFT_DIR)

clean:
	$(RM) $(OBJECTS)
	make clean -C $(LIBFT_DIR)
	make clean -C $(MINILIBX_DIR)

fclean: clean
	$(RM)  $(NAME)
	make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re

