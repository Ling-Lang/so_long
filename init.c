/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkulka <jkulka@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 13:59:06 by jkulka            #+#    #+#             */
/*   Updated: 2023/04/26 13:28:39 by jkulka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void ft_init(t_data *data)
{
    data->img = malloc(sizeof(mlx_image_t));
    char *path = "textures/Ship_Forward.png";
    data->player->player_up = mlx_load_png(path);
    data->img->player_up = mlx_texture_to_image(data->mlx, data->player->player_up);
    path = "textures/Ship_Left.png";
    data->player->player_left = mlx_load_png(path);
    data->img->player_left = mlx_texture_to_image(data->mlx, data->player->player_left);
    path = "textures/Ship_Right.png";
    data->player->player_right = mlx_load_png(path);
    data->img->player_right = mlx_texture_to_image(data->mlx, data->player->player_right);
    path = "textures/Ship_Down.png";
    data->player->player_down = mlx_load_png(path);
    data->img->player_down = mlx_texture_to_image(data->mlx, data->player->player_down);
    data->img->background = mlx_load_png("textures/Background_Tile.png");
}

void	ft_put_background(t_data *data)
/* will fill the whole screen with background */
{
	int		y;
	int		x;

    mlx_image_t *img = mlx_texture_to_image(data->mlx, data->img->background);
    // mlx_set_instance_depth(&img->instances[0], 1);
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			mlx_image_to_window(data->mlx, img, x, y);
    mlx_set_instance_depth(&img->instances[0], 1);
            
			x += BG_W;
		}
		y += BG_H;
	}
}