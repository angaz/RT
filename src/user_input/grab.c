/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grab.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arnovan- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/15 17:07:36 by arnovan-          #+#    #+#             */
/*   Updated: 2016/09/02 15:37:31 by adippena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	m_wheel(t_env *e, SDL_Event event)
{
	size_t index;

	if (e->s_num)
	{
		index = e->prims;
		while (index--)
			if (e->prim[index]->s_bool)
				e->prim[index]->loc.y -= (double)event.wheel.y * 0.5;
		SDL_FlushEvent(SDL_MOUSEWHEEL);
		draw(e, (SDL_Rect){0, 0, e->x, e->y});
	}
}

void	grab(t_env *e, SDL_Event event)
{
	size_t	index;

	SDL_SetRelativeMouseMode(1);
	if (e->s_num)
	{
		index = e->prims;
		while (index--)
			if (e->prim[index]->s_bool)
			{
				e->prim[index]->loc.x += (double)event.motion.xrel * 0.015;
				e->prim[index]->loc.z -= (double)event.motion.yrel * 0.015;
			}
		SDL_FlushEvent(SDL_MOUSEMOTION);
		draw(e, (SDL_Rect){0, 0, e->x, e->y});
	}
}

void	deselect_all(t_env *e)
{
	size_t	index;

	if (e->s_num)
	{
		index = e->prims;
		while (index--)
			e->prim[index]->s_bool = 0;
	}
	e->s_num = 0;
}

void	select_all(t_env *e)
{
	size_t	index;

	index = e->prims;
	while (index--)
	{
		e->prim[index]->s_bool = 1;
		e->prim[index]->loc_bak = e->prim[index]->loc;
	}
	e->s_num = e->prims;
}
