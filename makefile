NAME = so_long
RM = rm -f
CC = gcc
CFLAGS = -Wall -Wextra -Werror -Iinclude -lglfw
DEBUG = -Wall -Wextra -g -ldl -lglfw -pthread -lm
LIBINC = -I ./libft/src -I ./mlx
LIB		= MLX42/build/libmlx42.a libft/libft.a
LIBMLX  = MLX42

MAND = 	main.c \
		mlx_utils.c \
		mlx_input.c 

MANDOBJ	= $(MAND:.c=.o)

$(NAME): $(MANDOBJ) | lft mlx
	$(CC) $(MANDOBJ) $(LIBINC) $(CFLAGS) -o $(NAME) $(LIB)

lft:
	(cd libft && make && make clean)

mlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

%.o : %.c lft
	$(CC) -Wall -Wextra -Werror -c $< -o $@

debug: $(MANDOBJ)| lft mlx
	$(CC) $(LIBINC) $(DEBUG) $(MANDOBJ) -o $(NAME) $(LIB)

clean:
	$(RM) $(MANDOBJ)

fclean: clean
	$(RM) $(NAME) $(BIN_NAME)
	$(RM) -f MLX42/build/libmlx42.a
	cd libft && make fclean

re: fclean all

all: $(NAME)

.PHONY: all clean fclean re mlx lft 