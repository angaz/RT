/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adippena <angusdippenaar@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/08 20:00:24 by adippena          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2016/09/01 22:58:50 by adippena         ###   ########.fr       */
=======
/*   Updated: 2016/08/31 21:00:12 by adippena         ###   ########.fr       */
>>>>>>> 30a4314a13a467cafffd81c84ca3427de211883a
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

<<<<<<< HEAD
static void	event_keydown(t_env *e, SDL_Keycode key)
{
	if (key == SDLK_ESCAPE)
		exit_rt(e, 0);
	else if (key == SDLK_d && !(e->flags & KEY_MID_CLICK))
		draw(e, (SDL_Rect){0, 0, e->x, e->y});
	else if (key == SDLK_e && !(e->flags & KEY_MID_CLICK))
		export(e);
	else if (key == SDLK_s && !(e->flags & KEY_MID_CLICK))
		save(e);
	else if (!e->objects && e->flags & KEY_MID_CLICK)
		mkey_press(e, key);
	else if (!e->objects && !(e->flags & KEY_MID_CLICK))
		key_press(e, key);
=======
static void	event_keydown(t_env *e, SDL_Event *event)
{
	if (event->key.keysym.sym == SDLK_ESCAPE)
		exit_rt(e, 0);
	else if (event->key.keysym.sym == SDLK_d && !e->key.mid_click)
		draw(e, (SDL_Rect){0, 0, e->x, e->y});
	else if (event->key.keysym.sym == SDLK_e && !e->key.mid_click)
		export(e);
	else if (event->key.keysym.sym == SDLK_s && !e->key.mid_click)
		save(e);
	else if (!e->objects && e->key.mid_click)
		mkey_press(e, *event);
	else if (!e->objects && !e->key.mid_click)
		key_press(e, *event);
>>>>>>> 30a4314a13a467cafffd81c84ca3427de211883a
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
<<<<<<< HEAD
			event_keydown(e, event.key.keysym.sym);
		else if (event.type == SDL_KEYUP && event.key.repeat == 0)
			key_release(e, event.key.keysym.sym);
		else if (event.type == SDL_MOUSEBUTTONUP && !e->objects)
			click_release(e, event);
		else if (event.type == SDL_MOUSEBUTTONDOWN && !e->objects)
			mouse_click(e, event.button.button);
		else if (e->flags & KEY_MID_CLICK && !e->s_num)
			(event.type == SDL_MOUSEMOTION) ? cam_rot(e, event) : 0;
		(e->flags & KEY_MID_CLICK) ? cam_move(e) : 0;
		if (e->flags & KEY_G && event.type == SDL_MOUSEMOTION)
			grab(e, event);
		if (e->flags & KEY_G && event.type == SDL_MOUSEWHEEL)
			m_wheel(e, event);
=======
			event_keydown(e, &event);
		else if (event.type == SDL_KEYUP && event.key.repeat == 0)
			key_release(e, event);
		else if (event.type == SDL_MOUSEBUTTONUP && !e->objects)
			click_release(e, event);
		else if (event.type == SDL_MOUSEBUTTONDOWN && !e->objects)
			mouse_click(e, event);
		else if (e->key.mid_click && !e->s_num)
			(event.type == SDL_MOUSEMOTION) ? cam_rot(e, event) : 0;
		(e->key.mid_click) ? cam_move(e) : 0;
		(e->key.g && event.type == SDL_MOUSEMOTION) ? grab(e, event) : 0;
		(e->key.g && event.type == SDL_MOUSEWHEEL) ? m_wheel(e, event) : 0;
>>>>>>> 30a4314a13a467cafffd81c84ca3427de211883a
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
