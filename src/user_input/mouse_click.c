/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_click.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arnovan- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/12 15:51:20 by arnovan-          #+#    #+#             */
/*   Updated: 2016/08/19 18:09:08 by arnovan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void	reset_loc(t_env *e)
{
	size_t	index;

	index = e->s_num;
	e->key.g = 0;
	while (index > 0)
	{
		e->selected[index]->loc = e->selected[index]->loc_bak;
		index--;
	}
}

static void	click_select(t_env *e)
{
	t_env			*mouse;
	int				mouse_x;
	int				mouse_y;
	t_camera_ray 	ray_origin;
	
	printf("s_num : %lu\n", e->s_num);

	mouse = copy_env(e);
	setup_camera_plane(mouse, &ray_origin);
	SDL_GetMouseState( &mouse_x, &mouse_y );
	get_ray_dir(mouse, &ray_origin, mouse_x, mouse_y);
	intersect_scene(mouse);
	if (mouse->p_hit != NULL)
	{
		/*
		if (e->key.shift == 0)
		{
			printf("s_num : %lu\n", e->s_num);
			deselect(e);
		}*/

		if (e->key.shift == 0 || (mouse->p_hit == e->selected[e->s_num]))
		{
			printf("sdfsdf");
			deselect(e);
		}

		if (mouse->p_hit->s_bool == 0)
		{
			e->s_num++;
			mouse->p_hit->s_bool = 1;
			e->selected[e->s_num] = mouse->p_hit;
			e->selected[e->s_num]->loc_bak = e->selected[e->s_num]->loc; 
		}
		else
		{
			
//			e->selected[e->s_num] = 0;
			mouse->p_hit->s_bool = 0;
		}
//		mouse->p_hit->s_bool = (mouse->p_hit->s_bool == 0) ? 1 : 0;
//		mouse->p_hit->s_bool = (mouse->p_hit->s_bool == 0) ? 1 : 0;
//			e->selected[e->s_num]->s_bool = 0;
	}
	else if (!mouse->p_hit && e->s_num > 0)
		deselect(e);	
	free(mouse);
}

void		mouse_click(t_env *e, SDL_Event event)
{
	SDL_SetRelativeMouseMode(0);
	if (event.button.button == SDL_BUTTON_LEFT && e->key.g != 1)
		click_select(e);
	if (event.button.button == SDL_BUTTON_RIGHT)
	{
		if (e->key.g == 1)
			reset_loc(e);
	}
	reset_keys(e);
	draw(e, (SDL_Rect){0, 0, WIN_X, WIN_Y});
}
