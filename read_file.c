/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nozakoya <nozakoya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 21:01:53 by nozakoya          #+#    #+#             */
/*   Updated: 2022/02/20 15:09:38 by nozakoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_width(char *file_name)
{
	int		fd;
	char	*line;
	int		width;

	fd = open(file_name, O_RDONLY);
	get_next_line(fd, &line);
	width = ft_word_count(line, ' ');
	free(line);
	close(fd);
	return (width);
}

int	get_height(char *file_name)
{
	int		fd;
	int		height;
	char	*line;

	height = 0;
	fd = open(file_name, O_RDONLY);
	while (get_next_line(fd, &line))
	{
		++height;
		free(line);
	}
	free(line);
	close(fd);
	return (height);
}

void	get_elements(t_fdf *data, char *line, int i)
{
	char	**arr;
	int		j;

	j = 0;
	arr = ft_split(line, ' ');
	while (j < data->width)
	{
		data->fdf_map[i][j] = ft_atoi(arr[j]);
		free(arr[j]);
		++j;
	}
	free(arr[j]);
	free(arr);
}

void	read_file(char *file_name, t_fdf *data)
{
	int		i;
	int		fd;
	char	*line;

	data->width = get_width(file_name);
	data->height = get_height(file_name);
	check_map(file_name, data);
	data->fdf_map = (int **)malloc(sizeof(int *) * (data->height));
	i = 0;
	while (i < data->height)
	{
		data->fdf_map[i] = (int *)malloc(sizeof(int) * (data->width));
		++i;
	}
	i = 0;
	fd = open(file_name, O_RDONLY);
	while (get_next_line(fd, &line))
	{
		get_elements(data, line, i);
		free(line);
		++i;
	}
	free(line);
	close(fd);
}
