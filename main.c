// Written by Bruh

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "Libft/src/ft_printf.h"
#include "MLX42/include/MLX42/MLX42.h"
#include "so_long.h"

#define WIDTH 256
#define HEIGHT 256

static mlx_image_t* img;

// Exit the program as failure.
static void ft_error(void)
{
	fprintf(stderr, "%s", mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

// Print the window width and height.
static void ft_hook(void* data)
{
	mlx_t	*mlx;
	mlx = data;

	if (mlx_is_key_down(data, MLX_KEY_ESCAPE))
	{
		ft_printf("Closing Window...\n");
		mlx_close_window(mlx);
	}
		if (mlx_is_key_down(data, MLX_KEY_ESCAPE))
	{
		ft_printf("Closing Window...\n");
		mlx_close_window(mlx);
	}
	if (mlx_is_key_down(data, MLX_KEY_UP))
	{
		img->instances[0].y -= 5;
	}
	if (mlx_is_key_down(data, MLX_KEY_DOWN))
	{
		img->instances[0].y += 5;
	}
	if (mlx_is_key_down(data, MLX_KEY_LEFT))
		{
			img->instances[0].x -= 5;
		}
	if (mlx_is_key_down(data, MLX_KEY_RIGHT))
		{
			img->instances[0].x += 5;
		}
			if(img->instances[0].x < 0 && mlx_is_key_down(data, MLX_KEY_LEFT))
		{
			img->instances[0].x = 256;
		}
	if(img->instances[0].x > 256 && mlx_is_key_down(data, MLX_KEY_RIGHT))
		{
			img->instances[0].x = 0;
		}
	if(img->instances[0].y < 0 && mlx_is_key_down(data, MLX_KEY_UP))
		{
			img->instances[0].y = 256;
		}
	if(img->instances[0].y > 256 && mlx_is_key_down(data, MLX_KEY_DOWN))
		{
			img->instances[0].y = 0;
		}
	
}

int32_t	main(int argv, char *argc[])
{
  mlx_t* mlx = mlx_init(WIDTH, HEIGHT, "so_long", true);
  if(ft_checkmap(argv, argc) == 1)
  {
    mlx_terminate(mlx);
    ft_printf("No valid map file given closing program...\n");
    return (EXIT_SUCCESS);
  }

	t_rect rect;
	mlx_texture_t* hehe = mlx_load_png("./hehe.png");
	// int x = 0;
	rect.x1 = 10;
	rect.y1 = 10;

	rect.x2 = 20;
	rect.y2 = 10;
	/* Do stuff */

	// Create and display the image.
	img = mlx_texture_to_image(mlx,hehe);

	// ft_print_rect_fill(img, rect, create_trgb(1, 12, 31, 12), create_trgb(1, 123, 12, 31));
	mlx_image_to_window(mlx, img, 0, 0);
	mlx_loop_hook(mlx, ft_hook, mlx);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
