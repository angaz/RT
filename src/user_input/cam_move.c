/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cam_move.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arnovan- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/20 11:12:18 by arnovan-          #+#    #+#             */
/*   Updated: 2016/08/29 20:23:47 by adippena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	cam_rot(t_env *e, SDL_Event event)
{
	SDL_SetRelativeMouseMode(1);
	SDL_SetWindowGrab(e->win, SDL_TRUE);
	e->camera.dir.x += (double)event.motion.xrel * 0.01;
	e->camera.dir.z -= (double)event.motion.yrel * 0.01;
	draw(e, (SDL_Rect){0, 0, e->x, e->y});
	SDL_FlushEvent(SDL_MOUSEMOTION);
}

static void		cam_move_minus(t_env *e)
{
	if (e->key.a)
	{
		--e->camera.loc.x;
		--e->camera.dir.x;
	}
	if (e->key.s)
	{
		--e->camera.loc.y;
		--e->camera.dir.y;
	}
	if (e->key.ctrl)
	{
		--e->camera.loc.z;
		--e->camera.dir.z;
	}
}

static void		cam_move_plus(t_env *e)
{
	if (e->key.d)
	{
		++e->camera.loc.x;
		++e->camera.dir.x;
	}
	if (e->key.w)
	{
		++e->camera.loc.y;
		++e->camera.dir.y;
	}
	if (e->key.space)
	{
		++e->camera.loc.z;
		++e->camera.dir.z;
	}
}

void	cam_move(t_env *e)
{
	cam_move_plus(e);
	cam_move_minus(e);
	draw(e, (SDL_Rect){0, 0, e->x, e->y});
}
