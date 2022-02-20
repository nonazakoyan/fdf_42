# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nozakoya <nozakoya@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/19 20:57:58 by nozakoya          #+#    #+#              #
#    Updated: 2022/02/20 16:07:49 by nozakoya         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf.a
SRCS = $(shell find "." -maxdepth 1 -name '*.c' ! -name "_bonus.c")
BONUS = $(shell find "." -maxdepth 1 -name '*.c' ! -name "key_hook.c")
CC = gcc minilibx_macos/libmlx.a -framework OpenGL -framework AppKit
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf



all: ${NAME}

${NAME}: 
		@make -C minilibx_macos/ all
		@${CC} ${CFLAGS} -L. ${SRCS} -o fdf

bonus:
		@make -C minilibx_macos/ all
		@${CC} ${CFLAGS} -L. ${BONUS} -o fdf
clean:
	@${RM} ${OBJS}
	@make -C minilibx_macos/ clean

fclean: clean
	@${RM} ${NAME}
	@${RM} fdf

re: fclean all

.PHONY: clean fclean re all
