/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arnovan- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/12 15:44:46 by arnovan-          #+#    #+#             */
/*   Updated: 2016/08/19 18:05:29 by arnovan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

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
	if (event.key.keysym.sym == SDLK_LSHIFT ||
			event.key.keysym.sym == SDLK_RSHIFT)
	{
		e->key.shift = 0;
		printf("shift: %i\n", e->key.shift);
	}
}

void		key_press(t_env *e, SDL_Event event)
{
	if (event.key.keysym.sym == SDLK_LSHIFT ||
			event.key.keysym.sym == SDLK_RSHIFT)
	{
		e->key.shift = 1;
		printf("shift: %i\n", e->key.shift);
	}
	else if (event.key.keysym.sym == SDLK_g && e->s_num > 0)
		e->key.g = 1;
	else if (event.key.keysym.sym == SDLK_a && e->key.g == 0)
	{
		if (e->s_num == 0)
			select_all(e);
		else
			deselect(e);
		draw(e, (SDL_Rect){0, 0, WIN_X, WIN_Y});
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
