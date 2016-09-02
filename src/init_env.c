/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adippena <angusdippenaar@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/08 20:00:14 by adippena          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2016/09/01 22:58:24 by adippena         ###   ########.fr       */
=======
/*   Updated: 2016/08/30 23:30:55 by adippena         ###   ########.fr       */
>>>>>>> 30a4314a13a467cafffd81c84ca3427de211883a
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
<<<<<<< HEAD
=======
	e->px_pitch = 0;
>>>>>>> 30a4314a13a467cafffd81c84ca3427de211883a
	e->hit_type = 0;
	e->prims = 0;
	e->objects = 0;
	e->lights = 0;
	e->materials = 0;
	e->t = INFINITY;
	e->maxdepth = 1;
	e->x = 1600;
	e->y = 900;
<<<<<<< HEAD
	e->flags = 0;
=======
	e->threads = 4;
>>>>>>> 30a4314a13a467cafffd81c84ca3427de211883a
}

static void		nulls(t_env *e)
{
	e->win = NULL;
	e->img = NULL;
	e->px = NULL;
<<<<<<< HEAD
=======
	e->dx = NULL;
>>>>>>> 30a4314a13a467cafffd81c84ca3427de211883a
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
<<<<<<< HEAD
=======
	init_keys(e);
>>>>>>> 30a4314a13a467cafffd81c84ca3427de211883a
	init_camera(e);
}

void			init_env(t_env *e)
{
	nullify_pointers(e);
	read_scene(e->file_name, e);
	e->win = SDL_CreateWindow(e->file_name, SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED, e->x, e->y, SDL_WINDOW_SHOWN);
	e->img = SDL_GetWindowSurface(e->win);
<<<<<<< HEAD
=======
	e->depth = SDL_CreateRGBSurface(0, e->x, e->y, 32, 0, 0, 0, 0);
>>>>>>> 30a4314a13a467cafffd81c84ca3427de211883a
	e->px = (uint32_t *)e->img->pixels;
	ft_bzero(e->px, (e->x * 4) * e->y);
	SDL_UpdateWindowSurface(e->win);
}
