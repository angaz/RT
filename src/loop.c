/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adippena <angusdippenaar@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/08 20:00:24 by adippena          #+#    #+#             */
/*   Updated: 2016/09/01 22:34:49 by adippena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void	event_keydown(t_env *e, SDL_Keycode key)
{
	if (key == SDLK_ESCAPE)
		exit_rt(e, 0);
	else if (key == SDLK_d && !(e->keys & KEY_MID_CLICK))
		draw(e, (SDL_Rect){0, 0, e->x, e->y});
	else if (key == SDLK_e && !(e->keys & KEY_MID_CLICK))
		export(e);
	else if (key == SDLK_s && !(e->keys & KEY_MID_CLICK))
		save(e);
	else if (!e->objects && e->keys & KEY_MID_CLICK)
		mkey_press(e, key);
	else if (!e->objects && !(e->keys & KEY_MID_CLICK))
		key_press(e, key);
}

static void	event_poll(t_env *e)
{
	SDL_Event	event;

	while (SDL_PollEvent(&event))
	{
		if (event.type == SDL_QUIT)
			exit_rt(e, 0);
		else if (event.type == SDL_WINDOWEVENT_EXPOSED)
			SDL_UpdateWindowSurface(e->win);
		else if (event.type == SDL_KEYDOWN && event.key.repeat == 0)
			event_keydown(e, event.key.keysym.sym);
		else if (event.type == SDL_KEYUP && event.key.repeat == 0)
			key_release(e, event.key.keysym.sym);
		else if (event.type == SDL_MOUSEBUTTONUP && !e->objects)
			click_release(e, event);
		else if (event.type == SDL_MOUSEBUTTONDOWN && !e->objects)
			mouse_click(e, event.button.button);
		else if (e->keys & KEY_MID_CLICK && !e->s_num)
			(event.type == SDL_MOUSEMOTION) ? cam_rot(e, event) : 0;
		(e->keys & KEY_MID_CLICK) ? cam_move(e) : 0;
		if (e->keys & KEY_G && event.type == SDL_MOUSEMOTION)
			grab(e, event);
		if (e->keys & KEY_G && event.type == SDL_MOUSEWHEEL)
			m_wheel(e, event);
	}
}

void		event_loop(t_env *e)
{
	while (42)
	{
		event_poll(e);
		SDL_Delay(16);
	}
}
