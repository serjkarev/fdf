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
	draw(map);
	controls(map);
	mlx_loop(map->ptr);
	return (0);
}

// void	brazenhaime(int x1, int y1, int x2, int y2, t_m *map)
// {
// 	int		d_x = ABS(x2 - x1);
// 	int		d_y = ABS(y2 - y1);
// 	int		s_x = x1 < x2 ? 1 : -1;
// 	int		s_y = y1 < y2 ? 1 : -1;
// 	int		error = d_x - d_y;
// 	int 	error2;

// 	mlx_pixel_put(map->ptr, map->window, x2, y2, 255);
// 	while (x1 != x2 || y1 != y2)
// 	{
// 		mlx_pixel_put(map->ptr, map->window, x1, y1, 255);
// 		error2 = error * 2;
// 		if (error2 > -d_y)
// 		{
// 			error -= d_y;
// 			x1 += s_x;
// 		}
// 		if (error2 < d_x)
// 		{
// 			error += d_x;
// 			y1 += s_y;
// 		}
// 	}
// }