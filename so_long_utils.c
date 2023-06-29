/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkulka <jkulka@student.42heilbronn.de >    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 10:06:16 by dylan             #+#    #+#             */
/*   Updated: 2023/06/29 20:54:03 by jkulka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_count(char *s, char c)
{
	int	i;
	int	x;

	i = 0;
	x = 0;
	if (!s)
		return (-1);
	while (s && s[i])
	{
		if (s[i++] == c)
			x++;
	}
	return (x);
}

void ft_exit(t_data *data)
{
	mlx_close_window(data->mlx);
	mlx_terminate(data->mlx);
	exit (EXIT_SUCCESS);
}

void	ft_success(t_data *data)
{
	ft_printf("Congrats you found all the space-cows and brought them safely to the exit.\n");
	ft_printf("You won!\n");
	ft_printf("You made it in %d moves \n", data->counter);
	exit(EXIT_SUCCESS);
}