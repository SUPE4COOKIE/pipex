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
LIBFT= libft/libft.a
LIBFT_SRC = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
      ft_isdigit.c ft_isprint.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c \
      ft_memset.c ft_strchr.c ft_strdup.c ft_strlcat.c ft_strlcpy.c ft_strlen.c \
      ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_tolower.c ft_toupper.c ft_split.c \
      ft_itoa.c ft_putchar_fd.c ft_putendl_fd.c ft_putstr_fd.c ft_striteri.c ft_strjoin.c \
      ft_strjoin.c ft_strmapi.c ft_strtrim.c ft_substr.c ft_putnbr_fd.c
LIBFT_OBJ = $(LIBFT_SRC:.c=.o)
LIBFT_DEPS = $(LIBFT_OBJ:.o=.d)

all: $(NAME)

$(NAME): $(FT_PRINTF) $(GNL) $(LIBFT) $(OBJ)
	cc -o $(NAME) $(OBJ) $(FT_PRINTF) $(LIBFT) $(GNL)

%.o: %.c
	cc $(CFLAGS) -o $@ -c $<

$(FT_PRINTF): $(FT_PRINTF_SRC)
	$(MAKE) -C ft_printf/

$(GNL) : $(GNL_SRC)
	$(MAKE) -C get_next_line/

$(LIBFT) : $(LIBFT_SRC)
	$(MAKE) -C libft/

-include $(OBJDEPS)
-include $(FT_PRINTF_DEPS)
-include $(GNL_DEPS)
-include $(LIBFT_DEPS)

clean:
	rm -f $(OBJ) $(OBJDEPS)
	$(MAKE) -C ft_printf/ clean
	$(MAKE) -C get_next_line/ clean
	$(MAKE) -C libft/ clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C ft_printf/ fclean
	$(MAKE) -C get_next_line/ fclean
	$(MAKE) -C libft/ fclean

re: fclean all

.PHONY: all clean fclean re