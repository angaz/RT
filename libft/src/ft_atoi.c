/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adippena <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/15 11:28:00 by adippena          #+#    #+#             */
/*   Updated: 2016/05/15 11:44:04 by adippena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	long int	res;
	size_t		i;
	int			neg;

	res = 0;
	i = 0;
	neg = 0;
	if (nptr[0] == '-')
	{
		neg = 1;
		++i;
	}
	if (nptr[0] == '+')
		++i;
	while ((nptr[i] >= '0') && (nptr[i] <= '9'))
	{
		res *= 10;
		res += (nptr[i++] - '0');
	}
	if (neg)
		res = -res;
	return ((int)res);
}
