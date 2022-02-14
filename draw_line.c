#include "fdf.h"

float	ft_max(float x, float y)
{
	if (x > y)
		return (x);
	else
		return (y);
}

void    fdf_3d(float *x, float *y, int z, fdf *data)
{

    *x = (*x - *y) * cos(data->angle);
    *y = (*x + *y) * sin(data->angle) - z * data->z_coord;
}


void   fdf_zoom(float *x, float *y, float *x1, float *y1, fdf *data)
{
    *x *= data->zoom;
    *x1 *= data->zoom;  
    *y *= data->zoom;  
    *y1 *= data->zoom; 
}

void fdf_shift(float *x, float *y, float *x1, float *y1, fdf *data)
{
	*x += data->shift_x;
    *y += data->shift_y;
    *x1 += data->shift_x;
    *y1 += data->shift_y;
}

void    draw_line(float x, float y, float x1, float y1, fdf *data)
{
    float	dx;
	float	dy;
	float	max;
	int		z;
	int		z1;

	z = data->fdf_map[(int)y][(int)x];
	z1 = data->fdf_map[(int)y1][(int)x1];
    if (z || z1)
        data->color = 0xFF0000;
    else
        data->color = 0xFFFFFF;

	fdf_zoom(&x, &y, &x1, &y1, data);
	fdf_3d(&x, &y, z, data);
	fdf_3d(&x1, &y1, z1, data);
	fdf_shift(&x, &y, &x1, &y1, data);
	dx = x1 - x;
	dy = y1 - y;
	max = ft_max(fabs(dx), fabs(dy));
	dx /= max;
	dy /= max;
	while (((int)(x1 - x) || (int)(y1 - y)))
	{
		if ((y < WIN_H) && (x < WIN_L))
		{
			if (x >= 0 && y >= 0)
				my_mlx_pixel_put(&data->img, x, y, data->color);
		}
		x += dx;
		y += dy;
	}
}

void    draw(fdf *data)
{
 	int	x;
	int	y;
    
	y = 0;
	while ((y < data->height))
	{
		x = 0;
		while (x < data->width)
		{
			if (x < data->width - 1)
				draw_line(x, y, x + 1, y, data);
			if (y < data->height - 1)
				draw_line(x, y, x, y + 1, data);
			x++;
		}
		y++;
	}
}

