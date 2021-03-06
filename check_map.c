/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nozakoya <nozakoya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 20:59:05 by nozakoya          #+#    #+#             */
/*   Updated: 2022/02/20 14:24:08 by nozakoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	check_map(char *file_name, t_fdf *data)
{
	int		width;
	int		fd;
	char	*line;
	int		w;

	fd = open(file_name, O_RDONLY);
	get_next_line(fd, &line);
	width = ft_word_count(line, ' ');
	free(line);
	while (get_next_line(fd, &line))
	{
		w = ft_word_count(line, ' ');
		free(line);
		if (w < width)
		{
			write(1, "ERROR\n", 6);
			exit (0);
		}
	}
	free(line);
	data->width = width;
	close (fd);
}
