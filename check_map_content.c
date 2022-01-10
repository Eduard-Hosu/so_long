/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_content.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehosu <ehosu@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 13:57:17 by ehosu             #+#    #+#             */
/*   Updated: 2021/12/10 18:39:23 by ehosu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	chek_if_content_valid(char item)
{
	if ((item == 'E') || (item == 'C') || (item == 'P') || \
		(item == '1') || (item == '0') || (item == '\n'))
		return (1);
	else
	{
		printf("Error: Content is invalid.\n");
		exit(EXIT_FAILURE);
	}
}

void	handle_item_errors(int exit_c, int player, int collectable)
{
	if (player > 1)
	{
		printf("Error: To many players.\n");
		exit(EXIT_FAILURE);
	}
	if ((exit_c < 1) || (player < 1) || (collectable < 1))
	{
		printf("Error: Not enough content.\n");
		exit(EXIT_FAILURE);
	}
}

void	content_check(t_window *window)
{
	int	exit_c;
	int	player;
	int	i;

	i = 0;
	exit_c = 0;
	window->collectable_number = 0;
	player = 0;
	while (i < window->map_size)
	{
		chek_if_content_valid(window->map[i]);
		if (window->map[i] == 'E')
			exit_c++;
		else if (window->map[i] == 'P')
			player++;
		else if (window->map[i] == 'C')
			window->collectable_number++;
		i++;
	}
	handle_item_errors(exit_c, player, window->collectable_number);
}
