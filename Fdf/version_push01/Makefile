# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/06 10:48:53 by mbocquel          #+#    #+#              #
#    Updated: 2022/12/21 13:10:53 by mbocquel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SOURCES_DIR = srcs/

SOURCES = 	apply_isometric_proj.c \
			calculate_point_pos.c \
			change_z_scale.c \
			clear_all_change.c \
			clear_img.c \
			create_color_code.c \
			event_key.c \
			free_functions.c \
			ft_atoi_color.c \
			ft_swap_seg.c \
			get_alt_min_max.c \
			get_color_gradian.c \
			get_origin_coord.c \
			get_scale_factor.c \
			get_tram_elem.c \
			get_xf_min_and_max.c \
			get_yf_min_and_max.c \
			main.c \
			make_colored_trame.c \
			make_trame.c \
			my_mlx_pixel_put.c \
			parsing.c \
			print_command_list.c \
			prod_mat.c \
			put_segment_img.c \
			rotate_functions.c \
			tracer_trame.c \
			translation.c \
			zoom_unzoom.c \
						
OBJECTS		= $(addprefix ${SOURCES_DIR}, ${SOURCES:.c=.o})

CC = cc

CFLAGS = -Wall -Wextra -Werror

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
	make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re

