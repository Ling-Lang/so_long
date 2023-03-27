/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkulka <jkulka@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 12:08:11 by jkulka            #+#    #+#             */
/*   Updated: 2023/03/27 09:48:51 by jkulka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


int main(){
	t_data mlx;
	int Width;
	int Height;
	t_rect rect;

	rect.x1 = 100;
	rect.y1 = rect.x1;
	rect.x2 = 300;
	rect.y2 = 200;
	
	Width = 740;
	Height = 480;
	
	mlx.mlx = mlx_init(Width, Height, "so_long", false);
	mlx.img = mlx_new_image(mlx.mlx, Width, Height);
	ft_print_rect_fill(mlx.img, rect, create_trgb(1, 244, 244, 0), create_trgb(1, 123, 21, 24));
	// mlx_loop_hook(mlx.mlx, key_hook, NULL);
	mlx_loop(mlx.mlx);
	return 0;
}