/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_click.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arnovan- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/12 15:51:20 by arnovan-          #+#    #+#             */
/*   Updated: 2016/08/21 14:37:57 by arnovan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void	reset_loc(t_env *e)
{
	size_t	index;

	index = e->s_num;
	while (index > 0)
	{
		e->selected[index]->loc = e->selected[index]->loc_bak;
		index--;
	}
}

static void	click_select(t_env *e)
{
	t_env	*mouse;

	mouse = copy_env(e);
	setup_camera_plane(mouse, &e->click.ray_cam);
	SDL_GetMouseState(&e->click.mouse_x, &e->click.mouse_y);
	get_ray_dir(mouse, &e->click.ray_cam, e->click.mouse_x, e->click.mouse_y);
	intersect_scene(mouse);
	if (mouse->p_hit != NULL)
	{
		if (e->key.shift == 0 || (mouse->p_hit == e->selected[e->s_num]))
			deselect_all(e);
		if (mouse->p_hit->s_bool == 0)
		{
			e->s_num++;
			mouse->p_hit->s_bool = 1;
			e->selected[e->s_num] = mouse->p_hit;
			e->selected[e->s_num]->loc_bak = e->selected[e->s_num]->loc;
		}
		else
			mouse->p_hit->s_bool = 0;
	}
	else if (!mouse->p_hit && e->s_num > 0)
		deselect_all(e);
	free(mouse);
}

void		click_release(t_env *e, SDL_Event event)
{
	if (event.button.button == SDL_BUTTON_MIDDLE)
	{
		e->key.mid_click = 0;
		SDL_SetRelativeMouseMode(0);
	}
}

void		mouse_click(t_env *e, SDL_Event event)
{
	SDL_SetRelativeMouseMode(0);
	if (event.button.button == SDL_BUTTON_LEFT && e->key.g == 0)
	{
		click_select(e);
	}
	else if (event.button.button == SDL_BUTTON_RIGHT)
	{
		if (e->key.g == 1)
			reset_loc(e);
	}
	else if (event.button.button == SDL_BUTTON_MIDDLE)
	{
		e->key.mid_click = 1;
	}
	reset_keys(e);
	draw(e, (SDL_Rect){0, 0, WIN_X, WIN_Y});
}
