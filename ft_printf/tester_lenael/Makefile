# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iaschnei <iaschnei@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/28 14:47:50 by iaschnei          #+#    #+#              #
#    Updated: 2022/11/24 13:24:26 by iaschnei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re bonus

SRCS		=	#ADD YOUR SOURCES HERE

NAME		=	test

HEAD		=	#ADD YOUR HEADER HERE

OBJS		=	${SRCS:.c=.o}	

CC			=	cc -w

COLOR_GREEN=	\033[1;32m
COLOR_RED	=	\033[1;31m
COLOR_BLUE	=	\033[3;36m
COLOR_PURP	=	\033[1;35m
COLOR_END	=	\033[0m

%.o: %.c
	@${CC} -include ${HEAD} -c $< -o $@
	@echo "${COLOR_BLUE}|| Compiling ($<)...${COLOR_END}"

all: ${NAME}

${NAME}: ${OBJS} 
	@${CC} ${OBJS} main.c -o ${NAME}
	@echo "${COLOR_GREEN}|| Done !\n"
	@echo "${COLOR_RED} ___ ___      __   __         ___  ___   ___  ___  __  ___  ___  __   "
	@echo "|__   |      |__) |__) | |\ |  |  |__     |  |__  /__\`  |  |__  |__)  "
	@echo "|     |  ___ |    |  \ | | \|  |  |       |  |___ .__/  |  |___ |  \  "
	@echo "______________________________________________________________________\n ${COLOR_END}"
	@./test

clean:
	@rm -f ${OBJS}
	@echo "${COLOR_PURP}|| Cleaning files...${COLOR_END}"

fclean: clean
	@rm -f ${NAME}
	@echo "${COLOR_PURP}|| Cleaning library...${COLOR_END}"

re: fclean all
