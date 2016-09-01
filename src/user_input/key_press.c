/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arnovan- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/12 15:44:46 by arnovan-          #+#    #+#             */
/*   Updated: 2016/09/01 20:24:56 by adippena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		key_release(t_env *e, SDL_Keycode key)
{
	if (key == SDLK_LSHIFT)
		e->keys &= ~KEY_SHIFT;
	else if (key == SDLK_LCTRL)
		e->keys &= ~KEY_CTRL;
	else if (key == SDLK_SPACE)
		e->keys &= ~KEY_SPACE;
	else if (key == SDLK_w)
		e->keys &= ~KEY_W;
	else if (key == SDLK_s)
		e->keys &= ~KEY_S;
	else if (key == SDLK_a)
		e->keys &= ~KEY_A;
	else if (key == SDLK_d)
		e->keys &= ~KEY_D;
}

static void	key_press_a(t_env *e)
{
	if (e->s_num)
	{
		ft_putstr("Deselecting all primitives\n");
		deselect_all(e);
	}
	else
	{
		ft_putstr("Selecting all primitives\n");
		select_all(e);
	}
	draw(e, (SDL_Rect){0, 0, e->x, e->y});
}

void		key_press(t_env *e, SDL_Keycode key)
{
	if (key == SDLK_LSHIFT)
		e->keys |= KEY_SHIFT;
	else if (e->s_num && key == SDLK_g)
	{
		e->key.g = 1;
		SDL_SetRelativeMouseMode(1);
		draw(e, (SDL_Rect){0, 0, e->x, e->y});
	}
	else if (!(e->keys & KEY_G) && key == SDLK_a)
		key_press_a(e);
	else if (key == SDLK_s)
		e->keys ^= KEY_S;
	else if (key == SDLK_r)
		e->keys ^= KEY_R;
	else if (key == SDLK_x)
		e->keys ^= KEY_X;
	else if (key == SDLK_y)
		e->keys ^= KEY_Y;
	else if (key == SDLK_z)
		e->keys ^= KEY_Z;
}

void		mkey_press(t_env *e, SDL_Keycode key)
{
	if (key == SDLK_LCTRL)
		e->keys |= KEY_CTRL;
	else if (key == SDLK_SPACE)
		e->keys |= KEY_SPACE;
	else if (key == SDLK_w)
		e->keys |= KEY_W;
	else if (key == SDLK_s)
		e->keys |= KEY_S;
	else if (key == SDLK_a)
		e->keys |= KEY_A;
	else if (key == SDLK_d)
		e->keys |= KEY_D;
}
