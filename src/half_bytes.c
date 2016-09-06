/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   half_bytes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adippena <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/01 13:17:39 by adippena          #+#    #+#             */
/*   Updated: 2016/09/03 15:17:43 by adippena         ###   ########.fr       */
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

void		blend(SDL_Surface *s1, SDL_Surface *s2)
{
	size_t			index;
	unsigned char	*px1;
	unsigned char	*px2;

	index = s1->h * s1->pitch;
	px1 = (unsigned char *)(s1->pixels + index - 1);
	px2 = (unsigned char *)(s2->pixels + index - 1);
	while (index--)
	{
		*px1 = (*px1 + *px2) * 0.5;
		--px1;
		--px2;
	}
}
