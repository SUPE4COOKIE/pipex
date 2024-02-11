CFLAGS = -Wall -Wextra -Werror -MMD -MP
SRC = get_next_line.c get_next_line_utils.c
OBJ = $(SRC:.c=.o)
NAME = gnl.a
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