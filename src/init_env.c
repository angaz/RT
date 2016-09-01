/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adippena <angusdippenaar@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/08 20:00:14 by adippena          #+#    #+#             */
/*   Updated: 2016/09/01 23:54:57 by adippena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void		init_camera(t_env *e)
{
	e->camera.loc = (t_vector){0.0, -10.0, 0.0};
	e->camera.dir = (t_vector){0.0, 0.0, 0.0};
	e->camera.up = (t_vector){0.0, 0.0, 1.0};
}

static void		initials(t_env *e)
{
	e->s_num = 0;
	e->prims = 0;
	e->objects = 0;
	e->lights = 0;
	e->materials = 0;
	e->hit_type = 0;
	e->prims = 0;
	e->objects = 0;
	e->lights = 0;
	e->materials = 0;
	e->t = INFINITY;
	e->maxdepth = 1;
	e->x = 1600;
	e->y = 900;
	e->flags = 0;
}

static void		nulls(t_env *e)
{
	e->win = NULL;
	e->img = NULL;
	e->px = NULL;
	e->p_hit = NULL;
	e->prim = NULL;
	e->o_hit = NULL;
	e->object_hit = NULL;
	e->object = NULL;
	e->light = NULL;
	e->material = NULL;
	e->p_hit = NULL;
}

void			nullify_pointers(t_env *e)
{
	initials(e);
	nulls(e);
	init_camera(e);
}

void			init_env(t_env *e)
{
	nullify_pointers(e);
	read_scene(e->file_name, e);
	e->win = SDL_CreateWindow(e->file_name, SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED, e->x, e->y, SDL_WINDOW_SHOWN);
	e->img = SDL_GetWindowSurface(e->win);
	e->px = (uint32_t *)e->img->pixels;
	ft_bzero(e->px, (e->x * 4) * e->y);
	SDL_UpdateWindowSurface(e->win);
}
