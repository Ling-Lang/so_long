/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkulka <jkulka@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 12:08:11 by jkulka            #+#    #+#             */
/*   Updated: 2023/03/24 13:20:31 by jkulka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(void)
{
	t_data	data;
	
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, 1920, 1080, "Hello world!");
	data.img = mlx_new_image(data.mlx, 1920, 1080);
	data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel, &data.line_length, &data.endian);
	mlx_loop_hook(data.mlx, render_next_frame, &data);
	mlx_loop(data.mlx);
}

int render_next_frame(t_data *data)
{
	t_rect rect;

	rect.x1 = 100;
	rect.y1 = 100;
	rect.x2 = 200;
	rect.y2 = 200;

	mlx_key_hook(data->win, key_hook, data);
	mlx_clear_window(data->mlx, data->win);
	ft_print_rect_fill(data, rect, create_trgb(1, 12,133,243), 0x0000FF00);
	ft_print_rect_fill(data, rect, create_trgb(1, 12,133,243), 0x0000FFFF);

	
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	return (0);
}