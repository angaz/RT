/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cam_transforms.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arnovan- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/20 11:12:18 by arnovan-          #+#    #+#             */
/*   Updated: 2016/08/20 16:35:18 by arnovan-         ###   ########.fr       */
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
	if (e->key.up == 1)
		e->camera.loc.y += 1;
	if (e->key.down == 1)
		e->camera.loc.y -= 1;
	if (e->key.left == 1)
		e->camera.loc.x -= 1;
	if (e->key.right == 1)
		e->camera.loc.x += 1;
	if (e->key.space == 1)
		e->camera.loc.z += 1;
	if (e->key.ctrl == 1)
		e->camera.loc.z -= 1;
}
