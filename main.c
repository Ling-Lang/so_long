/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkulka <jkulka@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 13:33:52 by jkulka            #+#    #+#             */
/*   Updated: 2023/04/26 10:51:10 by jkulka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_render_next_frame(t_data *data)
/* checks for keyboard or mouse input */
{
    ft_background(data);
    mlx_key_hook(data->mlx, ft_keyhook, data);
	return (0);
}
int main (int argv, char *argc[])
{
    t_data data;
    
   data.mlx = mlx_init(WIDTH, HEIGHT, "so_long", false);
    if(ft_checkmap(argv, argc) == 1)
    {
        mlx_terminate(data.mlx);
        ft_printf("Error\nNo valid map file given closing program...\n");
        return (EXIT_FAILURE);
    }
    mlx_image_t *img = mlx_new_image(data.mlx, WIDTH, HEIGHT);
    mlx_image_to_window(data.mlx, img, 200, 0);
    ft_init(&data);
    img = mlx_texture_to_image(data.mlx, data.img->player_up);
    mlx_image_to_window(data.mlx, img, 200, 0);
    ft_render_next_frame(&data);
    // mlx_key_hook(mlx, ft_keyhook, NULL);
    mlx_loop(data.mlx);

    

    mlx_loop_hook(data.mlx, ft_loop, data.mlx);
    mlx_terminate(data.mlx);
    return (EXIT_SUCCESS);
}