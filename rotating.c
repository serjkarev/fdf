/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotating.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarev <skarev@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 13:57:40 by skarev            #+#    #+#             */
/*   Updated: 2019/02/18 13:57:41 by skarev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		*rot_x(int *point, t_m *map)
{
	int	prev_y;

	prev_y = point[1];
	point[1] = prev_y * cos(map->delta->drx) + point[2] * sin(map->delta->drx);
	point[2] = -prev_y * sin(map->delta->drx) + point[2] * cos(map->delta->drx);
	return (point);
}

int		*rot_y(int *point, t_m *map)
{
	int	prev_x;

	prev_x = point[0];
	point[0] = prev_x * cos(map->delta->dry) + point[2] * sin(map->delta->dry);
	point[2] = -prev_x * sin(map->delta->dry) + point[2] * cos(map->delta->dry);
	return (point);
}

int		*rot_z(int *point, t_m *map)
{
	int	prev_x;
	int	prev_y;

	prev_x = point[0];
	prev_y = point[1];
	point[0] = prev_x * cos(map->delta->drz) - prev_y * sin(map->delta->drz);
	point[1] = prev_x * sin(map->delta->drz) + prev_y * cos(map->delta->drz);
	return (point);
}

int		*isometric(int *point)
{
	int	prev_x;
	int	prev_y;

	prev_x = point[0];
	prev_y = point[1];
	point[0] = (prev_x - prev_y) * cos(0.523599);
	point[1] = -point[2] + (prev_x + prev_y) * sin(0.523599);
	return (point);
}
