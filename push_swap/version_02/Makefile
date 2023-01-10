# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/06 10:48:53 by mbocquel          #+#    #+#              #
#    Updated: 2023/01/09 16:59:51 by mbocquel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SOURCES_DIR = srcs/

SOURCES = 	main.c \
			free_functions.c \
			parsing.c \
			add_to_pile.c \
			actions_elem.c  \
			print_piles.c \
			get_final_position.c \
			start_process_3.c \
			start_process_5.c \
			start_process_big.c \
			add_action.c \
						
OBJECTS		= $(addprefix ${SOURCES_DIR}, ${SOURCES:.c=.o})

CC = gcc

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

