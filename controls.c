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

int		close_icon(void *param)
{
	(void)param;
	exit(0);
	return (0);
}

void	controls(t_m *map)
{
	mlx_hook(map->window, 17, 0, close_icon, (void*)map);
	mlx_hook(map->window, 2, 0, keypress, (void*)map);
}

int		keypress(int key, void *param)
{
	t_m	*map;

	map = (t_m*)param;
	if (key == 53)
		exit(0);
	else if (key >= 123 && key <= 126)
		xy_moving(key, map);
	else if (key == 84 || key == 86 || key == 88 || \
			key == 91 || key == 115 || key == 119)
		rotating(key, map);
	else if (key == 78 || key == 69)
		scaling(key, map);
	else if (key == 18 || key == 19)
		choose_projection(key, map);
	else if (key == 116 || key == 121)
		z_change(key, map);
	else if (key == 4 || key == 8)
		(key == 4) ? help_switch(map) : change_color(map);
	else if (key == 2)
		map->custom_color = 0;
	draw(map);
	return (0);
}


void	xy_moving(int key, t_m *map)
{
	if (key == 123)
		map->delta->dx -= 10;
	else if (key == 124)
		map->delta->dx += 10;
	else if (key == 126)
		map->delta->dy -= 10;
	else if (key == 125)
		map->delta->dy += 10;
}

void	rotating(int key, t_m *map)
{
	if (key == 88)
		map->delta->dry += 0.05;
	else if (key == 86)
		map->delta->dry -= 0.05;
	else if (key == 91)
		map->delta->drx += 0.05;
	else if (key == 84)
		map->delta->drx -= 0.05;
	else if (key == 115)
		map->delta->drz += 0.05;
	else if (key == 119)
		map->delta->drz -= 0.05;
}

void	z_change(int key, t_m *map)
{
	if (key == 116)
		map->delta->dz -= 0.1;
	else if (key == 121)
		map->delta->dz += 0.1;
	if (map->delta->dz < 0.1)
		map->delta->dz = 0.1;
	else if (map->delta->dz > 10)
		map->delta->dz = 10;
}

void	scaling(int key, t_m *map)
{
	if (key == 78)
		map->delta->ds--;
	else if (key == 69)
		map->delta->ds++;
	if (map->delta->ds < 1)
		map->delta->ds = 1;
}

void	choose_projection(int key,  t_m *map)
{
	map->delta->drx = 0;
	map->delta->dry = 0;
	map->delta->drz = 0;
	if (key == 18)
		map->project = 1;
	else if (key == 19)
		map->project = 2;
}

void	help_switch(t_m *map)
{
	if (map->delta->help == 1)
		map->delta->help = 0;
	else if (map->delta->help == 0)
		map->delta->help = 1;
}

void	change_color(t_m *map)
{
	if (map->delta->dc == 0)
		map->custom_color = 16711680;
	else if (map->delta->dc == 1)
		map->custom_color = 16711851;
	else if (map->delta->dc == 2)
		map->custom_color = 11206911;
	else if (map->delta->dc == 3)
		map->custom_color = 255;
	else if (map->delta->dc == 4)
		map->custom_color = 44031;
	else if (map->delta->dc == 5)
		map->custom_color = 65451;
	else if (map->delta->dc == 6)
		map->custom_color = 65280;
	else if (map->delta->dc == 7)
		map->custom_color = 11271936;
	else if (map->delta->dc == 8)
		map->custom_color = 16755456;
	map->delta->dc += 1;
	if (map->delta->dc > 8)
		map->delta->dc = 0;
}
