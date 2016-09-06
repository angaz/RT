/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adippena <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/17 12:54:15 by adippena          #+#    #+#             */
/*   Updated: 2016/09/05 12:10:04 by adippena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_uitoa_base(size_t value, int base)
{
	char	*temp;
	char	*str;
	char	*new;
	char	*str_backup;

	str = NULL;
	while (value)
	{
		new = ft_strnew(ft_strlen(str) + 2);
		temp = new;
		str_backup = str;
		if (str)
			while (*str)
				*temp++ = *str++;
		*temp++ = "0123456789abcdef"[value % base];
		*temp = '\0';
		ft_strdel(&str_backup);
		str = new;
		value /= base;
	}
	return (ft_strrev(str));
}
