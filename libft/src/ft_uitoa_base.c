/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adippena <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/17 12:54:15 by adippena          #+#    #+#             */
/*   Updated: 2016/08/26 18:47:29 by adippena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*my_strjoinchar(char *str, char c)
{
	char	*new;
	char	*temp;

	new = (char *)malloc(ft_strlen(str) + 2);
	temp = new;
	while (*str != '\0')
		*temp++ = *str++;
	*temp++ = c;
	*temp = '\0';
	return (new);
}

char		*ft_uitoa_base(size_t value, int base)
{
	char	*temp;

	temp = NULL;
	while (value > 0)
	{
		temp = my_strjoinchar(temp, "0123456789ABCDEF"[value % base]);
		value /= base;
	}
	return (ft_strrev(temp));
}
