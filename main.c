/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarev <skarev@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 19:06:27 by skarev            #+#    #+#             */
/*   Updated: 2019/01/31 19:06:27 by skarev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(int ac, char **av)
{
	int		fd;
	t_m		*map;

	if (ac < 2 || ac > 2)
		ft_error(ER01, NULL, NULL);
	fd = open(av[1], O_RDONLY);
	if (!(map = (t_m*)ft_memalloc(sizeof(t_m))))
		ft_error(ER04, NULL, NULL);
	init_map(map);
	parce(fd, map);
	in_to_int_array(map);
	map->ptr = mlx_init();
	map->window = mlx_new_window(map->ptr, WIN_SIZE_X, WIN_SIZE_Y, "fdf");

	int		point1[3] = {200, 200, 0};
	int		point2[8][3] = {{100, 100, 0},
	{200, 50, 0},
	{300, 100, 0},
	{100, 300, 0},
	{300, 300, 0},
	{200, 350, 0},
	{50, 200, 0},
	{350, 200, 0},
	};

	int i = 0;
	while (i <= 8)
	{
		mlx_pixel_put(map->ptr, map->window, point2[i][0], point2[i][1], 255);
		i++;
	}
	i = 0;
	while (i < 8)
	{
		int		point1[3] = {200, 200, 0};
		// brazenhaime(point2[i++], point1, map);
		brazenhaime(point1, point2[i++], map);
	}














	// draw(map);
	// controls(map);
	mlx_loop(map->ptr);
	return (0);
}
