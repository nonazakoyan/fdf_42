#include "fdf.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	black_img(fdf *data)
{
	int	x;
	int y;
	y = 0;
	while(y < WIN_H)
    {
        x = 0;
        while(x < WIN_L)
        {
            my_mlx_pixel_put(&data->img, x, y, 0x000000);
            ++x;
        }
        ++y;
    }
}

int main(int argc, char **argv)
{
	fdf *data;

	data = (fdf *)malloc(sizeof(fdf));
	data->mlx = mlx_init();
	data->mlx_win = mlx_new_window(data->mlx, WIN_L, WIN_H, "fdf");
	data->img.img = mlx_new_image(data->mlx, WIN_L, WIN_H);
	data->img.addr = mlx_get_data_addr(data->img.img, &data->img.bits_per_pixel, &data->img.line_length,
	 							&data->img.endian);
	data->zoom = 10;
	data->angle = 0.5;
	data->z_coord = 1;
	data->shift_x = WIN_L / 3;
	data->shift_y = WIN_H / 3;
	if (argc == 2)
	{
		char *file_name = argv[1];
		read_file(file_name, data); 
		mlx_hook(data->mlx_win, 2, 1L<<0, key_hook, data);
		mlx_hook(data->mlx_win, 17, 1L<<0, key_hook1, data);
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->img.img, 0, 0);
		mlx_loop_hook(data->mlx, funct_ptr, data);
	}
	mlx_loop(data->mlx);
}