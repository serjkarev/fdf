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
	while (i + 1 <= map->arr_len)
	{
		if ((i + 1) % map->width != 0)
			brazenhaime(map->array[0][i],map->array[1][i],map->array[0][i+1],map->array[1][i+1], map);
		if (i + map->width < map->arr_len)
			brazenhaime(map->array[0][i], map->array[1][i], map->array[0][i + map->width], map->array[1][i + map->width], map);
		i++;
	}
}

void	brazenhaime(int x1, int y1, int x2, int y2, t_m *map)
{
	int		d_x = ABS(x2 - x1);
	int		d_y = ABS(y2 - y1);
	int		s_x = x1 < x2 ? 1 : -1;
	int		s_y = y1 < y2 ? 1 : -1;
	int		error = d_x - d_y;
	int 	error2;

	mlx_pixel_put(map->ptr, map->window, x2, y2, 255);
	while (x1 != x2 || y1 != y2)
	{
		mlx_pixel_put(map->ptr, map->window, x1, y1, 255);
		error2 = error * 2;
		if (error2 > -d_y)
		{
			error -= d_y;
			x1 += s_x;
		}
		if (error2 < d_x)
		{
			error += d_x;
			y1 += s_y;
		}
	}
}