NAME = so_long
RM = rm -f
CC = gcc
CFLAGS = -Wall -Wextra -Werror
DEBUG = -Wall -Wextra -g
LIBINC = -I ./libft/src -I ./mlx
LIB		= libmlx.dylib libft.a

MAND = 	main.c \
		mlx_utils.c

MANDOBJ	= $(MAND:.c=.o)

$(NAME): $(MANDOBJ) | lft mlx
	cp libft/libft.a .
	cp mlx/libmlx.dylib .
	$(CC) $(MANDOBJ) $(LIBINC) $(CFLAGS) -o $(NAME) $(LIB)

lft:
	(cd libft && make && make clean)
mlx:
	(cd mlx && make)
%.o : %.c lft
	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@
	# $(CC) -c $(CFLAGS) $(INCFLAG) $< -o $@

debug: $(MANDOBJ)| lft mlx
	cp libft/libft.a .
	cp mlx/libmlx.dylib .
	$(CC) $(LIBINC) $(DEBUG) $(MANDOBJ) -o $(NAME) $(LIB)

clean:
	$(RM) $(MANDOBJ)

fclean: clean
	$(RM) $(NAME) $(BIN_NAME)
	$(RM) libft.a
	$(RM) libmlx.dylib
	cd mlx && make clean
	cd libft && make fclean

re: fclean all

all: $(NAME)

.PHONY: all clean fclean re mlx lft 