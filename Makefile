CFLAGS = -Wall -Wextra -Werror -MMD -MP -g3
NAME = pipex
SRC = src/main.c src/ft_split_args.c
OBJ = $(SRC:.c=.o)
OBJDEPS = $(OBJ:.o=.d)
FT_PRINTF = ft_printf/libftprintf.a
FT_PRINTF_SRC = ft_printf/ft_printf.c ft_printf/print_char.c ft_printf/print_dec.c \
				ft_printf/print_hex.c ft_printf/print_ptr.c ft_printf/print_string.c
FT_PRINTF_OBJ = $(FT_PRINTF_SRC:.c=.o)
FT_PRINTF_DEPS = $(FT_PRINTF_OBJ:.o=.d)
LIBFT= libft/libft.a
LIBFT_SRC = libft/ft_atoi.c libft/ft_bzero.c libft/ft_calloc.c libft/ft_isalnum.c libft/ft_isalpha.c libft/ft_isascii.c \
	libft/ft_isdigit.c libft/ft_isprint.c libft/ft_memchr.c libft/ft_memcmp.c libft/ft_memcpy.c libft/ft_memmove.c \
	libft/ft_memset.c libft/ft_strchr.c libft/ft_strdup.c libft/ft_strlcat.c libft/ft_strlcpy.c libft/ft_strlen.c \
	libft/ft_strncmp.c libft/ft_strnstr.c libft/ft_strrchr.c libft/ft_tolower.c libft/ft_toupper.c libft/ft_split.c \
	libft/ft_itoa.c libft/ft_putchar_fd.c libft/ft_putendl_fd.c libft/ft_putstr_fd.c libft/ft_striteri.c libft/ft_strjoin.c \
	libft/ft_strjoin.c libft/ft_strmapi.c libft/ft_strtrim.c libft/ft_substr.c libft/ft_putnbr_fd.c
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