/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehosu <ehosu@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 17:04:12 by ehosu             #+#    #+#             */
/*   Updated: 2021/12/10 18:57:00 by ehosu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "mlx_linux/mlx.h"
# include <stdlib.h>
# include <unistd.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>
# include "libft/libft.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2000
# endif

typedef struct s_image
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		x;
	int		y;
	int		position;
	int		steps;
}	t_image;

typedef struct s_window
{
	char		map[BUFFER_SIZE + 1];
	int			map_size;
	void		*mlx;
	void		*window;
	int			x;
	int			y;
	int			map_length;
	int			map_row;
	int			collectable_number;
	t_image		*wall;
	t_image		*player;
	t_image		*floor;
	t_image		*collectable;
	t_image		*escape;
}	t_window;

t_image	*initialize_image(t_window *wind_mlx, char	*relative_path);
void	map_extension(char *argv);
void	check_map(t_window *window);
void	check_rectangular(t_window *window);
void	check_rows_and_length(t_window *window);
void	construct_elements(t_window *window);
int		make_map(t_window *window);
void	check_map_wall(int i, t_window *window);
void	content_check(t_window *window);
int		key_code(int keycode, t_window *window);
void	free_elements(t_window *window);

#endif