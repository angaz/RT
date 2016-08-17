/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_click.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arnovan- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/12 15:51:20 by arnovan-          #+#    #+#             */
/*   Updated: 2016/08/17 18:20:06 by arnovan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
/*
static void deselect(t_env *e)
{
	e->selected->select = 0;
	e->selected = NULL;
}
*/


static void	click_select(t_env *e)
{
	t_env			*mouse;
	int				mouse_x;
	int				mouse_y;
	t_camera_ray 	ray_origin;

	mouse = copy_env(e);
	setup_camera_plane(mouse, &ray_origin);
	SDL_GetMouseState( &mouse_x, &mouse_y );
	get_ray_dir(mouse, &ray_origin, mouse_x, mouse_y);
	intersect_scene(mouse);
	if (mouse->p_hit != NULL)
	{
			mouse->p_hit->select = (mouse->p_hit->select == 0) ? 1 : 0;
			if (e->selected)
				e->selected->select = 0;
			if (mouse->p_hit->select == 1)
			{
				e->selected = mouse->p_hit;
			}
			else
				e->selected = NULL;
			e->orig_loc = (t_vector)
			{e->selected->loc.x, e->selected->loc.y, e->selected->loc.z};
	}
	else if (!mouse->p_hit && e->selected)
	{
			e->selected->select = 0;
//			e->orig_loc = (t_vector){0.0, 0.0, 0.0};
	
	}
	free(mouse);
}

static void	shift_select(t_env *e)
{
	t_env			*mouse;
	int				mouse_x;
	int				mouse_y;
	t_camera_ray 	ray_origin;
	
	mouse = copy_env(e);
	setup_camera_plane(mouse, &ray_origin);
	SDL_GetMouseState( &mouse_x, &mouse_y );
	get_ray_dir(mouse, &ray_origin, mouse_x, mouse_y);
	intersect_scene(mouse);
	if (mouse->p_hit != NULL)
	{
printf("Shift-selecting!\n");
			mouse->p_hit->select = (mouse->p_hit->select == 0) ? 1 : 0;
		//	if (e->selected)
		//		e->selected->select = 0;
		//	if (mouse->p_hit->select == 1)
		//		e->selected = mouse->p_hit;
		//	else
		//		e->selected = NULL;
	}
	free(mouse);
}

void		mouse_click(t_env *e, SDL_Event event)
{
	SDL_SetRelativeMouseMode(0);
	if (event.button.button == SDL_BUTTON_LEFT && e->key.g != 1)
	{
		if (e->key.shift == 1)
			shift_select(e);
		else 
			click_select(e);
	}
	if (event.button.button == SDL_BUTTON_RIGHT)
	{
		if (e->key.g == 1)
		{
			e->key.g = 0;
			e->selected->loc = e->orig_loc;
		}
	}
	reset_keys(e);
	draw(e, (SDL_Rect){0, 0, WIN_X, WIN_Y});
}
