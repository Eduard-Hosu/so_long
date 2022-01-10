/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehosu <ehosu@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 12:19:33 by ehosu             #+#    #+#             */
/*   Updated: 2022/01/10 10:42:03 by ehosu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_extension(char *argv)
{
	int	argv_len;

	argv_len = ft_strlen(argv);
	if ((argv[argv_len - 1] != 'r') || (argv[argv_len - 2] != 'e') || \
		(argv[argv_len - 3] != 'b'))
	{
		printf("Error: Wrong extension.\n");
		exit(EXIT_FAILURE);
	}
}

void	check_map_wall(int i, t_window *window)
{
	if (window->map[i - 1] != '1' || window->map[i + 1] != '1')
	{
		printf("Error: The map must be closed/surrounded by walls.\n");
		exit(EXIT_FAILURE);
	}
}

void	check_rectangular(t_window *window)
{
	int	i;

	i = 1;
	while (i <= window->map_row)
	{
		if (window->map[window->map_length * i - 1] != '\n')
		{
			printf("Error: Map is not rectangular.\n");
			exit(EXIT_FAILURE);
		}
		i++;
	}
	if (window->map[window->map_length * (window->map_row + 1) - 1] != '\0')
	{
		printf("Error: Map is not rectangular.\n");
		exit(EXIT_FAILURE);
	}
}

void	check_first_and_last_wall(t_window *window)
{
	int	i;
	int	check;

	i = 0;
	while (window->map[i] != '\n')
	{
		if (window->map[i] != '1')
		{
			printf("Error: Map is invalid.\n");
			exit(EXIT_FAILURE);
		}
		i++;
	}
	check = window->map_length * (window->map_row + 1) - 2;
	while (window->map[check] != '\n')
	{
		if (window->map[check] != '1')
		{
			printf("Error: Map is invalid.\n");
			exit(EXIT_FAILURE);
		}
		check--;
	}
}

void	check_map(t_window *window)
{
	int	i;
	int	flag;

	i = 0;
	window->map_row = 0;
	flag = 1;
	while (i < window->map_size)
	{
		if (window->map[i] == '\n')
		{
			check_map_wall(i, window);
			window->map_row++;
			i++;
			if (flag)
			{
				window->map_length = i;
				flag = 0;
			}
			continue ;
		}
		i++;
	}
	check_rectangular(window);
	check_first_and_last_wall(window);
	content_check(window);
}
