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
	map->img = mlx_new_image(map->ptr, WIN_SIZE_X, WIN_SIZE_Y);
	map->data_adr = mlx_get_data_addr(map->img, &(map->bit_per_pix),
										&(map->line_size), &(map->endian));
	draw(map);
	controls(map);
	mlx_loop(map->ptr);
	return (0);
}
