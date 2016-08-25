/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adippena <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/09 09:53:55 by adippena          #+#    #+#             */
/*   Updated: 2016/08/25 15:00:26 by adippena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*str;
	char	*ret;

	str = ft_strnew(ft_strlen(s) + 1);
	ret = str;
	while (*s)
		*(str++) = *(s++);
	*str = '\0';
	return (ret);
}
