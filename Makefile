MY_SOURCES = ft_atoi.c \
	     ft_isalpha.c \
	     ft_isprint.c \
	     ft_memcpy.c \
	     ft_strchr.c \
	     ft_strlen.c \
	     ft_strrchr.c \
	     ft_bzero.c \
	     ft_isascii.c \
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
	     ft_strdup.c

MY_HEADERS = .

MY_OBJECTS = $(MY_SOURCES:.c=.o)

NAME = libft.a

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

