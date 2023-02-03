# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/06 10:48:53 by mbocquel          #+#    #+#              #
#    Updated: 2023/02/03 18:25:26 by mbocquel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

SOURCES_DIR = ./srcs/

BUILD_DIR = ./build/

SOURCES = 	main.c \
			parsing.c \
			utils.c \
			print.c \
			
OBJECTS		= $(addprefix ${BUILD_DIR}, ${SOURCES:.c=.o})

DEPS := $(OBJECTS:.o=.d)

CC = gcc

CFLAGS = -Wall -Wextra -Werror -MMD -MP -g3 -pthread

RM = rm -rf

CLIB = -lpthread

all: $(NAME)

$(BUILD_DIR)%.o: $(SOURCES_DIR)%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -O3 -c $< -o $@
	@echo "Compiling " $<

$(NAME):	$(OBJECTS)
			@$(CC) $(CFLAGS) $(OBJECTS) $(CLIB) -o $(NAME)
			@echo "\nCreating ./"$(NAME)
			@echo "\nAll done!"

clean:
	$(RM) $(BUILD_DIR)

fclean: clean
	$(RM)  $(NAME)

re: fclean all

.PHONY: all clean fclean re

-include $(DEPS)
