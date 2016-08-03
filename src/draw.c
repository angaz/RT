/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adippena <angusdippenaar@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/10 14:00:07 by adippena          #+#    #+#             */
/*   Updated: 2016/08/03 11:21:38 by adippena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

static uint32_t	find_colour(t_env *e)
{
	uint32_t	colour;
	t_colour	temp_c;

	if (e->hit == NULL)
		return (0x7F7F7F);
	temp_c = diffuse_shade(e);
	colour = 0;
	colour |= (int)(temp_c.r * 255.0 * temp_c.intensity) << 16;
	colour |= (int)(temp_c.g * 255.0 * temp_c.intensity) << 8;
	colour |= (int)(temp_c.b * 255.0 * temp_c.intensity);
	return (colour);
}

static void		*draw_chunk(void *q)
{
	t_chunk		*c;

	c = (t_chunk *)q;
	c->stopx = c->d.x + c->d.w;
	c->stopy = c->d.y + c->d.h;
	setup_camera_plane(c->e, &c->cr);
	while (c->d.y < c->stopy && c->d.y < WIN_Y)
	{
		c->x = c->d.x;
		while (c->x < c->stopx && c->x < WIN_X)
		{
			get_ray_dir(c->e, &c->cr, (double)c->x, (double)c->d.y);
			intersect_scene(c->e);
			c->pixel = (c->d.y * c->e->px_pitch + c->x * 4);
			*(uint32_t *)(c->e->px + c->pixel) = find_colour(c->e);
			++c->x;
		}
		++c->d.y;
	}
	free(c->e);
	free(c);
	pthread_exit(0);
}

static int		ft_ceiling(double nbr)
{
	if (nbr > (double)((int)nbr))
		return ((int)nbr + 1);
	return ((int)nbr);
}

static t_env	*copy_env(t_env *e)
{
	t_env	*res;

	res = (t_env *)malloc(sizeof(t_env));
	res->win = e->win;
	res->rend = e->rend;
	res->img = e->img;
	res->px = e->px;
	res->px_pitch = e->px_pitch;
	res->ray = e->ray;
	res->camera = e->camera;
	res->hit = e->hit;
	res->object = e->object;
	res->objects = e->objects;
	res->light = e->light;
	res->lights = e->lights;
	res->material = e->material;
	res->materials = e->materials;
	res->t = e->t;
	return (res);
}

static void		make_chunks(t_env *e, SDL_Rect *d)
{
	size_t		tids;
	size_t		thread;
	size_t		chunk_x;
	size_t		chunk_y;
	pthread_t	*tid;
	t_chunk		*c;

	tids = ft_ceiling((double)d->w / 64.0) * ft_ceiling((double)d->h / 64.0);
	tid = (pthread_t *)malloc(sizeof(pthread_t) * tids);
	thread = 0;
	chunk_y = 0;
	while (chunk_y * 64 < (size_t)d->h)
	{
		chunk_x = 0;
		while(chunk_x * 64 < (size_t)d->w)
		{
			c = (t_chunk *)malloc(sizeof(t_chunk));
			c->e = copy_env(e);
			c->d = (SDL_Rect){chunk_x * 64, chunk_y * 64, 64, 64};
			pthread_create(&tid[thread++], NULL, draw_chunk, (void *)c);
			++chunk_x;
		}
		++chunk_y;
	}
	while (thread)
		pthread_join(tid[--thread], NULL);
	free(tid);
}

void			draw(t_env *e, SDL_Rect d)
{
	SDL_LockTexture(e->img, NULL, &e->px, &e->px_pitch);
	make_chunks(e, &d);
	SDL_UnlockTexture(e->img);
	SDL_RenderCopy(e->rend, e->img, NULL, NULL);
	SDL_RenderPresent(e->rend);
	ft_putstr("Frame drawn\n");
}
