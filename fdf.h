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

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;

}				t_data;


typedef struct 
{
	t_data	img;
    int 	height;
    int 	width;
	int 	z_coord;
	int 	**fdf_map;
	int 	zoom;
	int 	color;
	float 	angle;
	int 	hook_key;
	int		shift_x;
	int		shift_y;
	
	void	*mlx;
 	void	*mlx_win;
	
}	fdf;


int		read_result(int r, char **line, char **tmp);
int		get_char(char *str, char c);
char	*get_before_str(char *buf);
char	*del(char *buf);
int		get_next_line(int fd, char **line);
char	*ft_strjoin(char  *s1, char *s2);
int		ft_word_count(char const *s, char c);
char	**ft_split(char const *s, char c);
void    read_file(char  *file_name, fdf *data);
int		ft_atoi(char *s);
int		get_width(char *file_name);
int     get_height(char *file_name);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	black_img(fdf *data);
void 	draw(fdf *data);
void    draw_line(float x, float y, float x1, float y1, fdf *data);
int		key_hook(long key, fdf *data);
int		key_hook1(long key, fdf *data);
int		funct_ptr(fdf * data);

#endif