/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adippena <angusdippenaar@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/08 20:00:14 by adippena          #+#    #+#             */
/*   Updated: 2016/08/18 08:06:56 by rojones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void		init_camera(t_env *e)
{
	e->camera.loc = (t_vector){0.0, -10.0, 0.0};
	e->camera.dir = (t_vector){0.0, 0.0, 0.0};
	e->camera.up = (t_vector){0.0, 0.0, 1.0};
}

void			nullify_pointers(t_env *e)
{
	e->win = NULL;
	e->rend = NULL;
	e->img = NULL;
	e->px = NULL;
	e->p_hit = NULL;
	e->prim = NULL;
	e->o_hit = NULL;
	e->object_hit = NULL;
	e->object = NULL;
	e->light = NULL;
	e->material = NULL;
	e->px_pitch = 0;
	e->hit_type = 0;
	e->prims = 0;
	e->objects = 0;
	e->lights = 0;
	e->materials = 0;
	e->t = INFINITY;
	e->maxdepth = 1;
	init_camera(e);
}

void			init_env(t_env *e)
{
	nullify_pointers(e);	
	read_scene(e->file_name, e);
	e->win = SDL_CreateWindow(e->file_name, SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED, WIN_X, WIN_Y, 0);
	e->rend = SDL_CreateRenderer(e->win, -1, SDL_RENDERER_ACCELERATED);
	e->img = SDL_CreateTexture(e->rend, SDL_PIXELFORMAT_ARGB8888,
		SDL_TEXTUREACCESS_STREAMING, WIN_X, WIN_Y);
}
