/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _bonus.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nozakoya <nozakoya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 20:58:26 by nozakoya          #+#    #+#             */
/*   Updated: 2022/02/20 15:52:31 by nozakoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_zoomik(int key, t_fdf *data)
{
	if (key == 69)
	{
		if (data->zoom <= 150)
			data->zoom += 1;
	}
	if (key == 78)
	{
		if (data->zoom > 0)
			data->zoom -= 1;
	}
}

int	key_hook(int key, t_fdf *data)
{
	if (key == 124)
		data->angle += 0.05;
	if (key == 123)
		data->angle -= 0.05;
	if (key == 6)
		data->z_coord += 1;
	if (key == 7)
		data->z_coord -= 1;
	if (key == 13)
		data->shift_y -= 10;
	if (key == 1)
		data->shift_y += 10;
	if (key == 2)
		data->shift_x += 10;
	if (key == 0)
		data->shift_x -= 10;
	if (key == 53)
		exit(0);
	fdf_zoomik(key, data);
	return (0);
}
