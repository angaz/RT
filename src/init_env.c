/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adippena <angusdippenaar@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/08 20:00:14 by adippena          #+#    #+#             */
/*   Updated: 2016/08/02 00:46:03 by adippena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	nullify_pointers(t_env *e)
{
	e->win = NULL;
	e->rend = NULL;
	e->img = NULL;
	e->object = NULL;
	e->light = NULL;
	e->material = NULL;
	e->objects = 0;
	e->lights = 0;
	e->materials = 0;
}

void	init_env(t_env *e, char **av)
{
	read_scene(av[1], e);
	e->win = SDL_CreateWindow(av[1], SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED, WIN_X, WIN_Y, 0);
	e->rend = SDL_CreateRenderer(e->win, -1, SDL_RENDERER_ACCELERATED);
	e->img = SDL_CreateTexture(e->rend, SDL_PIXELFORMAT_ARGB8888,
		SDL_TEXTUREACCESS_STREAMING, WIN_X, WIN_Y);
}
