/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adippena <angusdippenaar@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/10 14:00:07 by adippena          #+#    #+#             */
/*   Updated: 2016/08/18 17:08:40 by rojones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

/*
** l = ref[l]ect colour
** r = ref[r]act colour
*/

static uint32_t	find_colour(t_env *e)
{
	t_colour	c;
	t_colour	l;
	t_colour	r;
	t_material	*mat;

	if (!e->hit_type)
		return (0x7F7F7F);
	l = (t_colour){0.0, 0.0, 0.0, 0.0};
	c = (e->hit_type == FACE) ? face_diffuse(e) : prim_diffuse(e);
	mat = (e->hit_type == FACE) ?
		e->material[e->object_hit->material] :
		e->material[e->p_hit->material];
	if (mat->reflect > EPSILON)
		l = reflect(e, 1);
	if (mat->refract > EPSILON)
	{
		r = refract(e, 1, c);
		c.r = (c.r * (1 - mat->refract)) + (r.r * mat->refract);
		c.g = (c.g * (1 - mat->refract)) + (r.g * mat->refract);
		c.b = (c.b * (1 - mat->refract)) + (r.b * mat->refract);
	}
	return ((uint32_t)(
	(int)(((c.r * (1 - mat->reflect)) + (l.r * mat->reflect)) * 255.0) << 16 |
	(int)(((c.g * (1 - mat->reflect)) + (l.g * mat->reflect)) * 255.0) << 8 |
	(int)(((c.b * (1 - mat->reflect)) + (l.b * mat->reflect)) * 255.0)));
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


static void		make_chunks(t_env *e, SDL_Rect *d)
{
	t_make_chunks	m;

	m.tids = ceil((double)d->w / 64.0) * ceil((double)d->h /64.0);
	m.tid = (pthread_t *)malloc(sizeof(pthread_t) * m.tids);
	m.thread = 0;
	m.chunk_y = 0;
	while (m.chunk_y * 64 < (size_t)d->h)
	{
		m.chunk_x = 0;
		while (m.chunk_x * 64 < (size_t)d->w)
		{
			m.c = (t_chunk *)malloc(sizeof(t_chunk));
			m.c->e = copy_env(e);
			m.c->d = (SDL_Rect){m.chunk_x * 64, m.chunk_y * 64, 64, 64};
			pthread_create(&m.tid[m.thread++], NULL, draw_chunk, (void *)m.c);
			++m.chunk_x;
		}
	++m.chunk_y;
	}
	while (m.thread)
		pthread_join(m.tid[--m.thread], NULL);
	free(m.tid);
}

void			draw(t_env *e, SDL_Rect d)
{
	time_t	t;

	t = time(NULL);
	SDL_LockTexture(e->img, NULL, &e->px, &e->px_pitch);
	make_chunks(e, &d);

	/*t_camera_ray cr;
	int	pixel;

			setup_camera_plane(e, &cr);
			get_ray_dir(e, &cr, d.w/2, d.h/2);
			intersect_scene(e);
			pixel = (d.h/2 * e->px_pitch + d.w/2 * 4);
			*(uint32_t *)(e->px + pixel) = find_colour(e);*/

	SDL_UnlockTexture(e->img);
	SDL_RenderCopy(e->rend, e->img, NULL, NULL);
	SDL_RenderPresent(e->rend);
	t = time(NULL) - t;
	ft_printf("Frame drawn in %d seconds\n", t);
}
