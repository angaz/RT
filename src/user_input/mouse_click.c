/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_click.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arnovan- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/12 15:51:20 by arnovan-          #+#    #+#             */
/*   Updated: 2016/08/29 21:28:25 by adippena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void	reset_loc(t_env *e)
{
	size_t	index;

	index = e->prims;
	while (index--)
		if (e->prim[index]->s_bool)
			e->prim[index]->loc = e->prim[index]->loc_bak;
}

static void	click_select(t_env *e)
{
	int	x;
	int	y;

	SDL_GetMouseState(&x, &y);
	get_ray_dir(e, x, y);
	intersect_scene(e);
	if (e->p_hit)
	{
		if (!e->key.shift)
			deselect_all(e);
		if (!e->p_hit->s_bool)
		{
			e->p_hit->s_bool = 1;
			e->p_hit->loc_bak = e->p_hit->loc;
			++e->s_num;
		}
		else
		{
			e->p_hit->s_bool = 0;
			--e->s_num;
		}
	}
	else
		deselect_all(e);
}

void		click_release(t_env *e, SDL_Event event)
{
	if (event.button.button == SDL_BUTTON_MIDDLE)
	{
		SDL_SetRelativeMouseMode(0);
		SDL_SetWindowGrab(e->win, SDL_FALSE);
		e->key.mid_click = 0;
	}
}

void		mouse_click(t_env *e, SDL_Event event)
{
	if (event.button.button == SDL_BUTTON_LEFT)
	{
		if (!e->key.g)
			click_select(e);
	}
	else if (event.button.button == SDL_BUTTON_RIGHT)
	{
		if (e->key.g)
			reset_loc(e);
	}
	else if (event.button.button == SDL_BUTTON_MIDDLE)
	{
		e->key.mid_click = 1;
		SDL_SetRelativeMouseMode(0);
		SDL_SetWindowGrab(e->win, SDL_FALSE);
	}
	reset_keys(e);
	draw(e, (SDL_Rect){0, 0, e->x, e->y});
}
