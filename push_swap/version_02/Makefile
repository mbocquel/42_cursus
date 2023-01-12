# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/06 10:48:53 by mbocquel          #+#    #+#              #
#    Updated: 2023/01/11 17:40:14 by mbocquel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

NAME_BONUS = checker

SOURCES_DIR = ./srcs/

BUILD_DIR = ./build/

SOURCES = 	actions/actions_elem.c \
			actions/add_action.c \
			actions/double_actions.c \
			parsing/add_to_pile.c \
			parsing/get_final_position.c \
			parsing/parsing.c \
			utils/free_exit.c \
			utils/ft_math.c \
			utils/push_swap_utils.c \
			main.c \
			print.c \
			process_big_back_to_a.c \
			process_big_to_b.c \
			process_small.c \

SOURCES_BONUS = actions/actions_elem.c \
				actions/add_action.c \
				actions/double_actions.c \
				parsing/add_to_pile.c \
				parsing/get_final_position.c \
				parsing/parsing.c \
				utils/free_exit.c \
				utils/ft_math.c \
				utils/push_swap_utils.c \
				bonus/main_bonus.c \
				print.c \

OBJECTS		= $(addprefix ${BUILD_DIR}, ${SOURCES:.c=.o})

OBJECTS_BONUS = $(addprefix ${BUILD_DIR}, ${SOURCES_BONUS:.c=.o})

DEPS := $(OBJECTS:.o=.d)

DEPS_BONUS := $(OBJECTS_BONUS:.o=.d)

CC = gcc

CFLAGS = -Wall -Wextra -Werror -MMD -MP

RM = rm -rf

LIBFT_DIR = libft/

CLIB = -Llibft -lft

all: $(NAME)

bonus: $(NAME_BONUS)

$(BUILD_DIR)%.o: $(SOURCES_DIR)%.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -O3 -c $< -o $@

$(NAME):	$(OBJECTS) 
			make -C $(LIBFT_DIR)
			$(CC) $(CFLAGS) $(OBJECTS) $(CLIB) -o $(NAME)

$(NAME_BONUS):	$(OBJECTS_BONUS) 
			make -C $(LIBFT_DIR)
			$(CC) $(CFLAGS) $(OBJECTS_BONUS) $(CLIB) -o $(NAME_BONUS)

clean:
	$(RM) $(BUILD_DIR)
	make clean -C $(LIBFT_DIR)

fclean: clean
	$(RM)  $(NAME) $(NAME_BONUS)
	make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re bonus

-include $(DEPS) $(DEPS_BONUS)