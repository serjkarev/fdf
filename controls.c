/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarev <skarev@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 14:30:41 by skarev            #+#    #+#             */
/*   Updated: 2019/02/18 14:30:41 by skarev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		close_icon(void *param)
{
	(void)param;
	system("killall afplay");
	exit(0);
	return (0);
}

int		keypress(int key, void *param)
{
	t_m	*map;

	map = (t_m*)param;
	if (key == 53)
	{
		(map->delta->sound == 2) ? 0 : system("killall afplay");
		exit(0);
	}
	else if (key >= 123 && key <= 126)
		xy_moving(key, map);
	else if (key == 84 || key == 86 || key == 88 || \
			key == 91 || key == 115 || key == 119)
		(map->special == 1 && map->delta->sound == 1) ? \
		rotating_2(key, map) : rotating(key, map);
	else if (key == 78 || key == 69)
		scaling(key, map);
	else if (key == 18 || key == 19)
		choose_projection(key, map);
	else if (key == 116 || key == 121)
		z_change(key, map);
	else if (key == 4 || key == 8)
		(key == 4) ? help_switch(map) : change_color(map);
	else if (key == 2 || key == 1 || key == 46)
		(key == 2) ? map->custom_color = 0 : sound(key, map);
	ft_bzero(map->data_adr, (map->bit_per_pix / 8) * WIN_SIZE_X * WIN_SIZE_Y);
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

void	scaling(int key, t_m *map)
{
	if (key == 78)
		map->delta->ds--;
	else if (key == 69)
		map->delta->ds++;
	if (map->delta->ds < 1)
		map->delta->ds = 1;
}
