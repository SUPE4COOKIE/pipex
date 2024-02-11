CFLAGS = -Wall -Wextra -Werror -MMD -MP
NAME = pipex
SRC = main.c
OBJ = $(SRC:.c=.o)
OBJDEPS = $(OBJ:.o=.d)
GNL = get_next_line/gnl.a
GNL_SRC = get_next_line/get_next_line.c get_next_line/get_next_line_utils.c
GNL_OBJ = $(GNL_SRC:.c=.o)
GNL_DEPS = $(GNL_OBJ:.o=.d)
FT_PRINTF = ft_printf/libftprintf.a
FT_PRINTF_SRC = ft_printf/ft_printf.c ft_printf/print_char.c ft_printf/print_dec.c \
				ft_printf/print_hex.c ft_printf/print_ptr.c ft_printf/print_string.c
FT_PRINTF_OBJ = $(FT_PRINTF_SRC:.c=.o)
FT_PRINTF_DEPS = $(FT_PRINTF_OBJ:.o=.d)

all: $(NAME)

$(NAME): $(FT_PRINTF) $(GNL) $(OBJ)
	cc -o $(NAME) $(OBJ) $(FT_PRINTF) $(GNL)

%.o: %.c
	cc $(CFLAGS) -o $@ -c $<

$(FT_PRINTF): $(FT_PRINTF_SRC)
	$(MAKE) -C ft_printf/

$(GNL) : $(GNL_SRC)
	$(MAKE) -C get_next_line/

-include $(OBJDEPS)
-include $(FT_PRINTF_DEPS)
-include $(GNL_DEPS)

clean:
	rm -f $(OBJ) $(OBJDEPS)
	$(MAKE) -C ft_printf/ clean
	$(MAKE) -C get_next_line/ clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C ft_printf/ fclean
	$(MAKE) -C get_next_line/ fclean

re: fclean all

.PHONY: all clean fclean re