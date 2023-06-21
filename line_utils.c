/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkulka <jkulka@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 11:52:35 by jkulka            #+#    #+#             */
/*   Updated: 2023/06/21 11:55:47 by jkulka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int ft_line_len(int fd)
{
	char buffer[1];
	int length;
	int bytes;

	buffer[0] = '\0';
	length = 0;
	bytes = 1;
	
	while(bytes == 1)
	{
		bytes = read(fd, buffer, 1);
		if(buffer[0] != '\n')
			length++;
		else
			break;
	}
	return (length);
}

static void	exit_error(void)
{
	ft_printf("Error\nwrong map dimensions\n");
	exit(EXIT_FAILURE);
}

int	ft_count_lines(int fd, int x, int img_w)
/* returns how many lines the file of fd contains */
{
	char	*line;
	int		linecount;
	int		i;

	i = 0;
	linecount = 1;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		if ((int)ft_strlen(line) < x / img_w
			|| (ft_strlen(line) == 1 && *line != '\n'))
		{
			free(line);
			exit_error();
		}
		else
		{
			free(line);
			linecount++;
		}
	}
	return (linecount);
}