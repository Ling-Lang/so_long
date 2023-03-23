/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkulka <jkulka@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 12:08:11 by jkulka            #+#    #+#             */
/*   Updated: 2023/03/23 12:09:32 by jkulka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	t_point start;
	t_point end;
	t_rect rect;
	
	start.x = 100;
	start.y = 100;
	end.x = 200;
	end.y = 600;
	
	rect.x1 = 100;
	rect.x2 = 200;
	rect.y1 = 100;
	rect.y2 = 200;
	

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	// ft_putline(&img, start.x, start.y,end.x,end.y,0x00FF0000);
	ft_print_square(&img, rect, create_trgb(1, 145, 210,255));
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}