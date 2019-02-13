/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_hex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarev <skarev@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 13:35:42 by skarev            #+#    #+#             */
/*   Updated: 2019/02/13 13:35:48 by skarev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			is_digit_bace(char c)
{
	int		i;
	char	*dig = "0123456789ABCDEF";

	i = 0;
	while (i < 16)
	{
		if (dig[i] == ft_toupper(c))
			return (i);
		i++;
	}
	return (-1);
}

int			ft_atoi_hex(char *str)
{
	int		i;
	int		result;

	i = 2;
	result = 0;
	if (str[0] != '0' && (str[1] != 'x' || str[1] != 'X'))
		return (0);
	while (is_digit_bace(str[i]) >= 0)
		result = result * 16 + is_digit_bace(str[i++]);
	return (result);
}
