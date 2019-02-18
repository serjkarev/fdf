/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stuff.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarev <skarev@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 10:02:53 by skarev            #+#    #+#             */
/*   Updated: 2019/02/01 10:02:54 by skarev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_map(t_m *map, char *av)
{
	t_d		*d;

	map->width = 0;
	map->length = 0;
	map->elem = NULL;
	map->custom_color = 0;
	d = (t_d*)ft_memalloc(sizeof(t_d));
	*d = (t_d){0, 0, 10, 0, 0, 0, 1, 0, 0, 0};
	map->delta = d;
	map->project = 1;
	if (ft_strequ(av, "./maps/test_maps/1488.fdf"))
		map->special = 1;
}

void	atoi_color_and_z(char *point, char **arr, t_e *elem)
{
	int		valera;

	if (arr && !point)
	{
		!ft_isdigit_str(arr[0]) ? \
		elem->z = ft_atoi(arr[0]) : ft_error(ER02, NULL, NULL);
		((valera = ft_strlen(arr[1])) < 9 && valera > 2) ? \
		elem->color = ft_atoi_hex(arr[1]) : ft_error(ER05, NULL, NULL);
		(ft_nbrlen(elem->z) != ft_strlen(arr[0])) ? \
		ft_error(ER02, NULL, NULL) : 0;
	}
	else if (!arr && point)
	{
		!ft_isdigit_str(point) ? \
		elem->z = ft_atoi(point) : ft_error(ER02, NULL, NULL);
		(ft_nbrlen(elem->z) != ft_strlen(point)) ? \
		ft_error(ER02, NULL, NULL) : 0;
	}
}

void	free_arr(char **arr)
{
	int		i;

	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}
