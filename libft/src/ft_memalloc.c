/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adippena <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/15 11:28:55 by adippena          #+#    #+#             */
/*   Updated: 2016/05/15 11:45:25 by adippena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void			*res;
	unsigned char	*res2;

	res = malloc(size);
	res2 = res;
	if (res == NULL)
		return (NULL);
	while (size--)
		*(res2++) = 0;
	return ((void *)res);
}
