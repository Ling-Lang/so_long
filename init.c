/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkulka <jkulka@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 13:59:06 by jkulka            #+#    #+#             */
/*   Updated: 2023/04/25 14:40:19 by jkulka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void ft_init(t_data *data)
{
    data->img = malloc(sizeof(mlx_image_t));
    char *path = "textures/Ship_Forward.png";
    data->img->player_up = mlx_load_png(path);
    path = "textures/Ship_Left.png";
    data->img->player_left = mlx_load_png(path);
    path = "textures/Ship_Right.png";
    data->img->player_right = mlx_load_png(path);
    path = "textures/Ship_Down.png";
    data->img->player_down = mlx_load_png(path);
    data->img->background = mlx_load_png("textures/BG.png");
}