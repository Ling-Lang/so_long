/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkulka <jkulka@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 10:17:33 by jkulka            #+#    #+#             */
/*   Updated: 2023/03/23 12:02:08 by jkulka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

// void	ft_putline(t_data *img, t_point start,t_point end, int color)
// {
// 	int temp_x = start.x;
// 	int temp_y = start.y;
// 	while (temp_x != end.x)
// 	{
// 		my_mlx_pixel_put(img, temp_x, temp_y, color);
// 		if(start.y < end.y)
// 			temp_y += 1;
// 		if(start.y > end.y)
// 			temp_y -= 1;
// 		if(start.x < end.x)
// 			temp_x += 1;
// 		if(start.x > end.x)
// 			temp_x -= 1;		
// 	}
// }

void	ft_putline(t_data *img, int x1, int y1,int x2, int y2, int color)
{
	int temp_x = x1;
	int temp_y = y1;
	while (temp_x != x2)
	{
		my_mlx_pixel_put(img, temp_x, temp_y, color);
		if(y1 < x2)
			temp_y += 1;
		if(y1 > y2)
			temp_y -= 1;
		if(x1 < x2)
			temp_x += 1;
		if(x1 > x2)
			temp_x -= 1;		
	}
}


void ft_print_square(t_data *img, t_rect rect,int color)
{
	ft_putline(img, rect.x1, rect.y1, rect.x2, rect.y1,color);
	ft_putline(img, rect.x2, rect.y1, rect.x2, rect.y2, color);
	ft_putline(img, rect.x2, rect.y2, rect.x1, rect.y2, color);
	ft_putline(img, rect.x1, rect.y2,rect.x1, rect.y1, color);
	
}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}
