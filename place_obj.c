/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_obj.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkulka <jkulka@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 11:27:29 by jkulka            #+#    #+#             */
/*   Updated: 2023/06/28 11:54:21 by jkulka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void ft_place_object(t_data *data, int x, int y)
{
	mlx_image_to_window(data->mlx, data->img->player_right, x * BG_W, y * BG_H);
}