/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adippena <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/15 11:30:27 by adippena          #+#    #+#             */
/*   Updated: 2016/07/16 16:50:15 by adippena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*str;
	char	*str2;

	str = malloc(size);
	if (str == NULL)
		return (NULL);
	str2 = str;
	while (size--)
		*str2++ = '\0';
	return (str);
}
