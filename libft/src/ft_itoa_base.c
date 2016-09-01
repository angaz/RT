/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/15 16:52:59 by rojones           #+#    #+#             */
/*   Updated: 2016/09/01 13:34:46 by adippena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_numlen(int num, int base)
{
	int re;

	re = 0;
	if (num == 0)
		return (1);
	if (num < 0 && base == 10)
		re++;
	while (num != 0)
	{
		re++;
		num /= base;
	}
	return (re);
}

char		*ft_itoa_base(int value, int base)
{
	char	*rep;
	char	*re;
	int		size;
	int		sign;

	sign = 1;
	size = ft_numlen(value, base);
	rep = "0123456789ABCDEF";
	if (value < 0)
		sign = -1;
	if (!(re = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	re[size--] = '\0';
	if (value == 0)
		re[0] = '0';
	while (value != 0)
	{
		re[size--] = rep[sign * (value % base)];
		value /= base;
	}
	if (sign == -1 && base == 10)
		re[0] = '-';
	return (re);
}
