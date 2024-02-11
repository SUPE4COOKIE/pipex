CFLAGS = -Wall -Wextra -Werror -MMD -MP
SRC = ft_printf.c print_char.c print_dec.c print_hex.c print_ptr.c print_string.c
OBJ = $(SRC:.c=.o)
NAME = libftprintf.a
OBJDEPS = $(OBJ:.o=.d)

all: $(NAME)

$(NAME): $(OBJ)
	ar -crs $(NAME) $(OBJ)

-include $(OBJDEPS)

%.o: %.c
	cc $(CFLAGS) -o $@ -c $<

clean:
	rm -f $(OBJ) $(OBJDEPS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re