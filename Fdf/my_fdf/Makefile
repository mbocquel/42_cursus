# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/06 10:48:53 by mbocquel          #+#    #+#              #
#    Updated: 2022/12/08 23:46:38 by mbocquel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SOURCES_DIR = srcs/

SOURCES = 	main.c \
			put_circle_img.c \
			my_mlx_pixel_put.c \
			put_segment_img.c \
			ft_swap_seg.c \
			create_color_code.c \
			get_color_gradian.c \
			parsing.c \
			parsing2.c \
			trame_iso.c \
			free_functions.c\
			functions_get_map_info.c
			
OBJECTS		= $(addprefix ${SOURCES_DIR}, ${SOURCES:.c=.o})

DEP		= $(addprefix ${SOURCES_DIR}, ${SOURCES:.c=.d})

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

$(NAME):	$(OBJECTS) 
			make -C $(LIBFT_DIR)
			make -C $(MINILIBX_DIR)
			$(CC) $(CFLAGS) $(OBJECTS) $(CLIB) -o $(NAME)

clean:
	$(RM) $(OBJECTS)
	make clean -C $(LIBFT_DIR)
	make clean -C $(MINILIBX_DIR)

fclean: clean
	$(RM)  $(NAME)
	$(RM)  $(DEP)
	make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re

