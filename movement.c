/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkulka <jkulka@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 10:34:27 by jkulka            #+#    #+#             */
/*   Updated: 2023/06/30 12:36:10 by jkulka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void ft_keyhook(mlx_key_data_t keydata, t_data *data)
{
    if(keydata.key == MLX_KEY_ESCAPE)
        ft_exit(data);
    else if(keydata.key == MLX_KEY_W)
        ft_move(data, 'y', UP);
    else if(keydata.key == MLX_KEY_A)
        ft_move(data, 'x', LEFT);
    else if(keydata.key == MLX_KEY_S)
        ft_move(data, 'y', DOWN);
    else if(keydata.key == MLX_KEY_D)
        ft_move(data, 'x', RIGHT);
    if(data->map->map[data->p_y][data->p_x] == 'E')
        ft_success(data);
}

static void ft_move_player(t_data *data, char position, int direction)
{
    if(position == 'y' && direction == UP)
        mlx_image_to_window(data->mlx, data->player->player_up, data->p_x * BG_W, data->p_y * BG_H);
    if(position == 'x' && direction == LEFT)
        mlx_image_to_window(data->mlx, data->player->player_left, data->p_x * BG_W, data->p_y * BG_H);
    if(position == 'y' && direction == DOWN)
        mlx_image_to_window(data->mlx, data->player->player_down, data->p_x * BG_W, data->p_y * BG_H);
    if(position == 'x' && direction == RIGHT)
        mlx_image_to_window(data->mlx, data->player->player_right, data->p_x * BG_W, data->p_y * BG_H);
}

static void ft_collect_cow(t_data *data, char pos, int dir)
{
    data->collected++;
    data->map->map[data->p_y][data->p_x] = '0';
    mlx_image_to_window(data->mlx, data->img->background, data->p_x * BG_W, data->p_y * BG_H);
    ft_move_player(data, pos, dir);
}

void	ft_move(t_data *data, char pos, int dir)
/* will check if a move is valid and move the player if valid */
{
    ft_printf("%c", data->map->map[data->p_y][data->p_x + 1 * dir]);
    mlx_image_to_window(data->mlx, data->img->background, data->p_x * BG_W, data->p_y * BG_H);
	if (pos == 'y' && data->map->map[data->p_y + 1 * dir][data->p_x] != '1'
		&& (data->map->map[data->p_y + 1 * dir][data->p_x] != 'E'
		|| data->collected == data->map->collectible))
        {
            write(1, "c", 1);
		data->p_y = data->p_y + 1 * dir;
        }
	else if (pos == 'x' && data->map->map[data->p_y][data->p_x + 1 * dir] != '1'
		&& (data->map->map[data->p_y][data->p_x + 1 * dir] != 'E'
		|| data->collected == data->map->collectible))
        {
            write(1, "c", 1);
            data->p_x = data->p_x + 1 * dir;
        }
	else if (pos == 'y' && data->map->map[data->p_y + 1 * dir][data->p_x] == 'E'
		&& data->collected != data->map->collectible)
		ft_printf("Collect all collectibles before leaving\n");
	else if (pos == 'x' && data->map->map[data->p_y][data->p_x + 1 * dir] == 'E'
		&& data->collected != data->map->collectible)
		ft_printf("Collect all collectibles before leaving\n");
	ft_move_player(data, pos, dir);
	if (data->map->map[data->p_y][data->p_x] == 'C')
		ft_collect_cow(data, pos, dir);
	printf("You moved %d times.\n", ++data->counter);
}