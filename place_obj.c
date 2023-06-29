/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_obj.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkulka <jkulka@student.42heilbronn.de >    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 11:27:29 by jkulka            #+#    #+#             */
/*   Updated: 2023/06/29 17:21:10 by jkulka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
void	ft_put_player(t_data *data);

void ft_place_object(t_data *data,int obj_id)
{
	if(obj_id == 0)
		mlx_image_to_window(data->mlx, data->img->wall, data->map->x * BG_W, data->map->y * BG_H);
	else if(obj_id == 1)
		mlx_image_to_window(data->mlx, data->img->collectible, data->map->x * BG_W, data->map->y * BG_H);
	else if(obj_id == 2)
		mlx_image_to_window(data->mlx, data->img->exit, data->map->x * BG_W, data->map->y * BG_H);
}

void	ft_put_player(t_data *data)
/* puts the player in the starting position */
{
	data->p_x = data->map->x;
	data->p_y = data->map->y;
	mlx_image_to_window(data->mlx, data->img->player_up, data->p_x * BG_W, data->p_y * BG_H);
}

void	ft_create_map(t_data *data)
/* will fill the map with the corresponding images */
{
	data->map->x = 0;
	data->map->y = 0;
	while (data->map->y < (data->size_y / BG_H))
	{
		if (data->map->map[data->map->y][data->map->x] == 'P')
			ft_put_player(data);
		if (data->map->map[data->map->y][data->map->x] == '1')
			ft_place_object(data, 0);
		else if (data->map->map[data->map->y][data->map->x] == 'C')
			ft_place_object(data, 1);
		else if (data->map->map[data->map->y][data->map->x] == 'E')
			ft_place_object(data, 2);
		if (data->map->x < (data->size_x / BG_W))
			data->map->x++;
		else
		{
			data->map->y++;
			data->map->x = 0;
		}
	}
}