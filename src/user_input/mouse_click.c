/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_click.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arnovan- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/12 15:51:20 by arnovan-          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2016/09/01 22:59:40 by adippena         ###   ########.fr       */
=======
/*   Updated: 2016/08/29 21:28:25 by adippena         ###   ########.fr       */
>>>>>>> 30a4314a13a467cafffd81c84ca3427de211883a
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
<<<<<<< HEAD
		if (!(e->flags & KEY_SHIFT))
=======
		if (!e->key.shift)
>>>>>>> 30a4314a13a467cafffd81c84ca3427de211883a
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
<<<<<<< HEAD
		e->flags &= ~KEY_MID_CLICK;
	}
}

void		mouse_click(t_env *e, uint8_t button)
{
	if (button == SDL_BUTTON_LEFT)
	{
		if (!(e->flags & KEY_G))
			click_select(e);
	}
	else if (button == SDL_BUTTON_RIGHT)
	{
		if (e->flags & KEY_G)
			reset_loc(e);
	}
	else if (button == SDL_BUTTON_MIDDLE)
	{
		e->flags |= KEY_MID_CLICK;
		SDL_SetRelativeMouseMode(0);
=======
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
>>>>>>> 30a4314a13a467cafffd81c84ca3427de211883a
	}
	reset_keys(e);
	draw(e, (SDL_Rect){0, 0, e->x, e->y});
}
