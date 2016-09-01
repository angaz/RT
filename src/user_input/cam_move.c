/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cam_move.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arnovan- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/20 11:12:18 by arnovan-          #+#    #+#             */
/*   Updated: 2016/09/01 23:54:02 by adippena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void			cam_rot(t_env *e, SDL_Event event)
{
	SDL_SetRelativeMouseMode(1);
	e->camera.dir.x += (double)event.motion.xrel * 0.1;
	e->camera.dir.z -= (double)event.motion.yrel * 0.1;
	draw(e, (SDL_Rect){0, 0, e->x, e->y});
	SDL_FlushEvent(SDL_MOUSEMOTION);
}

static void		cam_move_minus(t_env *e)
{
	if (e->flags & KEY_A)
	{
		--e->camera.loc.x;
		--e->camera.dir.x;
	}
	if (e->flags & KEY_S)
	{
		--e->camera.loc.y;
		--e->camera.dir.y;
	}
	if (e->flags & KEY_CTRL)
	{
		--e->camera.loc.z;
		--e->camera.dir.z;
	}
}

static void		cam_move_plus(t_env *e)
{
	if (e->flags & KEY_D)
	{
		++e->camera.loc.x;
		++e->camera.dir.x;
	}
	if (e->flags & KEY_W)
	{
		++e->camera.loc.y;
		++e->camera.dir.y;
	}
	if (e->flags & KEY_SPACE)
	{
		++e->camera.loc.z;
		++e->camera.dir.z;
	}
}

void			cam_move(t_env *e)
{
	cam_move_plus(e);
	cam_move_minus(e);
	draw(e, (SDL_Rect){0, 0, e->x, e->y});
}
