/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkulka <jkulka@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 11:54:54 by jkulka            #+#    #+#             */
/*   Updated: 2023/03/23 11:57:41 by jkulka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "libft/src/libft.h"
#include "mlx/mlx.h"

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
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
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	ft_putline(t_data *img, int x1, int y1,int x2, int y2, int color);
void ft_print_square(t_data *img, t_rect rect,int color);
int	create_trgb(int t, int r, int g, int b);
