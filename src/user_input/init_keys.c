/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_keys.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adippena <angusdippenaar@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/29 20:08:58 by adippena          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2016/09/01 22:53:19 by adippena         ###   ########.fr       */
=======
/*   Updated: 2016/08/29 20:31:56 by adippena         ###   ########.fr       */
>>>>>>> 30a4314a13a467cafffd81c84ca3427de211883a
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

<<<<<<< HEAD
void		reset_keys(t_env *e)
{
	e->flags &= ~(KEY_G | KEY_S | KEY_R | KEY_X | KEY_Y | KEY_Z);
	SDL_SetRelativeMouseMode(0);
=======
void		init_keys(t_env *e)
{
	e->key.g = 0;
	e->key.s = 0;
	e->key.r = 0;
	e->key.x = 0;
	e->key.y = 0;
	e->key.z = 0;
	e->key.w = 0;
	e->key.s = 0;
	e->key.a = 0;
	e->key.d = 0;
	e->key.a = 0;
	e->key.ctrl = 0;
	e->key.space = 0;
	e->key.shift = 0;
	e->key.mid_click = 0;
}

void		reset_keys(t_env *e)
{
	e->key.g = 0;
	e->key.s = 0;
	e->key.r = 0;
	e->key.x = 0;
	e->key.y = 0;
	e->key.z = 0;
	SDL_SetRelativeMouseMode(0);
	SDL_SetWindowGrab(e->win, SDL_FALSE);
>>>>>>> 30a4314a13a467cafffd81c84ca3427de211883a
}
