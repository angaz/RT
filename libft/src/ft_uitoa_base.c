/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adippena <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/17 12:54:15 by adippena          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2016/09/01 22:24:25 by adippena         ###   ########.fr       */
=======
/*   Updated: 2016/08/26 18:47:29 by adippena         ###   ########.fr       */
>>>>>>> 30a4314a13a467cafffd81c84ca3427de211883a
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

<<<<<<< HEAD
/*static char	*my_strjoinchar(char *str, char c)
=======
static char	*my_strjoinchar(char *str, char c)
>>>>>>> 30a4314a13a467cafffd81c84ca3427de211883a
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

<<<<<<< HEAD
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
=======
	temp = NULL;
	while (value > 0)
	{
		temp = my_strjoinchar(temp, "0123456789ABCDEF"[value % base]);
>>>>>>> 30a4314a13a467cafffd81c84ca3427de211883a
		value /= base;
	}
	return (ft_strrev(str));
}
