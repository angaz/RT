/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adippena <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/17 12:54:15 by adippena          #+#    #+#             */
/*   Updated: 2016/09/01 22:24:25 by adippena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*static char	*my_strjoinchar(char *str, char c)
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
}*/

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
		*temp++ = "0123456789ABCDEF"[value % base];
		*temp = '\0';
		ft_strdel(&str_backup);
		str = new;
		value /= base;
	}
	return (ft_strrev(str));
}
