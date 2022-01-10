/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehosu <ehosu@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 16:03:29 by ehosu             #+#    #+#             */
/*   Updated: 2021/12/10 19:15:02 by ehosu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <errno.h>

int	exit_game(t_window *window)
{
	free_elements(window);
	exit(1);
}

int	main(int argc, char **argv)
{
	int			fd;
	t_window	window;

	if (argc == 2)
	{
		map_extension(argv[1]);
		fd = open(argv[1], O_RDONLY);
		window.map_size = read(fd, window.map, BUFFER_SIZE);
		window.map[window.map_size] = '\0';
		window.map_length = 0;
		check_map(&window);
		construct_elements(&window);
		make_map(&window);
		close(fd);
		mlx_hook(window.window, 19, (1L << 4), make_map, &window);
		mlx_hook(window.window, 2, 1L << 0, key_code, &window);
		mlx_hook(window.window, 33, (1L << 17), exit_game, &window);
		mlx_loop(window.mlx);
	}
	else
	{
		printf("Error: Wrong number of arguments\n");
		exit(EXIT_FAILURE);
	}
	return (0);
}
