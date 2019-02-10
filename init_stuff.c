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

void	init_map(t_m *map)
{
	t_d		*d;

	map->width = 0;
	map->length = 0;
	map->elem = NULL;
	d = (t_d*)ft_memalloc(sizeof(t_d));
	*d = (t_d){0, 0, 0.1, 0, 0, 0, 1, 0};
	map->delta = d;
	map->project = 1;
}