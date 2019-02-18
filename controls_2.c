/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarev <skarev@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 13:53:57 by skarev            #+#    #+#             */
/*   Updated: 2019/02/18 13:53:57 by skarev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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

void	choose_projection(int key, t_m *map)
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

void	sound(int key, t_m *map)
{
	if (key == 1)
		map->delta->sound += 1;
	else if (key == 46)
		map->delta->sound = 0;
	if (map->delta->sound == 1)
		(map->special == 1) ? system("afplay ./sound/special.mp3&") : \
					system("afplay ./sound/take_on_me.mp3&");
	else if (map->delta->sound == 0)
		system("killall afplay");
}

void	rotating_2(int key, t_m *map)
{
	static double	kek = 0.01;
	char			flag = 1;

	if (kek <= 1.55 && flag == 0)
		flag = 1;
	if (kek >= 1.59)
		flag = 0;
	(flag == 0) ? (kek -= 0.01) : (kek += 0.01);
	if (key == 88)
		map->delta->dry += kek;
	else if (key == 86)
		map->delta->dry -= kek;
	else if (key == 91)
		map->delta->drx += kek;
	else if (key == 84)
		map->delta->drx -= kek;
	else if (key == 115)
		map->delta->drz += kek;
	else if (key == 119)
		map->delta->drz -= kek;
}
