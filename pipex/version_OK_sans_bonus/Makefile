# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/06 10:48:53 by mbocquel          #+#    #+#              #
#    Updated: 2023/01/19 13:45:13 by mbocquel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

#NAME_BONUS = pipex_bonus

SOURCES_DIR = ./srcs/

BUILD_DIR = ./build/

SOURCES = 	main.c \
			parsing.c \
			ft_exit.c \
			
#SOURCES_BONUS = 

OBJECTS		= $(addprefix ${BUILD_DIR}, ${SOURCES:.c=.o})

#OBJECTS_BONUS = $(addprefix ${BUILD_DIR}, ${SOURCES_BONUS:.c=.o})

DEPS := $(OBJECTS:.o=.d)

#DEPS_BONUS := $(OBJECTS_BONUS:.o=.d)

CC = gcc

CFLAGS = -Wall -Wextra -Werror -MMD -MP -g3

RM = rm -rf

LIBFT_DIR = libft/

CLIB = -Llibft -lft

all: $(NAME)

#bonus: $(NAME_BONUS)

$(BUILD_DIR)%.o: $(SOURCES_DIR)%.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -O3 -c $< -o $@

$(NAME):	$(OBJECTS) 
			make -C $(LIBFT_DIR)
			$(CC) $(CFLAGS) $(OBJECTS) $(CLIB) -o $(NAME)

#$(NAME_BONUS):	$(OBJECTS_BONUS) 
#			make -C $(LIBFT_DIR)
#			$(CC) $(CFLAGS) $(OBJECTS_BONUS) $(CLIB) -o $(NAME_BONUS)

clean:
	$(RM) $(BUILD_DIR)
	make clean -C $(LIBFT_DIR)

fclean: clean
	$(RM)  $(NAME)
	make fclean -C $(LIBFT_DIR)
#fclean: clean
#	$(RM)  $(NAME) $(NAME_BONUS)
#	make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re
#.PHONY: all clean fclean re bonus

-include $(DEPS)
#-include $(DEPS) $(DEPS_BONUS)