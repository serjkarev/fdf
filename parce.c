/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parce.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarev <skarev@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 21:17:07 by skarev            #+#    #+#             */
/*   Updated: 2019/01/31 21:17:07 by skarev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	create_color_elem(t_m *map, char *point)
{
	char	**arr;

	if (!map->elem)
	{
		map->elem = (t_e*)ft_memalloc(sizeof(t_e));
		map->elem->x = map->curr_pos;
		map->elem->y = map->length;
		arr = ft_strsplit(point, ',');
		atoi_color_and_z(NULL, arr, map->elem);
		map->elem->next = NULL;
		map->elem->tail = map->elem;
	}
	else
	{
		map->elem->tail->next = (t_e*)ft_memalloc(sizeof(t_e));
		map->elem->tail = map->elem->tail->next;
		map->elem->tail->x = map->curr_pos;
		map->elem->tail->y = map->length;
		arr = ft_strsplit(point, ',');
		atoi_color_and_z(NULL, arr, map->elem->tail);
		map->elem->tail->next = NULL;
	}
	free_arr(arr);
	free(point);
}

void	create_elem(t_m *map, char *point)
{
	if (!map->elem)
	{
		map->elem = (t_e*)ft_memalloc(sizeof(t_e));
		map->elem->x = map->curr_pos;
		map->elem->y = map->length;
		atoi_color_and_z(point, NULL, map->elem);
		map->elem->color = 0;
		map->elem->next = NULL;
		map->elem->tail = map->elem;
	}
	else
	{
		map->elem->tail->next = (t_e*)ft_memalloc(sizeof(t_e));
		map->elem->tail = map->elem->tail->next;
		map->elem->tail->x = map->curr_pos;
		map->elem->tail->y = map->length;
		atoi_color_and_z(point, NULL, map->elem->tail);
		map->elem->tail->color = 0;
		map->elem->tail->next = NULL;
	}
	free(point);
}

int		check_point(t_m *map, char *point)
{
	int		i;
	int		comma;
	int		x;

	i = 0;
	comma = 0;
	x = 0;
	while (point[i])
	{
		if (point[i] == ',' || point[i] == 'x')
			point[i] == ',' ? comma++ : x++;
		else if (!ft_isdigit(point[i]) && (comma > 1 || x > 1) &&\
							(point[i] != ',' && point[i] != 'x'))
			return (0);
		i++;
	}
	if (x == 1 && comma == 1)
		create_color_elem(map, point);
	else if (x == 0 && comma == 0)
		create_elem(map, point);
	else
		ft_error(ER05, NULL, NULL);
	return (1);
}

void	valid(t_m *map, char *str, int flag)
{
	int		i;
	int		j;
	char	**arr;

	i = 0;
	j = 0;
	if (!(arr = ft_strsplit(str, ' ')))
		ft_error(ER01, NULL, NULL);
	if (!flag)
	{
		while (arr[j])
			j++;
		map->width = j;
	}
	map->curr_pos = 0;
	while (arr[i])
	{
		if (!check_point(map, arr[i]))
			ft_error(ER02, NULL, arr);
		map->curr_pos++;
		i++;
	}
	free(arr);
	if (map->curr_pos > map->width || map->curr_pos < map->width)
		ft_error(ER03, NULL, NULL);
}

void	parce(int fd, t_m *map)
{
	int		res;
	int		flag;
	char	*str;

	flag = 0;
	while ((res = get_next_line(fd, &str)) == 1)
	{
		valid(map, str, flag);
		flag = 1;
		map->length += 1;
		free(str);
	}
	if (res < 0)
		ft_error(ER01, NULL, NULL);
}
