/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkulka <jkulka@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 13:31:52 by jkulka            #+#    #+#             */
/*   Updated: 2023/04/19 15:20:54 by jkulka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "Libft/src/ft_printf.h"
#include "MLX42/include/MLX42/MLX42.h"
#include "so_long.h"

// Exit the program as failure.
static void ft_error(void)
{
	fprintf(stderr, "%s", mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}
static void ft_move_player(void *data)
{
	mlx_t	*mlx;
	mlx = data;
	if (mlx_is_key_down(data, MLX_KEY_UP))
	{
		img->instances[0].y -= speed;
		sprite = "./textures/Ship_Forward.png";
		player = mlx_load_png(sprite);

		
		

	}
	if (mlx_is_key_down(data, MLX_KEY_DOWN))
	{
		img->instances[0].y += speed;
  		sprite = "./textures/Ship_Down.png";
		player = mlx_load_png(sprite);
		

		
	}
	if (mlx_is_key_down(data, MLX_KEY_LEFT))
		{
			img->instances[0].x -= speed;
		}
	if (mlx_is_key_down(data, MLX_KEY_RIGHT))
		{
			img->instances[0].x += speed;
		}
}
static void ft_wall_collission(void *data)
{
	mlx_t	*mlx;
	mlx = data;
	if(img->instances[0].x < 0 && mlx_is_key_down(data, MLX_KEY_LEFT))
	{
		img->instances[0].x = 0;
		speed = 0;
	}
	else
	if(img->instances[0].x > mlx->width - img->width && mlx_is_key_down(data, MLX_KEY_RIGHT))
	{
		img->instances[0].x = mlx->width - img->width;
		speed = 0;
	}
	else
	if(img->instances[0].y < 0 && mlx_is_key_down(data, MLX_KEY_UP))
	{
		img->instances[0].y = 0;
		speed = 0;
	}
	else
	if(img->instances[0].y > mlx->height - img->height && mlx_is_key_down(data, MLX_KEY_DOWN))
	{
		img->instances[0].y = mlx->height - img->height;
		speed = 0;
	}
	else
	speed = 2.5;
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
	ft_move_player(data);
	ft_wall_collission(data);

	
	

	
}

int32_t	main(int argv, char *argc[])
{
  mlx_t* mlx = mlx_init(WIDTH, HEIGHT, "so_long", false);
  if(ft_checkmap(argv, argc) == 1)
  {
    mlx_terminate(mlx);
    ft_printf("No valid map file given closing program...\n");
    return (EXIT_SUCCESS);
  }
  sprite = "./textures/Ship_Forward.png";
  speed = 2.5;
	player = mlx_load_png(sprite);
	
	t_rect rect;
	// int x = 0;
	
	rect.x1 = 10;
	rect.y1 = 10;

	rect.x2 = 20;
	rect.y2 = 10;
	/* Do stuff */

	// Create and display the image.
	img = mlx_texture_to_image(mlx,player);
	// img = mlx_new_image(mlx, 123 ,123);
	// ft_draw_rect(img, 0, 0, 10, 20, create_trgb(1, 123, 212, 123));
	
	// mlx_put_pixel(img, 12, 12, create_trgb(1, 23, 231, 12));
	mlx_image_to_window(mlx, img, 0, 0);
	mlx_loop_hook(mlx, ft_hook, mlx);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
