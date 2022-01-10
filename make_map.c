/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehosu <ehosu@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 17:01:51 by ehosu             #+#    #+#             */
/*   Updated: 2021/12/10 18:57:25 by ehosu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_image	*initialize_image(t_window *wind_mlx, char	*relative_path)
{
	int		img_width;
	int		img_height;
	t_image	*image;

	img_width = 60;
	img_height = 50;
	image = calloc(1, sizeof(t_image));
	image->img = mlx_xpm_file_to_image(wind_mlx->mlx, relative_path, \
		&img_width, &img_height);
	image->addr = mlx_get_data_addr(image->img, &image->bits_per_pixel, \
		&image->line_length, &image->endian);
	return (image);
}

void	*handle_char(int i, t_window *window)
{
	if (window->map[i] == '1')
		mlx_put_image_to_window(window->mlx, window->window, \
			window->wall->img, window->x, window->y);
	else if (window->map[i] == '0')
		mlx_put_image_to_window(window->mlx, window->window, \
			window->floor->img, window->x, window->y);
	else if (window->map[i] == 'P')
	{
		mlx_put_image_to_window(window->mlx, window->window, \
			window->player->img, window->x, window->y);
		window->player->x = window->x;
		window->player->y = window->y;
		window->player->position = i;
	}
	else if (window->map[i] == 'C')
		mlx_put_image_to_window(window->mlx, window->window, \
			window->collectable->img, window->x, window->y);
	else if (window->map[i] == 'E')
		mlx_put_image_to_window(window->mlx, window->window, \
			window->escape->img, window->x, window->y);
	return (NULL);
}

int	make_map(t_window *window)
{
	int	i;

	window->y = 0;
	window->x = 0;
	i = 0;
	while (i < window->map_size)
	{
		if (window->map[i] == '\n')
		{
			window->x = 0;
			window->y += 50;
			i++;
		}
		handle_char(i, window);
		window->x += 60;
		i++;
	}
	return (1);
}

void	construct_elements(t_window *window)
{
	window->mlx = mlx_init();
	window->window = mlx_new_window(window->mlx, (window->map_length - 1) * \
		60, (window->map_row + 1) * 50, "so_long");
	window->wall = initialize_image(window, "images/wall_1.xpm");
	window->floor = initialize_image(window, "images/floor_0.xpm");
	window->player = initialize_image(window, "images/duck_p.xpm");
	window->collectable = initialize_image(window, \
		"images/collectable_c.xpm");
	window->escape = initialize_image(window, "images/portal_e.xpm");
}

void	free_elements(t_window *window)
{
	mlx_destroy_image(window->mlx, window->wall->img);
	free(window->wall);
	mlx_destroy_image(window->mlx, window->player->img);
	free(window->player);
	mlx_destroy_image(window->mlx, window->floor->img);
	free(window->floor);
	mlx_destroy_image(window->mlx, window->escape->img);
	free(window->escape);
	mlx_destroy_image(window->mlx, window->collectable->img);
	free(window->collectable);
	mlx_destroy_window(window->mlx, window->window);
	mlx_destroy_display(window->mlx);
	free(window->mlx);
}
