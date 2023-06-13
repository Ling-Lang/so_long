/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dylan <dylan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 13:33:52 by jkulka            #+#    #+#             */
/*   Updated: 2023/06/13 10:14:12 by dylan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_render_next_frame(t_data *data)
/* checks for keyboard or mouse input */
{
    ft_put_background(data);
    mlx_key_hook(data->mlx, ft_keyhook, data);
	return (0);
}
int main (int argc, char *argv[])
{
    t_data data;
    
   data.mlx = mlx_init(WIDTH, HEIGHT, "so_long", false);
    // if(ft_checkmap(argv, argc) == 1)
    // {
    //     mlx_terminate(data.mlx);
    //     ft_printf("Error\nNo valid map file given closing program...\n");
    //     return (EXIT_FAILURE);
    // }
    
    ft_init(&data);
    ft_parse_input(&data, argv, argc);
    ft_render_next_frame(&data);
    
    // mlx_key_hook(mlx, ft_keyhook, NULL);
    mlx_loop(data.mlx);

    

    mlx_loop_hook(data.mlx, ft_loop, data.mlx);
    mlx_terminate(data.mlx);
    return (EXIT_SUCCESS);
}