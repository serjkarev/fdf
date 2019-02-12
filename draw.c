/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarev <skarev@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 16:30:43 by skarev            #+#    #+#             */
/*   Updated: 2019/02/04 16:30:43 by skarev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw(t_m *map)
{
	int i;

	i = 0;
	mlx_clear_window(map->ptr, map->window);
	while (i + 1 <= map->arr_len)
	{
		if ((i + 1) % map->width != 0)
			brazenhaime(change(map->array[0][i],map->array[1][i], map->array[2][i], map),\
				change(map->array[0][i+1],map->array[1][i+1], map->array[2][i+1], map), map);
		if (i + map->width < map->arr_len)
			brazenhaime(change(map->array[0][i], map->array[1][i], map->array[2][i], map), \
				change(map->array[0][i + map->width], map->array[1][i + map->width], map->array[2][i + map->width], map), map);
		i++;
	}
	if (map->delta->help == 1)
		print_help_menu(map);
}
 
void	brazenhaime(int *point1, int *point2, t_m *map)
{
	t_b		*braz;

	braz = (t_b*)ft_memalloc(sizeof(t_b));
	init_braz(braz, point1, point2);
	if (braz->length == 0)
		mlx_pixel_put(map->ptr, map->window, point1[0], point1[1], 255);
	if (braz->lengthY <= braz->lengthX)
		braz_helper(map, braz, point1, 1);
	else
		braz_helper(map, braz, point1, 2);
	free(point1);
	free(point2);
	free(braz);
}

int		*change(int x, int y, int z, t_m *map)
{
	int		*out;

	out = (int*)ft_memalloc(sizeof(int) * 3);
	out[0] = x * map->delta->ds;
	out[1] = y * map->delta->ds;
	out[2] = z * (map->delta->ds / map->delta->dz);
	out[0] -= (map->width * map->delta->ds) / 2;
	out[1] -= (map->length * map->delta->ds) / 2;
	out = rot_x(out, map);
	out = rot_y(out, map);
	out = rot_z(out, map);
	if (map->project == 1)
		out = isometric(out);
	out[0] += WIN_SIZE_X / 2 + map->delta->dx;
	out[1] += (WIN_SIZE_Y + map->delta->ds) / 2 + map->delta->dy;
	return (out);
}

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
