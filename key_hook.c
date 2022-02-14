#include "fdf.h"

int		key_hook(long key, fdf *data)
{
	if(key == 124)
		data->angle +=0.05;
	if(key == 123)
		data->angle -= 0.05;
	if(key == 69)
		data->zoom += 1;
	if(key == 78)
		data->zoom -= 1;
	if(key == 6)
		data->z_coord += 1; 
	if(key == 7)
		data->z_coord -= 1;
	if (key == 13)
		data->shift_y -= 10;
	if (key == 1)
		data->shift_y += 10;
	if (key == 2)
		data->shift_x +=10;
	if (key == 0)
		data->shift_x -=10;
	if (key == 53)
		exit(0);
	return (0);
}

int		key_hook1(long key, fdf *data)
{
	if (key)
	{
		exit(0);
	}
	return 0;
}

int	funct_ptr(fdf * data)
{
	black_img(data);
	draw(data);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img.img, 0, 0);
	mlx_do_sync(data->mlx);
	return 1;
}