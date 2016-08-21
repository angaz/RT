/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cam_move.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arnovan- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/20 11:12:18 by arnovan-          #+#    #+#             */
/*   Updated: 2016/08/21 14:23:48 by arnovan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	cam_rot(t_env *e, SDL_Event event)
{
	SDL_SetRelativeMouseMode(1);
	e->camera.dir.x += (double)event.motion.xrel * 0.01;
	e->camera.dir.z -= (double)event.motion.yrel * 0.01;
	draw(e, (SDL_Rect){0, 0, WIN_X, WIN_Y});
}

void	cam_move(t_env *e)
{
	if (e->key.w == 1)
		e->camera.loc.y += 1;
	if (e->key.s == 1)
		e->camera.loc.y -= 1;
	if (e->key.a == 1)
		e->camera.loc.x -= 1;
	if (e->key.d == 1)
		e->camera.loc.x += 1;
	if (e->key.space == 1)
		e->camera.loc.z += 1;
	if (e->key.ctrl == 1)
		e->camera.loc.z -= 1;
	draw(e, (SDL_Rect){0, 0, WIN_X, WIN_Y});
}
