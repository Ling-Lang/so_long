/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkulka <jkulka@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 11:54:54 by jkulka            #+#    #+#             */
/*   Updated: 2023/04/19 15:13:46 by jkulka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "Libft/src/libft.h"
#include "MLX42/include/MLX42/MLX42.h"
#include <fcntl.h>

#define WIDTH 800
#define HEIGHT 600

typedef struct	s_data {
	mlx_image_t	*img;
	mlx_t		*mlx;
}				t_data;

static mlx_image_t* img;
static float_t		speed;
static char			*sprite;
static mlx_texture_t* player;
typedef struct s_point {
	int x;
	int y;
} t_point;

typedef struct s_rect {
	int x1;
	int y1;
	int x2;
	int y2;
} t_rect;
void	ft_putline(mlx_image_t *img, int x1, int y1,int x2, int y2, int color);
void ft_print_square(mlx_image_t *img, t_rect rect,int color);
void ft_draw_rect(mlx_image_t *img, int posX, int posY, int width, int height, int color);
void ft_print_rect_fill(mlx_image_t *img, t_rect rect, int color_border, int color_fill);
int	create_trgb(int t, int r, int g, int b);
int move_player(int keycode, t_rect *rect);	
int ft_checkmap(int argc, char *argv[]);
void  ft_draw_map(char map);
void ft_validate_map(char *path);
// void ft_draw_map_lines(char *map);
