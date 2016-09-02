/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cam_move.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arnovan- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/20 11:12:18 by arnovan-          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2016/09/01 22:52:51 by adippena         ###   ########.fr       */
=======
/*   Updated: 2016/09/01 13:35:20 by adippena         ###   ########.fr       */
>>>>>>> 30a4314a13a467cafffd81c84ca3427de211883a
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void			cam_rot(t_env *e, SDL_Event event)
{
	SDL_SetRelativeMouseMode(1);
<<<<<<< HEAD
=======
	SDL_SetWindowGrab(e->win, SDL_TRUE);
>>>>>>> 30a4314a13a467cafffd81c84ca3427de211883a
	e->camera.dir.x += (double)event.motion.xrel * 0.1;
	e->camera.dir.z -= (double)event.motion.yrel * 0.1;
	draw(e, (SDL_Rect){0, 0, e->x, e->y});
	SDL_FlushEvent(SDL_MOUSEMOTION);
}

static void		cam_move_minus(t_env *e)
{
<<<<<<< HEAD
	if (e->flags & KEY_A)
=======
	if (e->key.a)
>>>>>>> 30a4314a13a467cafffd81c84ca3427de211883a
	{
		--e->camera.loc.x;
		--e->camera.dir.x;
	}
<<<<<<< HEAD
	if (e->flags & KEY_S)
=======
	if (e->key.s)
>>>>>>> 30a4314a13a467cafffd81c84ca3427de211883a
	{
		--e->camera.loc.y;
		--e->camera.dir.y;
	}
<<<<<<< HEAD
	if (e->flags & KEY_CTRL)
=======
	if (e->key.ctrl)
>>>>>>> 30a4314a13a467cafffd81c84ca3427de211883a
	{
		--e->camera.loc.z;
		--e->camera.dir.z;
	}
}

static void		cam_move_plus(t_env *e)
{
<<<<<<< HEAD
	if (e->flags & KEY_D)
=======
	if (e->key.d)
>>>>>>> 30a4314a13a467cafffd81c84ca3427de211883a
	{
		++e->camera.loc.x;
		++e->camera.dir.x;
	}
<<<<<<< HEAD
	if (e->flags & KEY_W)
=======
	if (e->key.w)
>>>>>>> 30a4314a13a467cafffd81c84ca3427de211883a
	{
		++e->camera.loc.y;
		++e->camera.dir.y;
	}
<<<<<<< HEAD
	if (e->flags & KEY_SPACE)
=======
	if (e->key.space)
>>>>>>> 30a4314a13a467cafffd81c84ca3427de211883a
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
