/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arnovan- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/12 15:44:46 by arnovan-          #+#    #+#             */
/*   Updated: 2016/08/29 20:33:10 by adippena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		key_release(t_env *e, SDL_Event event)
{
	if (event.key.keysym.sym == SDLK_LSHIFT)
		e->key.shift = 0;
	else if (event.key.keysym.sym == SDLK_LCTRL)
		e->key.ctrl = 0;
	else if (event.key.keysym.sym == SDLK_SPACE)
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

static void	key_press_a(t_env *e)
{
	if (e->s_num)
	{
		ft_putstr("Deselecting all primitives\n");
		deselect_all(e);
	}
	else
	{
		ft_putstr("Selecting all primitives\n");
		select_all(e);
	}
	draw(e, (SDL_Rect){0, 0, e->x, e->y});
}

void		key_press(t_env *e, SDL_Event event)
{
	if (event.key.keysym.sym == SDLK_LSHIFT)
		e->key.shift = 1;
	else if (e->s_num && event.key.keysym.sym == SDLK_g)
	{
		e->key.g = 1;
		SDL_SetRelativeMouseMode(1);
		SDL_SetWindowGrab(e->win, SDL_TRUE);
		draw(e, (SDL_Rect){0, 0, e->x, e->y});
	}
	else if (!e->key.g && event.key.keysym.sym == SDLK_a)
		key_press_a(e);
	else if (event.key.keysym.sym == SDLK_s)
		e->key.s = !e->key.s;
	else if (event.key.keysym.sym == SDLK_r)
		e->key.r = !e->key.r;
	else if (event.key.keysym.sym == SDLK_x)
		e->key.x = !e->key.x;
	else if (event.key.keysym.sym == SDLK_y)
		e->key.y = !e->key.y;
	else if (event.key.keysym.sym == SDLK_z)
		e->key.z = !e->key.z;
}

void		mkey_press(t_env *e, SDL_Event event)
{
	if (event.key.keysym.sym == SDLK_LCTRL)
		e->key.ctrl = 1;
	else if (event.key.keysym.sym == SDLK_SPACE)
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
