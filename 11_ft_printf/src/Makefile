MY_SOURCES = ft_printf.c \
			ft_printf_utis.c

MY_HEADERS = .

MY_OBJECTS = $(MY_SOURCES:.c=.o)

NAME = libftprintf.a

CC = cc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

LIBFT_DIR = ./libft/

all: $(NAME)

%.o : %.c
	$(CC) -c $(CFLAGS)  $< -o $@ -I $(MY_HEADERS)
	
$(NAME): $(LIBFT_DIR)libft.a $(MY_OBJECTS)
	cp $(LIBFT_DIR)libft.a ./$(NAME)
	ar rc $(NAME) $(MY_OBJECTS)
	ranlib $(NAME)

$(LIBFT_DIR)libft.a: 
	make all -C $(LIBFT_DIR)

clean:
	$(RM) $(MY_OBJECTS)
	make clean -C $(LIBFT_DIR)

fclean: clean
	$(RM)  $(NAME)
	make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re

