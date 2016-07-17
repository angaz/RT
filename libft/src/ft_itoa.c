/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adippena <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/15 11:28:52 by adippena          #+#    #+#             */
/*   Updated: 2016/05/15 11:45:18 by adippena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	nlen(int n)
{
	unsigned int		len;

	if (n < 0)
	{
		len = 2;
		n = -n;
	}
	else
		len = 1;
	while (n /= 10)
		len++;
	return (len);
}

char		*ft_itoa(int n)
{
	unsigned int		len;
	char				*new_str;

	len = nlen(n);
	new_str = (char *)malloc(len + 1);
	if (new_str == NULL)
		return (NULL);
	if (n == 0)
		new_str[0] = '0';
	if (n < 0)
	{
		n = -n;
		new_str[0] = '-';
	}
	new_str[len--] = '\0';
	while (n)
	{
		new_str[len--] = (n % 10) + '0';
		n /= 10;
	}
	return (new_str);
}
