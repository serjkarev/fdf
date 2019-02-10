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
	int *point1;
	int	*point2;
	int	*point3;

	i = 0;
	mlx_clear_window(map->ptr, map->window);
	while (i + 1 <= map->arr_len)
	{
		if ((i + 1) % map->width != 0)
		{
			printf("##### FIRST BRAZ #########\n");
			brazenhaime(change(map->array[0][i],map->array[1][i], map->array[2][i], map),change(map->array[0][i+1],map->array[1][i+1], map->array[2][i+1], map), map);
		}
		if (i + map->width < map->arr_len)
		{
			printf("##### SEC BRAZ #########\n");
			brazenhaime(change(map->array[0][i], map->array[1][i], map->array[2][i], map), change(map->array[0][i + map->width], map->array[1][i + map->width], map->array[2][i + map->width], map), map);
		}
		
		
		i++;
	}
}

# define OVER_DOHUA 1000

void	brazenhaime(int *point1, int *point2, t_m *map)
{
	int		d_x = ABS(point2[0] - point1[0]);
	int		d_y = ABS(point2[1] - point1[1]);
	int		s_x = point1[0] < point2[0] ? 1 : -1;
	int		s_y = point1[1] < point2[1] ? 1 : -1;
	int		error = d_x - d_y;
	int 	error2;
	
	printf("########### IN BRAZ ##################\n");
	printf("point1 x = %d y = %d z = %d\n", point1[0], point1[1], point1[2]);
	printf("point2 x = %d y = %d z = %d\n", point2[0], point2[1], point2[2]);
	// if (point2[0] > 0 && point2[0] < WIN_SIZE_X && point2[1] > 0 && point2[1] < WIN_SIZE_Y)
	mlx_pixel_put(map->ptr, map->window, point2[0], point2[1], 255);
	int a = 0;
	while (point1[0] != point2[0] || point1[1] != point2[1])
	{
		a++;
		if (a > OVER_DOHUA)
		{
			printf("huihuihuihuihuihuihuihuihuihuihuihui\n");
			printf("point1 x = %d y = %d z = %d\n", point1[0], point1[1], point1[2]);
			printf("point2 x = %d y = %d z = %d\n", point2[0], point2[1], point2[2]);
			break;
		}
		// if (point1[0] > 0 && point1[0] < WIN_SIZE_X && point1[1] > 0 && point1[1] < WIN_SIZE_Y)
		mlx_pixel_put(map->ptr, map->window, point1[0], point1[1], 255);
		error2 = error * 2;
		if (error2 > -d_y)
		{
			error -= d_y;
			point1[0] += s_x;
		}
		if (error2 < d_x)
		{
			error += d_x;
			point1[1] += s_y;
		}
	}
	// free(point1);
	// free(point2);
}

int		*change(int x, int y, int z, t_m *map)
{
	int		*out;

	// printf("prev x = %d y = %d z = %d\n", x, y, z);
	out = (int*)ft_memalloc(sizeof(int) * 3);
	out[0] = x * map->delta->ds;
	out[1] = y * map->delta->ds;
	out[2] = z * (map->delta->ds / map->delta->dz);//возможно здесь
	out[0] -= (map->width * map->delta->ds) / 2;
	out[1] -= (map->length * map->delta->ds) / 2;
	out = rot_x(out, map);
	out = rot_y(out, map);
	out = rot_z(out, map);
	if (map->project == 2)
	{
		// out = isometric(out);
		// printf("###########################################\n");
		// printf("x = %d y = %d z = %d\n", out[0], out[1], out[2]);
		isometric(out);
		// printf("x = %d y = %d z = %d\n", out[0], out[1], out[2]);
		// printf("###########################################\n");
	}
	out[0] += WIN_SIZE_X / 2 + map->delta->dx;
	out[1] += (WIN_SIZE_Y + map->delta->ds) / 2 + map->delta->dy;
	// printf("after x = %d y = %d z = %d\n", out[0], out[1], out[2]);
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

// int		*isometric(int *point)
// {
// 	int	prev_x;
// 	int	prev_y;

// 	prev_x = point[0];
// 	prev_y = point[1];
// 	point[0] = (prev_x - prev_y) * cos(0.523599);
// 	point[1] = -point[2] + (prev_x + prev_y) * sin(0.523599);
// 	return (point);
// }

void	isometric(int *point)
{
	int	prev_x;
	int	prev_y;

	prev_x = point[0];
	prev_y = point[1];
	point[0] = (prev_x - prev_y) * cos(0.523599);
	point[1] = -point[2] + (prev_x + prev_y) * sin(0.523599);
}