/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkulka <jkulka@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 10:34:27 by jkulka            #+#    #+#             */
/*   Updated: 2023/04/26 13:30:31 by jkulka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void ft_keyhook(mlx_key_data_t keydata, t_data *data)
{
    if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
    {
        data->p_y -= 25;
        mlx_draw_texture(data->img->player_up, data->player->player_up, data->p_x, data->p_y);
        // mlx_image_t *img = mlx_texture_to_image(data->mlx, data->img->player_up);
        // mlx_image_to_window(data->mlx, data->img->player_up, data->p_x, data->p_y);
        
        ft_printf("UP\n");
    }
        if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
    {
        data->p_x -= 25;
        mlx_image_to_window(data->mlx, data->img->player_left, data->p_x, data->p_y);
        ft_printf("LEFT\n");
    }
        if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
    {
        data->p_y += 25;
        mlx_image_to_window(data->mlx, data->img->player_down, data->p_x, data->p_y);
        ft_printf("DOWN\n");
    }
        if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
    {
        data->p_x += 25;
        mlx_image_to_window(data->mlx, data->img->player_right, data->p_x, data->p_y);
        ft_printf("RIGHT\n");
    }
    if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
    {
        mlx_close_window(data->mlx);
        ft_printf("Closing window...\n");
    }
}