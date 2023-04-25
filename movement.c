/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkulka <jkulka@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 10:34:27 by jkulka            #+#    #+#             */
/*   Updated: 2023/04/25 14:53:51 by jkulka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void ft_keyhook(int keycode, t_data *data)
{
    if (keycode == MLX_KEY_W)
    {
        // mlx_image_t *img = mlx_texture_to_image(data->mlx, data->img->player_up);
        // mlx_image_to_window(data->mlx, img, 200, 0);
        ft_printf("W pressed\n");
    }
    if (keycode == MLX_KEY_A)
    {
        // mlx_image_t *img = mlx_texture_to_image(data->mlx, data->img->player_left);
        // mlx_image_to_window(data->mlx, img, 200, 0);
    }
    if (keycode == MLX_KEY_S)
    {
        // mlx_image_t *img = mlx_texture_to_image(data->mlx, data->img->player_down);
        // mlx_image_to_window(data->mlx, img, 200, 0);
    }
    if (keycode == MLX_KEY_D)
    {
        // mlx_image_t *img = mlx_texture_to_image(data->mlx, data->img->player_right);
        // mlx_image_to_window(data->mlx, img, 200, 0);
    }
}

