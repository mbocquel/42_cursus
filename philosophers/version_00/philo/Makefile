# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/06 10:48:53 by mbocquel          #+#    #+#              #
#    Updated: 2023/02/08 10:21:33 by mbocquel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

SOURCES_DIR = ./srcs/

BUILD_DIR = ./build/

SOURCES = 	test.c
#			main.c \
#			parsing.c \
#			utils.c \
#			print.c \
#			routines.c \
#			garbage.c \
			
OBJECTS		= $(addprefix ${BUILD_DIR}, ${SOURCES:.c=.o})

DEPS := $(OBJECTS:.o=.d)

CC = cc

CFLAGS = -Wall -Wextra -Werror -pthread -g3

DEPS_FLAGS = -MMD -MP

RM = rm -rf

CLIB = -lpthread

all: $(NAME)

$(BUILD_DIR)%.o: $(SOURCES_DIR)%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(DEPS_FLAGS) -c $< -o $@
	@echo "\033[92mCompiling " $< "\033[0m"

$(NAME):	$(OBJECTS)
			@$(CC) $(CFLAGS) $(DEPS_FLAGS) $(OBJECTS) $(CLIB) -o $(NAME)
			@echo "\nCreating ./"$(NAME)
			@echo "\nAll done!"

clean:
	$(RM) $(BUILD_DIR)

fclean: clean
	$(RM)  $(NAME)

re: fclean all

.PHONY: all clean fclean re

-include $(DEPS)
