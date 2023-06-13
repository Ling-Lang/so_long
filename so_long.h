/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dylan <dylan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 11:54:54 by jkulka            #+#    #+#             */
/*   Updated: 2023/06/13 10:11:13 by dylan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdlib.h>
#include <unistd.h>
#include "Libft/src/libft.h"
#include "MLX42/include/MLX42/MLX42.h"
#include <fcntl.h>

#define WIDTH 800
#define HEIGHT 640
#define BG_H	32
#define BG_W	32
# define W 13
# define A 0
# define S 1
# define D 2
# define UP -1
# define DOWN 1
# define LEFT -1
# define RIGHT 1

typedef struct s_img
{
	void	*player_up;
	void	*player_left;
	void	*player_right;
	void	*player_down;
	void	*background;
	void	*playfield;
}				t_img;

typedef struct s_player
{
	void	*player_up;
	void	*player_left;
	void	*player_right;
	void	*player_down;
}				t_player;
typedef struct s_map
{
	char	**map;
	void	*object;
	int		x;
	int		y;
	int		collectible;
}				t_map;
typedef struct s_data
{
	mlx_t*	mlx;
	int		size_x;
	int		size_y;
	int		p_x;
	int		p_y;
	int		counter;
	int		collected;
	t_map	*map;
	t_img	*img;
	t_player *player;
}				t_data;
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

int	ft_count(char *s, char c);
static void	ft_map_error(char *error_msg);
static void	ft_check_borders(t_data *data);
static void	ft_check_content(t_data *data);
static void	ft_input_error(int	argc);
void	ft_parse_input(t_data *data, char **argv, int argc);


void	ft_putline(mlx_image_t *img, int x1, int y1,int x2, int y2, int color);
void ft_print_square(mlx_image_t *img, t_rect rect,int color);
void ft_draw_rect(mlx_image_t *img, int posX, int posY, int width, int height, int color);
void ft_print_rect_fill(mlx_image_t *img, t_rect rect, int color_border, int color_fill);
int	create_trgb(int t, int r, int g, int b);
int move_player(int keycode, t_rect *rect);	
int ft_checkmap(int argc, char *argv[]);
void  ft_draw_map(char map);
void ft_validate_map(char *path);
void ft_loop(void *data);
void ft_background(t_data *data);
void ft_init(t_data *data);
void ft_keyhook(mlx_key_data_t keydata, t_data *data);
void	ft_put_background(t_data *data);

// void ft_draw_map_lines(char *map);


