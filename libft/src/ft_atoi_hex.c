/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adippena <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/15 11:28:00 by adippena          #+#    #+#             */
/*   Updated: 2016/07/17 12:54:04 by adippena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi_hex(const char *nptr)
{
	size_t		res;
	size_t		i;

	res = 0;
	i = 0;
	while (ft_isdigit(nptr[i]) ||
		(ft_toupper(nptr[i] >= 'A' && ft_toupper(nptr[i]) <= 'F')))
	{
		res *= 16;
		if (nptr[i] < 'A')
			res += (nptr[i++] - '0');
		else
			res += (10 + (nptr[i++] - 'A'));
	}
	return (res);
}
