CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a

SRC =	ft_printf.c \
		ft_printf_putnbr.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $@ $^

%.o: %.c libftprintf.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all