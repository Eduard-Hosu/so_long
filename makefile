# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ehosu <ehosu@student.42wolfsburg.de>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/30 12:15:30 by ehosu             #+#    #+#              #
#    Updated: 2022/01/10 10:51:19 by ehosu            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
HEADER = so_long.h
SRCS = main.c check_map.c make_map.c check_map_content.c movement.c
OBJS = ${SRCS:.c=.o}
MLX = mlx_linux
RM = rm -rf

CC = gcc
CFLAGS = -g -Wall -Wextra -Werror
LDFLAGS =    -L${MLX} -lft

$(NAME):	mlx_all $(OBJS)
			cd libft && ${MAKE} bonus
			$(CC) -o so_long $(CFLAGS) $(OBJS) ./libft/libft.a mlx_linux/libmlx_Linux.a -L /usr/include/X11/extensions/ -lXext -lX11 -lm
			export DISPLAY=localhost:0.0

all:	${NAME}

clean:
	cd libft && ${MAKE} clean
	${RM} ${OBJS} ./libft/libft.a
	make -C ${MLX} clean

fclean:
	cd libft && ${MAKE} clean
	${RM} ${OBJS} ./libft/libft.a
	make -C ${MLX} clean
	${RM} so_long

re:	clean all

mlx_all:
	cd mlx_linux && ./configure

.PHONY:
	all clean fclean re