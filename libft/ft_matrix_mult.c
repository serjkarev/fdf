/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrix_mult.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarev <skarev@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 14:30:06 by skarev            #+#    #+#             */
/*   Updated: 2019/02/06 14:30:06 by skarev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		*ft_matrix_mult(int *m1, int m2[3][3])
{
	int		i;
	int		j;
	int		*out;

	i = 0;
	out = (int*)ft_memalloc(sizeof(int) * 3);
	while (i < 3)
	{
		j = 0;
		while (j < 3)
		{
			out[i] += m1[j] * m2[j][i];
			j++;
		}
		i++;
	}
	return (out);
}