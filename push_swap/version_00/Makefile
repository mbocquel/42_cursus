# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/06 10:48:53 by mbocquel          #+#    #+#              #
#    Updated: 2023/01/03 18:27:36 by mbocquel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SOURCES_DIR = srcs/

SOURCES = 	main.c \
			free_functions.c \
			parsing.c \
			push_front_lst.c \
			actions_rotate.c  \
			actions_swap_push.c \
			print_piles.c \
						
OBJECTS		= $(addprefix ${SOURCES_DIR}, ${SOURCES:.c=.o})

CC = cc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

LIBFT_DIR = libft/

CLIB = -Llibft -lft

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -O3 -c $< -o $@

$(NAME):	$(OBJECTS) 
			make -C $(LIBFT_DIR)
			$(CC) $(CFLAGS) $(OBJECTS) $(CLIB) -o $(NAME)

clean:
	$(RM) $(OBJECTS)
	make clean -C $(LIBFT_DIR)

fclean: clean
	$(RM)  $(NAME)
	make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re

