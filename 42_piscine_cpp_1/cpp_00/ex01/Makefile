# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/06 10:48:53 by mbocquel          #+#    #+#              #
#    Updated: 2023/04/20 18:05:00 by mbocquel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ex01

SOURCES_DIR = ./

BUILD_DIR = ./build/

SOURCES =	class/Contact.cpp \
			class/PhoneBook.cpp \
			main.cpp

OBJECTS		= $(addprefix ${BUILD_DIR}, ${SOURCES:.cpp=.o})

DEPS := $(OBJECTS:.o=.d)

CC = c++

CFLAGS = -Wall -Wextra -Werror -MMD -MP -std=c++98

RM = rm -rf

CLIB = 

all: $(NAME)

$(BUILD_DIR)%.o: $(SOURCES_DIR)%.cpp
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "Compiling " $<

$(NAME):	$(OBJECTS)
			@echo
			@$(CC) $(CFLAGS) $(OBJECTS) $(CLIB) -o $(NAME)
			@echo "Creating ./"$(NAME)
			@echo "\nALL DONE THANKS!"

run: all
	./$(NAME)

clean:
	$(RM) $(BUILD_DIR)

fclean: clean
	$(RM)  $(NAME)

re: fclean all

.PHONY: all clean fclean re

-include $(DEPS)
