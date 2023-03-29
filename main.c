/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dylan <dylan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 12:08:11 by jkulka            #+#    #+#             */
/*   Updated: 2023/03/30 01:17:07 by dylan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#define WIDTH 256
#define HEIGHT 256

static mlx_image_t* img;

void	ft_hook2(void *data)
{
	mlx_t	*mlx;
	ft_printf("Playerpos.y:\t%i\nPlayerpos.x:\t%i\n", img->instances[0].y, img->instances[0].x);
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
	mlx = data;
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
	
}


int32_t	main(void)
{
	mlx_t* mlx = mlx_init(WIDTH, HEIGHT, "Tri is klein", true);
	t_rect rect;
	mlx_texture_t* hehe = mlx_load_png("./textures/hehe.png");
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
	mlx_loop_hook(mlx, ft_hook2, mlx);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}

