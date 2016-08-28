/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arnovan- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/12 15:44:46 by arnovan-          #+#    #+#             */
/*   Updated: 2016/08/28 21:28:31 by adippena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		init_keys(t_env *e)
{
	e->key.g = 0;
	e->key.s = 0;
	e->key.r = 0;
	e->key.x = 0;
	e->key.y = 0;
	e->key.z = 0;
	e->key.w = 0;
	e->key.s = 0;
	e->key.a = 0;
	e->key.d = 0;
	e->key.a = 0;
	e->key.ctrl = 0;
	e->key.space = 0;
	e->key.mid_click = 0;
}

void		reset_keys(t_env *e)
{
	e->key.g = 0;
	e->key.s = 0;
	e->key.r = 0;
	e->key.x = 0;
	e->key.y = 0;
	e->key.z = 0;
}

void		key_release(t_env *e, SDL_Event event)
{
	if (event.key.keysym.sym == SDLK_LSHIFT)
		e->key.shift = 0;
	else if (event.key.keysym.sym == SDLK_LCTRL)
		e->key.ctrl = 0;
	else if (event.key.keysym.sym == SDLK_KP_SPACE)
		e->key.space = 0;
	else if (event.key.keysym.sym == SDLK_w)
		e->key.w = 0;
	else if (event.key.keysym.sym == SDLK_s)
		e->key.s = 0;
	else if (event.key.keysym.sym == SDLK_a)
		e->key.a = 0;
	else if (event.key.keysym.sym == SDLK_d)
		e->key.d = 0;
}

void		key_press(t_env *e, SDL_Event event)
{
	if (event.key.keysym.sym == SDLK_LSHIFT)
		e->key.shift = 1;
	else if (e->s_num && event.key.keysym.sym == SDLK_g)
	{
		e->key.g = 1;
		draw(e, (SDL_Rect){0, 0, e->x, e->y});
	}
	else if (!e->key.g && event.key.keysym.sym == SDLK_a)
	{
		(e->s_num) ? deselect_all(e) : select_all(e);
		draw(e, (SDL_Rect){0, 0, e->x, e->y});
	}
	else if (event.key.keysym.sym == SDLK_s)
		e->key.s = (e->key.s == 1) ? 0 : 1;
	else if (event.key.keysym.sym == SDLK_r)
		e->key.r = (e->key.r == 1) ? 0 : 1;
	else if (event.key.keysym.sym == SDLK_x)
		e->key.x = (e->key.x == 1) ? 0 : 1;
	else if (event.key.keysym.sym == SDLK_y)
		e->key.y = (e->key.y == 1) ? 0 : 1;
	else if (event.key.keysym.sym == SDLK_z)
		e->key.z = (e->key.z == 1) ? 0 : 1;
}

void		mkey_press(t_env *e, SDL_Event event)
{
	if (event.key.keysym.sym == SDLK_LCTRL)
		e->key.ctrl = 1;
	else if (event.key.keysym.sym == SDLK_KP_SPACE)
		e->key.space = 1;
	else if (event.key.keysym.sym == SDLK_w)
		e->key.w = 1;
	else if (event.key.keysym.sym == SDLK_s)
		e->key.s = 1;
	else if (event.key.keysym.sym == SDLK_a)
		e->key.a = 1;
	else if (event.key.keysym.sym == SDLK_d)
		e->key.d = 1;
}
