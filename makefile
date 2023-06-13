NAME = so_long
RM = rm -f
CC = gcc
CFLAGS = -Wall -Wextra -Werror -ldl -lglfw -pthread -lm
DEBUG = -Wall -Wextra -g -Iinclude 
LIBINC = -I ./Libft/src -I ./MLX42/include
LIB		=  MLX42/build/libmlx42.a Libft/libft.a 
LIBMLX  = MLX42

MAND = 	main.c \
		mlx_utils.c \
		mlx_input.c \
		check_map.c \
		movement.c	\
		init.c 		\
		hooks.c		\
		so_long_utils.c \
		parse_map.c \

MANDOBJ	= $(MAND:.c=.o)

$(NAME): $(MANDOBJ) | lft mlx
	$(CC) $(MANDOBJ) $(LIBINC) $(CFLAGS) -o $(NAME) $(LIB)

lft:
	(cd Libft && make && make clean)

mlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

%.o : %.c lft
	$(CC) -c $< -o $@

debug: $(MANDOBJ)| lft mlx
	$(CC) $(LIBINC) $(DEBUG) $(MANDOBJ) -o $(NAME) $(LIB)

clean:
	$(RM) $(MANDOBJ)

fclean: clean
	$(RM) $(NAME) $(BIN_NAME)
	$(RM) -f MLX42/build/libmlx42.a
	cd Libft && make fclean

re: fclean all

all: $(NAME)

.PHONY: all clean fclean re mlx lft 
