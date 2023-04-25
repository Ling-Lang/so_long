/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkulka <jkulka@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 10:17:33 by jkulka            #+#    #+#             */
/*   Updated: 2023/04/25 13:42:10 by jkulka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_putline(mlx_image_t *img, int x1, int y1,int x2, int y2, int color)
{
	int temp_x = x1;
	int temp_y = y1;
	while (temp_x != x2 || temp_y != y2)
	{
		mlx_put_pixel(img, temp_x, temp_y, color);
		if(y1 < y2)
			temp_y += 1;
		if(y1 > y2)
			temp_y -= 1;
		if(x1 < x2)
			temp_x += 1;
		if(x1 > x2)
			temp_x -= 1;		
	}
}

void ft_print_square(mlx_image_t *img, t_rect rect,int color)
{
	ft_putline(img, rect.x1, rect.y1, rect.x2, rect.y1,color);
	ft_putline(img, rect.x2, rect.y1, rect.x2, rect.y2, color);
	ft_putline(img, rect.x2, rect.y2, rect.x1, rect.y2, color);
	ft_putline(img, rect.x1, rect.y2,rect.x1, rect.y1, color);
}
void ft_draw_rect(mlx_image_t *img, int posX, int posY, int width, int height, int color)
{
  int posX2;
  int posY2;

  posX2 = posX + width;
  posY2 = posY + height;
  ft_putline(img, posX, posY,posX2, posY, color);
  ft_putline(img, posX2, posY, posX2, posY2, color);
  ft_putline(img, posX2, posY2, posX, posY2, color);
  ft_putline(img, posX, posY2, posX, posY, color);
}

void ft_print_rect_fill(mlx_image_t *img, t_rect rect, int color_border, int color_fill)
{
	int temp_y = rect.y1 + 1;
	int temp_x = rect.x1 + 1;
	ft_print_square(img, rect, color_border);
	while (temp_y != rect.y2 && temp_x != rect.x2)
	{
		mlx_put_pixel(img, temp_x, temp_y, color_fill);
		if(temp_y != rect.y2)
			temp_y++;
		if(temp_y == rect.y2)
		{
			temp_x += 1;
			temp_y = rect.y1 + 1;
		}
	}
}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}
