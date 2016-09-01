/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   half_bytes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adippena <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/01 13:17:39 by adippena          #+#    #+#             */
/*   Updated: 2016/09/01 13:18:29 by adippena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		half_bytes(SDL_Surface *s)
{
	size_t			index;
	unsigned char	*px;

	index = s->h * s->pitch;
	px = (unsigned char *)(s->pixels + index - 1);
	while (index--)
		*px-- >>= 1;
}
