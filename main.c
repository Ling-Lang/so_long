/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkulka <jkulka@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 13:33:52 by jkulka            #+#    #+#             */
/*   Updated: 2023/06/21 11:58:46 by jkulka           ###   ########.fr       */
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

static void	ft_window_size(t_data *data, char **argv)
/* will find the window size and check for some errors */
{
	int	fd;

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd("Error\nInvalid map_path/map\n", 2);
		exit(EXIT_FAILURE);
	}
	if (ft_strnstr(argv[1], ".ber", ft_strlen(argv[1])) == NULL)
	{
		printf("Error\nmap has to be .ber\n");
		exit(EXIT_FAILURE);
	}
	data->size_x = (ft_line_len(fd) * BG_W);
	data->size_y = (ft_count_lines(fd, data->size_x, BG_W) * BG_H);
}
int main (int argc, char *argv[])
{
    t_data data;
    t_map map;
    ft_putendl_fd("1", 1);
    ft_window_size(&data, argv);
    map.map = ft_calloc(data.size_y + 1, sizeof(char *));
    data.mlx = mlx_init(data.size_x, data.size_y, "so_long", false);
    ft_putendl_fd("2", 1);
    // if(ft_checkmap(argv, argc) == 1)
    // {
    //     mlx_terminate(data.mlx);
    //     ft_printf("Error\nNo valid map file given closing program...\n");
    //     return (EXIT_FAILURE);
    // }
    ft_init(&data, &map);
    ft_parse_input(&data, argv, argc);
    ft_render_next_frame(&data);
    mlx_loop(data.mlx);
    mlx_loop_hook(data.mlx, ft_loop, data.mlx);
    mlx_terminate(data.mlx);
    return (EXIT_SUCCESS);
}
