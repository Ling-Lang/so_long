/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkulka <jkulka@student.42heilbronn.de >    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 10:34:27 by jkulka            #+#    #+#             */
/*   Updated: 2023/06/29 20:53:31 by jkulka           ###   ########.fr       */
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
    mlx_image_to_window(data->mlx, data->img->background, data->p_x * BG_W, data->p_y * BG_H);
	if (pos == 'y' && data->map->map[data->p_y + 1 * dir][data->p_x] != '1'
		&& (data->map->map[data->p_y + 1 * dir][data->p_x] != 'E'
		|| data->collected == data->map->collectible))
		data->p_y = data->p_y + 1 * dir;
	else if (pos == 'x' && data->map->map[data->p_y][data->p_x + 1 * dir] != '1'
		&& (data->map->map[data->p_y][data->p_x + 1 * dir] != 'E'
		|| data->collected == data->map->collectible))
		data->p_x = data->p_x + 1 * dir;
	else if (pos == 'y' && data->map->map[data->p_y + 1 * dir][data->p_x] == 'E'
		&& data->collected != data->map->collectible)
		ft_printf("Collect all collectibles before leaving\n");
	else if (pos == 'x' && data->map->map[data->p_y][data->p_x + 1 * dir] == 'E'
		&& data->collected != data->map->collectible)
		ft_printf("Collect all collectibles before leaving\n");
	ft_move_player(data, pos, dir);
	if (data->map->map[data->p_y][data->p_x] == 'C')
		ft_collect_cow(data, pos, dir);
	// mlx_do_sync(data->mlx);
	printf("You moved %d times.\n", ++data->counter);
}

// void ft_keyhook(mlx_key_data_t keydata, t_data *data)
// {
//     if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
//     {
//         data->p_y -= 25;
//         // mlx_image_t *img = mlx_texture_to_image(data->mlx, data->img->player_up);
//         mlx_image_to_window(data->mlx, data->img->player_up, data->p_x, data->p_y);
//         ft_printf("UP\n");
//     }
//         if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
//     {
//         data->p_x -= 25;
//         mlx_image_to_window(data->mlx, data->img->player_left, data->p_x, data->p_y);
//         ft_printf("LEFT\n");
//     }
//         if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
//     {
//         data->p_y += 25;
//         mlx_image_to_window(data->mlx, data->img->player_down, data->p_x, data->p_y);
//         ft_printf("DOWN\n");
//     }
//         if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
//     {
//         data->p_x += 25;
//         mlx_image_to_window(data->mlx, data->img->player_right, data->p_x, data->p_y);
//         ft_printf("RIGHT\n");
//     }
//     if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
//     {
//         mlx_close_window(data->mlx);
//         ft_printf("Closing window...\n");
//     }
// }