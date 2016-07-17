/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adippena <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/15 11:28:52 by adippena          #+#    #+#             */
/*   Updated: 2016/07/17 12:54:39 by adippena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	nlen(size_t n)
{
	size_t	len;

	len = 1;
	while (n /= 10)
		len++;
	return (len);
}

char			*ft_uitoa(size_t n)
{
	size_t	len;
	char	*new_str;

	len = nlen(n);
	new_str = (char *)malloc(len + 1);
	if (new_str == NULL)
		return (NULL);
	if (n == 0)
		new_str[0] = '0';
	new_str[len--] = '\0';
	while (n)
	{
		new_str[len--] = (n % 10) + '0';
		n /= 10;
	}
	return (new_str);
}
