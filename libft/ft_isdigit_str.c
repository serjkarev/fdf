/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarev <skarev@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/17 14:09:56 by skarev            #+#    #+#             */
/*   Updated: 2019/02/17 14:09:56 by skarev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isdigit_str(char *str)
{
	int		i;
	int		d;

	i = 0;
	d = 0;
	if (str[i] == '-' && ft_isdigit(str[i + 1]))
	{
		i++;
		d++;
	}
	while (str[i])
	{
		if (ft_isdigit(str[i]))
			d++;
		i++;
	}
	return (i - d);
}
