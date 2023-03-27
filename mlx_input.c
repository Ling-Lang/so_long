/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkulka <jkulka@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 10:32:20 by jkulka            #+#    #+#             */
/*   Updated: 2023/03/27 09:49:18 by jkulka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int move_player(int keycode, t_rect *rect)
{
	ft_printf("Key %i pressed\n", keycode);
	if (keycode == 13)
	{
		//change values of pointer rect
		rect->y1 -= 10;
		rect->y2 -= 10;
		
	}
	return (0);
}