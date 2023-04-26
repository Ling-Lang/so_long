/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkulka <jkulka@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 10:34:27 by jkulka            #+#    #+#             */
/*   Updated: 2023/04/26 10:47:30 by jkulka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void ft_keyhook(mlx_key_data_t keydata, t_data *data)
{
    if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
    {
        data->p_x -= 10;
        mlx_image_t *img = mlx_texture_to_image(data->mlx, data->img->player_up);
        mlx_image_to_window(data->mlx, img, data->p_x, data->p_y);
        ft_printf("UP");
    }
        if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
    {
        mlx_image_t *img = mlx_texture_to_image(data->mlx, data->img->player_left);
        mlx_image_to_window(data->mlx, img, data->p_x, data->p_y);
        ft_printf("left");
    }
        if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
    {
        data->p_x += 10;
        mlx_image_t *img = mlx_texture_to_image(data->mlx, data->img->player_down);
        mlx_image_to_window(data->mlx, img, data->p_x, data->p_y);
        ft_printf("DOWN");
    }
        if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
    {
        mlx_image_t *img = mlx_texture_to_image(data->mlx, data->img->player_right);
        mlx_image_to_window(data->mlx, img, data->p_x, data->p_y);
        ft_printf("RIGHT");
    }
    if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
    {
        mlx_close_window(data->mlx);
        ft_printf("Closing window...\n");
    }
}