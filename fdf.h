/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nozakoya <nozakoya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 20:59:49 by nozakoya          #+#    #+#             */
/*   Updated: 2022/02/19 21:28:06 by nozakoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include  <string.h>
# include <math.h>
# include <mlx.h>
# define WIN_H 1080
# define WIN_L 1920

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;

}			t_data;

typedef struct s_fdf
{
	t_data	img;
	int		height;
	int		width;
	int		z_coord;
	int		**fdf_map;
	int		**color_map;
	int		zoom;
	int		color;
	float	angle;
	int		hook_key;
	int		key;
	int		shift_x;
	int		shift_y;	
	void	*mlx;
	void	*mlx_win;
}			t_fdf;

typedef struct s_coord
{
	float	x;
	float	x1;
	float	y;
	float	y1;
	int		z;
	int		z1;
}			t_coord;

int		read_result(int r, char **line, char **tmp);
int		get_char(char *str, char c);
char	*get_before_str(char *buf);
char	*del(char *buf);
int		get_next_line(int fd, char **line);
char	*ft_strjoin(char *s1, char *s2);
int		ft_word_count(char const *s, char c);
char	**ft_split(char const *s, char c);
void	read_file(char *file_name, t_fdf *data);
int		ft_atoi(char *s);
int		get_width(char *file_name);
int		get_height(char *file_name);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	black_img(t_fdf *data);
void	draw(t_fdf *data);
void	draw_line(t_coord xyz, t_fdf *data);
int		key_hook(int key, t_fdf *data);
int		key_hook1(long key);
int		funct_ptr(t_fdf *data);
void	check_map(char *file_name, t_fdf *data);
int		ft_atoi_base(char *str, char *base);
float	ft_max(float x, float y);
void	fdf_3d(float *x, float *y, int *z, t_fdf *data);
void	fdf_zoom(t_coord *xyz, t_fdf *data);
void	fdf_shift(t_coord *xyz, t_fdf *data);
void	color(t_fdf *data);
char	*ft_strrchr(char *s, int c);
void	fdf_color(t_coord *xyz, t_fdf *data);

#endif
