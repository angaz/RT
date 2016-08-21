/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adippena <angusdippenaar@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/08 20:00:24 by adippena          #+#    #+#             */
/*   Updated: 2016/08/21 14:41:50 by arnovan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void	event_poll(t_env *e)
{
	SDL_Event	event;

	while (SDL_PollEvent(&event))
	{
		if (event.type == SDL_QUIT)
			exit_rt(e, 0);
		else if (event.type == SDL_KEYDOWN && event.key.repeat == 0)
		{
			if (event.key.keysym.sym == SDLK_ESCAPE)
				exit_rt(e, 0);
			else if (event.key.keysym.sym == SDLK_d && e->key.mid_click == 0)
				draw(e, (SDL_Rect){0, 0, WIN_X, WIN_Y});
			else if (e->objects == 0 && e->key.mid_click == 1)
				mkey_press(e, event);
			else if (e->objects == 0 && e->key.mid_click == 0)
				key_press(e, event);
		}
		else if (event.type == SDL_KEYUP && event.key.repeat == 0)
			key_release(e, event);
		else if (event.type == SDL_MOUSEBUTTONUP && e->objects == 0)
			click_release(e, event);
		else if (event.type == SDL_MOUSEBUTTONDOWN && e->objects == 0)
			mouse_click(e, event);
		else if (e->key.mid_click == 1 && e->objects == 0)
			event.type == SDL_MOUSEMOTION ? cam_rot(e, event) : 0;
		e->key.mid_click == 1 ? cam_move(e) : 0;
		(e->key.g == 1 && event.type == SDL_MOUSEMOTION) ? grab(e, event) : 0;
		(e->key.g == 1 && event.type == SDL_MOUSEWHEEL) ? m_wheel(e, event) : 0;
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
