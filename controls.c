/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarev <skarev@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 15:46:35 by skarev            #+#    #+#             */
/*   Updated: 2019/02/07 15:46:36 by skarev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	controls(t_m *map)
{
	// mlx_hook(map->window, 17, 0, close, (void*)map);
	mlx_hook(map->window, 2, 0, keypress, (void*)map);
}

int		keypress(int key, void *param)
{
	t_m	*map;

	map = (t_m*)param;
	printf("%d\n", key);
	if (key == 53)
		exit(0);
	else if (key >= 123 && key <= 126)
		xyz_moving(key, map);
	else if (key == 84 || key == 86 || key == 88 || \
			key == 91 || key == 115 || key == 119)
		rotating(key, map);
	// else if (key == 78 || key == 69)
	// 	scaling(key, map);
	// else if (key == 18 || key == 19)
	// 	choose_projection(key, map);
	else if (key == 116 || key == 121)
		z_change(key, map);
	else if (key == 4)
		map->delta->help = 1;
	return (0);
}

// int		close(void *param)
// {
// 	(void)param;
// 	exit(0);
// 	return (0);
// }

void	xyz_moving(int key, t_m *map)
{
	if (key == 123)
		map->delta->dx -= 5;
	else if (key == 124)
		map->delta->dx += 5;
	else if (key == 126)
		map->delta->dy -= 5;
	else if (key == 125)
		map->delta->dy += 5;
	draw(map);
}

void	rotating(int key, t_m *map)
{
	if (key == 88)
		map->delta->dry += 0.03;
	else if (key == 86)
		map->delta->dry -= 0.03;
	else if (key == 91)
		map->delta->drx += 0.03;
	else if (key == 84)
		map->delta->drx -= 0.03;
	else if (key == 115)
		map->delta->dry += 0.03;
	else if (key == 119)
		map->delta->dry -= 0.03;
	draw(map);
}

void	z_change(int key, t_m *map)
{
	if (key == 116)
		map->delta->ds += 0.2;
	else if (key == 121)
		map->delta->ds -= 0.2;
	if (map->delta->ds < 0.2)
		map->delta->ds = 0.2;
	else if (map->delta->ds > 10)
		map->delta->ds = 10;
	draw(map);
}

// void	choose_projection(int key,  t_m *map)
// {
// 	if (key == 18)
// 		make_parralel(map);
// 	else if (key == 19)
// 		make_isometric(map);
// }