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
		map->elem->z = ft_atoi(arr[0]);
		// map->elem->color = ft_atoi(arr[1]);//тут тоже нужно будет подумать как правильно
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
		map->elem->tail->z = ft_atoi(arr[0]);
		// map->elem->tail->color = ft_atoi(arr[1]);//и вот тут тоже подумать
		map->elem->tail->next = NULL;
	}
}

void	create_elem(t_m *map, char *point)
{
	if (!map->elem)
	{
		map->elem = (t_e*)ft_memalloc(sizeof(t_e));
		map->elem->x = map->curr_pos;
		map->elem->y = map->length;
		map->elem->z = ft_atoi(point);
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
		map->elem->tail->z = ft_atoi(point);
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
	else
		create_elem(map, point);
	return (1);
}

void	valid(t_m *map, char *str, int flag)
{
	int		i;
	int 	j;
	char	**arr;

	i = 0;
	j = 0;
	arr = ft_strsplit(str, ' ');
	if (!flag)
	{
		while(arr[j])
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
}

void	parce(int fd, t_m *map)
{
	int		flag;
	char	*str;

	flag = 0;
	while (get_next_line(fd, &str))
	{
		valid(map, str, flag);
		flag = 1;
		map->length += 1;
		free(str);
	}
}