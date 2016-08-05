/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adippena <angusdippenaar@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/14 21:37:20 by adippena          #+#    #+#             */
/*   Updated: 2016/07/14 22:32:35 by adippena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static double	get_fraction(const char *nptr)
{
	double	res;

	res = 0.0;
	if (*nptr == '.' || *nptr == ',')
	{
		++nptr;
		while (ft_isdigit(*nptr))
		{
			res *= 10;
			res += *(nptr++) - '0';
		}
		while (res > 1)
			res /= 10;
	}
	return (res);
}

static double	get_double(const char *nptr)
{
	double	res;

	res = 0.0;
	while (ft_isdigit(*nptr))
	{
		res *= 10;
		res += *(nptr++) - '0';
	}
	res += get_fraction(nptr);
	return (res);
}

double			ft_atod(const char *nptr)
{
	double	res;
	int		neg;

	neg = 1;
	if (nptr[0] == '-')
		++nptr;
	else
		neg = 0;
	if (nptr[0] == '+')
		++nptr;
	res = get_double(nptr);
	if (neg)
		res = -res;
	return (res);
}
