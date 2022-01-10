/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehosu <ehosu@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 22:13:18 by ehosu             #+#    #+#             */
/*   Updated: 2021/12/12 15:47:37 by ehosu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	collect_coins(int position, t_window *window)
{
	if (window->map[position] == 'C')
		window->collectable_number--;
}

void	check_position(int check_position, int position, t_window *window)
{
	if ((window->map[check_position] == 'E')
		&& (window->collectable_number == 0))
	{
		window->map[position] = '0';
		printf("Congrats, game finished successfully!\n");
		free_elements(window);
		exit(EXIT_SUCCESS);
	}
	else if (window->map[check_position] != 'E')
	{
		window->map[check_position] = 'P';
		window->map[position] = '0';
		window->player->steps++;
	}
}

void	hadle_cheks(int to_check, int position, t_window *window)
{
	collect_coins(to_check, window);
	check_position(to_check, position, window);
}

int	key_code(int keycode, t_window *window)
{
	if (keycode == 65307)
	{
		free_elements(window);
		exit(1);
	}
	else if ((keycode == 119) && \
		(window->map[window->player->position - window->map_length] != '1'))
		hadle_cheks(window->player->position - window->map_length, \
			window->player->position, window);
	else if ((keycode == 115) && \
		(window->map[window->player->position + window->map_length] != '1'))
		hadle_cheks(window->player->position + window->map_length, \
			window->player->position, window);
	else if ((keycode == 100) && \
		(window->map[window->player->position + 1] != '1'))
		hadle_cheks(window->player->position + 1, \
			window->player->position, window);
	else if ((keycode == 97) && \
		(window->map[window->player->position - 1] != '1'))
		hadle_cheks(window->player->position - 1, \
			window->player->position, window);
	printf("%d\n", window->player->steps);
	make_map(window);
	return (1);
}
