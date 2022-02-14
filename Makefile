NAME = fdf.a
SRCS = *.c
CC = gcc minilibx_macos/libmlx.a -framework OpenGL -framework AppKit
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

all: ${NAME}

${NAME}:
	@make -C minilibx_macos/ all
	@${CC}  -L. ${SRCS} -o fdf

clean:
	@${RM} ${OBJS}
	@make -C minilibx_macos/ clean

fclean: clean
	@${RM} ${NAME}
	${RM} fdf

re: fclean all

.PHONY: clean fclean re all