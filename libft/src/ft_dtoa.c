/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dtoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/15 12:59:46 by rojones           #+#    #+#             */
/*   Updated: 2016/08/16 08:25:21 by rojones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_pow(int num, int pow)
{
	int	i;
	int	re;

	i = 0;
	re = 1;
	while (i < pow)
	{
		i++;
		re *= num;
	}
	return (re);
}

char		*ft_dtoa(double n, int num_place)
{
	char		*left;
	char		*right;
	char		*temp;
	char		*new_str;

	left = ft_itoa((int)(n));
	right = ft_itoa(ABS((int)((n - (int)(n)) * ft_pow(10, num_place))));
	temp = ft_strjoin(left, ".");
	new_str = ft_strjoin(temp, right);
	free(temp);
	free(left);
	free(right);
	return (new_str);
}
