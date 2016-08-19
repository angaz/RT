/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grab.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arnovan- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/15 17:07:36 by arnovan-          #+#    #+#             */
/*   Updated: 2016/08/19 18:09:06 by arnovan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void 	mouse_wheel(t_env *e, SDL_Event event)
{
	size_t index;

	if (e->s_num > 0)
	{
		index = e->s_num;
		while (index > 0)
		{
			e->selected[index]->loc.y -= (double)event.wheel.y * 0.05;
			draw(e, (SDL_Rect){0, 0, WIN_X, WIN_Y});
			index--;
		}
	}
}

void	grab(t_env *e, SDL_Event event)
{
	size_t index;

	SDL_SetRelativeMouseMode(1);
	if (e->s_num > 0)
	{
		index = e->s_num;
		while (index > 0)
		{
			draw(e, (SDL_Rect){0, 0, WIN_X, WIN_Y});
			e->selected[index]->loc.x += (double)event.motion.xrel * 0.015;
			e->selected[index]->loc.z -= (double)event.motion.yrel * 0.015;
			draw(e, (SDL_Rect){0, 0, WIN_X, WIN_Y});
			index--;
		}
	}
}

void	deselect(t_env *e)
{
	if (e->s_num > 0)
	{
		while (e->s_num > 0)
		{
			e->selected[e->s_num]->s_bool = 0;
			e->selected[e->s_num]->loc_bak = (t_vector){0.0, 0.0, 0.0};
			e->selected[e->s_num]= NULL;
			e->s_num--;
		}
	}
}

void	select_all(t_env *e)
{
	int	index;

	deselect(e);
	e->s_num = 0;
	index = 0;
	while (e->s_num < e->prims)
	{
		e->s_num++;
		e->selected[e->s_num] = e->prim[index];
		e->selected[e->s_num]->s_bool = 1;
		e->selected[e->s_num]->loc_bak = e->selected[e->s_num]->loc;
		index++;
	}
}
