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
	t_e		*head;

	i = 0;
	map->arr_len = 0;
	map->array = (int**)ft_memalloc(sizeof(int*) * 3);
	map->array[0] = (int*)ft_memalloc(sizeof(int) * (map->width * map->length));
	map->array[1] = (int*)ft_memalloc(sizeof(int) * (map->width * map->length));
	map->array[2] = (int*)ft_memalloc(sizeof(int) * (map->width * map->length));
	head = map->elem;
	while (head)
	{
		map->array[0][i] = (head->x * map->scale + WIN_SIZE_X / 2 - map->width / 2 * map->scale);
		map->array[1][i] = (head->y * map->scale + WIN_SIZE_Y / 2 - map->length / 2 * map->scale);
		// map->array[0][i] = head->x;
		// map->array[1][i] = head->y;
		map->array[2][i] = head->z;
		map->arr_len += 1;
		i++;
		head = head->next;
	}
}

void	scale_calc(t_m *map)
{
	int		x;
	int		y;

	x = WIN_SIZE_X / map->width;
	y = WIN_SIZE_Y / map->length;
	(x <= y) ? (map->scale = x / 1.2) : (map->scale = y / 1.2);
}
