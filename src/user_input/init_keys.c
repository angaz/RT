/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_keys.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adippena <angusdippenaar@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/29 20:08:58 by adippena          #+#    #+#             */
/*   Updated: 2016/09/01 22:31:29 by adippena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

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
/*
	e->key.g = 0;
	e->key.s = 0;
	e->key.r = 0;
	e->key.x = 0;
	e->key.y = 0;
	e->key.z = 0; */
	if (e->keys & KEY_G)
		printf("KEY G\n");
	e->keys &= ~(KEY_G | KEY_S | KEY_R | KEY_X | KEY_Y | KEY_Z);
	SDL_SetRelativeMouseMode(0);
}
