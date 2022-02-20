/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nozakoya <nozakoya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 20:59:36 by nozakoya          #+#    #+#             */
/*   Updated: 2022/02/20 15:28:26 by nozakoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float	ft_max(float x, float y)
{
	if (x > y)
		return (x);
	else
		return (y);
}

void	fdf_3d(float *x, float *y, int *z, t_fdf *data)
{
	*x = (*x - *y) * cos(data->angle);
	*y = (*x + *y) * sin(data->angle) - *z * data->z_coord;
}

void	fdf_zoom(t_coord *xyz, t_fdf *data)
{
	xyz->x *= data->zoom;
	xyz->x1 *= data->zoom;
	xyz->y *= data->zoom;
	xyz->y1 *= data->zoom;
}

void	fdf_shift(t_coord *xyz, t_fdf *data)
{
	xyz->x += data->shift_x;
	xyz->y += data->shift_y;
	xyz->x1 += data->shift_x;
	xyz->y1 += data->shift_y;
}

void	fdf_color(t_coord *xyz, t_fdf *data)
{
	xyz->z = data->fdf_map[(int)xyz->y][(int)xyz->x];
	xyz->z1 = data->fdf_map[(int)xyz->y1][(int)xyz->x1];
	if ((xyz->z || xyz->z1))
		data->color = 0xFF0000;
	else
		data->color = 0xFFFFFF;
}
