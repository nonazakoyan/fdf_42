#include "fdf.h"

int     check_map(char *file_name)
{
    int width;
    int fd;
    char *line;
    int w;

    fd = open(file_name, O_RDONLY);
    get_next_line(fd, &line); 
    width = ft_word_count(line, ' ');
    free(line);
    while (get_next_line(fd, &line))
    {
        w = ft_word_count(line, ' ');
        free(line);
        if(w != width)
        {
            write(1, "ERROR\n", 6);
            return (1);
        }
    }
    free(line);
    close (fd);
    return (0);
}