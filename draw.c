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
	int color;

	i = 0;
	while (i + 1 <= map->arr_len)
	{
		color = map->array[3][i] + map->custom_color;
		if ((i + 1) % map->width != 0)
			brazenhaime(\
			change(map->array[0][i], map->array[1][i], map->array[2][i], map),\
			change(map->array[0][i + 1], map->array[1][i + 1],\
			map->array[2][i + 1], map), map, color);
		if (i + map->width < map->arr_len)
			brazenhaime(\
			change(map->array[0][i], map->array[1][i], map->array[2][i], map),\
			change(map->array[0][i + map->width],\
			map->array[1][i + map->width], map->array[2][i + map->width],\
			map), map, color);
		i++;
	}
	mlx_put_image_to_window(map->ptr, map->window, map->img, 0, 0);
	if (map->delta->help == 1)
		print_help_menu(map->ptr, map->window);
}

void	brazenhaime(int *point1, int *point2, t_m *map, int color)
{
	t_b		*braz;

	braz = (t_b*)ft_memalloc(sizeof(t_b));
	init_braz(braz, point1, point2, color);
	if (braz->length == 0)
		pixel_put(map, point1[0], point1[1], braz->color);
	if (braz->lengthy <= braz->lengthx)
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

void	pixel_put(t_m *map, int x, int y, int color)
{
	int	i;

	if (x > 0 && x < WIN_SIZE_X && y > 0 && y < WIN_SIZE_Y)
	{
		i = ((x * map->bit_per_pix / 8) + (y * map->line_size));
		*((unsigned int *)&map->data_adr[i]) = color;
	}
}
