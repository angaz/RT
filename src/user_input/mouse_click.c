/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_click.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arnovan- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/12 15:51:20 by arnovan-          #+#    #+#             */
/*   Updated: 2016/08/28 22:04:34 by adippena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void	reset_loc(t_env *e)
{
	size_t	index;

	index = e->s_num;
	while (index--)
		e->selected[index]->loc = e->selected[index]->loc_bak;
}

static void	click_select(t_env *e)
{
	t_env	*mouse;

	mouse = copy_env(e);
	setup_camera_plane(mouse, &e->click.ray_cam);
	SDL_GetMouseState(&e->click.mouse_x, &e->click.mouse_y);
	get_ray_dir(mouse, &e->click.ray_cam, e->click.mouse_x, e->click.mouse_y);
	intersect_scene(mouse);
	if (mouse->p_hit)
	{
		if (!e->key.shift)
			deselect_all(e);
		if (mouse->p_hit == e->selected[e->s_num])
			e->selected[e->s_num] = 0;
		else if (mouse->p_hit->s_bool == 0)
		{
			mouse->p_hit->s_bool = 1;
			e->selected[e->s_num] = mouse->p_hit;
			e->selected[e->s_num]->loc_bak = e->selected[e->s_num]->loc;
			e->s_num++;
		}
		else
			mouse->p_hit->s_bool = 0;
	}
	else if (!mouse->p_hit && e->s_num)
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
	if (event.button.button == SDL_BUTTON_LEFT)
	{
		if (!e->key.g)
			click_select(e);
	}
	else if (event.button.button == SDL_BUTTON_RIGHT)
	{
		if (e->key.g)
			reset_loc(e);
	}
	else if (event.button.button == SDL_BUTTON_MIDDLE)
		e->key.mid_click = 1;
	reset_keys(e);
	draw(e, (SDL_Rect){0, 0, e->x, e->y});
}
