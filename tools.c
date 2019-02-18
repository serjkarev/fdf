/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarev <skarev@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 21:20:29 by skarev            #+#    #+#             */
/*   Updated: 2019/01/31 21:20:29 by skarev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_error(char *er_str, char *str, char **arr)
{
	if (str)
		free(str);
	if (arr)
	{
		while (arr)
			free(arr++);
	}
	ft_putstr(er_str);
	ft_putstr(USAGE);
	exit(1);
}

void	in_to_int_array(t_m *map)
{
	unsigned long	i;
	t_e				*head;

	i = 0;
	map->arr_len = 0;
	map->array = (int**)ft_memalloc(sizeof(int*) * 4);
	map->array[0] = (int*)ft_memalloc(sizeof(int) * (map->width * map->length));
	map->array[1] = (int*)ft_memalloc(sizeof(int) * (map->width * map->length));
	map->array[2] = (int*)ft_memalloc(sizeof(int) * (map->width * map->length));
	map->array[3] = (int*)ft_memalloc(sizeof(int) * (map->width * map->length));
	head = map->elem;
	while (head)
	{
		map->array[0][i] = head->x;
		map->array[1][i] = head->y;
		map->array[2][i] = head->z;
		map->array[3][i] = head->color;
		if (head->color == 0)
			map->array[3][i] = 255;
		map->arr_len += 1;
		i++;
		head = head->next;
	}
	if (map->arr_len < 2)
		ft_error(ER06, NULL, NULL);
}

void	init_braz(t_b *braz, int *point1, int *point2, int color)
{
	braz->dx = (point2[0] - point1[0] >= 0 ? 1 : -1);
	braz->dy = (point2[1] - point1[1] >= 0 ? 1 : -1);
	braz->lengthx = abs(point2[0] - point1[0]);
	braz->lengthy = abs(point2[1] - point1[1]);
	braz->length = fmax(braz->lengthx, braz->lengthy);
	braz->color = color;
}

void	braz_helper(t_m *map, t_b *braz, int *point1, int flag)
{
	int x;
	int y;
	int d;

	x = point1[0];
	y = point1[1];
	(flag == 1) ? (d = -braz->lengthx) : \
	(d = -braz->lengthy);
	braz->length++;
	while (braz->length--)
	{
		if (x <= WIN_SIZE_X && x >= 0 && y <= WIN_SIZE_Y && y >= 0)
			pixel_put(map, x, y, braz->color);
		(flag == 1) ? (x += braz->dx) : (y += braz->dy);
		(flag == 1) ? (d += 2 * braz->lengthy) : (d += 2 * braz->lengthx);
		if (d > 0)
		{
			(flag == 1) ? (d -= 2 * braz->lengthx) : (d -= 2 * braz->lengthy);
			(flag == 1) ? (y += braz->dy) : (x += braz->dx);
		}
	}
}

void	print_help_menu(void *ptr, void *window)
{
	mlx_string_put(ptr, window, 10, 10, 0x32CD32, "   HELP MENU");
	mlx_string_put(ptr, window, 10, 40, 0x32CD32, "isometric(def) 1");
	mlx_string_put(ptr, window, 10, 60, 0x32CD32, "parralel       2");
	mlx_string_put(ptr, window, 10, 100, 0x32CD32, "move left    <");
	mlx_string_put(ptr, window, 10, 120, 0x32CD32, "move right   >");
	mlx_string_put(ptr, window, 10, 140, 0x32CD32, "move up      ^");
	mlx_string_put(ptr, window, 10, 160, 0x32CD32, "move down    v");
	mlx_string_put(ptr, window, 10, 200, 0x32CD32, "zoom         +-");
	mlx_string_put(ptr, window, 10, 230, 0x32CD32, "rot x        num2 num8");
	mlx_string_put(ptr, window, 10, 250, 0x32CD32, "rot y        num4 num6");
	mlx_string_put(ptr, window, 10, 270, 0x32CD32, "rot z        home end");
	mlx_string_put(ptr, window, 10, 310, 0x32CD32, "flatten      pg_up pg_dwn");
	mlx_string_put(ptr, window, 10, 340, 0x32CD32, "colors       c");
	mlx_string_put(ptr, window, 10, 360, 0x32CD32, "colors(def)  d");
	mlx_string_put(ptr, window, 10, 390, 0x32CD32, "music on     s");
	mlx_string_put(ptr, window, 10, 410, 0x32CD32, "music off    m");
	mlx_string_put(ptr, window, 10, 430, 0x32CD32, "music in background");
	mlx_string_put(ptr, window, 10, 450, 0x32CD32, "tap s one more time");
}
