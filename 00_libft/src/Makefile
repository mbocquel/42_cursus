# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/11 14:11:32 by mbocquel          #+#    #+#              #
#    Updated: 2023/01/11 14:12:09 by mbocquel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

MY_SOURCES = ft_atoi.c \
			ft_isalpha.c \
			ft_isprint.c \
			ft_memcpy.c \
			ft_strchr.c \
			ft_strlen.c \
			ft_strrchr.c \
			ft_bzero.c \
			ft_isascii.c \
			ft_isspace.c \
			ft_memchr.c \
			ft_memmove.c \
			ft_strlcat.c \
			ft_strncmp.c \
			ft_tolower.c \
			ft_isalnum.c \
			ft_isdigit.c \
			ft_memcmp.c \
			ft_memset.c \
			ft_strlcpy.c \
			ft_strnstr.c \
			ft_toupper.c \
			ft_calloc.c \
			ft_strdup.c \
			ft_substr.c \
			ft_strjoin.c \
			ft_strtrim.c \
			ft_split.c \
			ft_power.c \
			ft_itoa.c \
			ft_strmapi.c \
			ft_striteri.c \
			ft_putchar_fd.c\
			ft_putstr_fd.c \
			ft_putendl_fd.c\
			ft_putnbr_fd.c\
			ft_lstnew.c \
			ft_lstadd_front.c \
			ft_swap.c \
			ft_lstsize.c \
			ft_lstlast.c \
			ft_lstadd_back.c \
			ft_lstdelone.c \
			ft_lstclear.c \
			ft_lstiter.c \
			ft_lstmap.c \
			ft_printf.c \
			ft_printf_utis.c \
			get_next_line_utils.c \
			get_next_line.c \
			ft_atoi_hex.c

MY_HEADERS = .

MY_OBJECTS = $(MY_SOURCES:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

%.o : %.c
	$(CC) -c $(CFLAGS)  $< -o $@ -I $(MY_HEADERS)
	
$(NAME): $(MY_OBJECTS)
	ar rc $(NAME) $(MY_OBJECTS)
	ranlib $(NAME)

clean:
	rm -f $(MY_OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

