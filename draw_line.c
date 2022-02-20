/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nozakoya <nozakoya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 20:59:19 by nozakoya          #+#    #+#             */
/*   Updated: 2022/02/20 15:33:29 by nozakoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_line(t_coord xyz, t_fdf *data)
{
	float	dx;
	float	dy;
	float	max;

	fdf_color(&xyz, data);
	fdf_zoom(&xyz, data);
	fdf_3d(&xyz.x, &xyz.y, &xyz.z, data);
	fdf_3d(&xyz.x1, &xyz.y1, &xyz.z1, data);
	fdf_shift(&xyz, data);
	dx = xyz.x1 - xyz.x;
	dy = xyz.y1 - xyz.y;
	max = ft_max(fabs(dx), fabs(dy));
	dx /= max;
	dy /= max;
	while (((int)(xyz.x1 - xyz.x) || (int)(xyz.y1 - xyz.y)))
	{
		if ((xyz.y < WIN_H) && (xyz.x < WIN_L))
		{
			if (xyz.x >= 0 && xyz.y >= 0)
				my_mlx_pixel_put(&data->img, xyz.x, xyz.y, data->color);
		}
		xyz.x += dx;
		xyz.y += dy;
	}
}

void	draw(t_fdf *data)
{
	t_coord		xyz;

	xyz.y = 0;
	while ((xyz.y < data->height))
	{
		xyz.x = 0;
		while (xyz.x < data->width)
		{
			if (xyz.x < data->width - 1)
			{
				xyz.x1 = xyz.x + 1;
				xyz.y1 = xyz.y;
				draw_line(xyz, data);
			}
			if (xyz.y < data->height - 1)
			{
				xyz.x1 = xyz.x;
				xyz.y1 = xyz.y + 1;
				draw_line(xyz, data);
			}
			xyz.x++;
		}
		xyz.y++;
	}
}
