/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adippena <angusdippenaar@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/10 14:00:07 by adippena          #+#    #+#             */
/*   Updated: 2016/08/01 20:36:57 by adippena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

static void		setup_camera_plane(t_env *e, t_camera_ray *c)
{
	c->d = 2.1675;
	c->h = 18.0 * c->d / 35.0;
	c->w = c->h * (double)WIN_X / (double)WIN_Y;
	c->n = vector_unit(vector_sub(e->camera.loc, e->camera.dir));
	c->u = vector_unit(vector_cross(e->camera.up, c->n));
	c->v = vector_unit(vector_cross(c->n, c->u));
	c->c = vector_sub(e->camera.loc, vector_mult(c->n, c->d));
	c->l = vector_sub(c->c, vector_mult(c->u, c->w / 2.0));
	c->l = vector_add(c->l, vector_mult(c->v, c->h / 2.0));
}

static void		get_ray_dir(t_env *e, t_camera_ray *cr, double x, double y)
{
	t_vector	s;

	s = vector_add(cr->l, vector_mult(cr->u, x * cr->w / (double)WIN_X));
	s = vector_sub(s, vector_mult(cr->v, y * cr->h / (double)WIN_Y));
	e->ray.dir = vector_sub(s, e->camera.loc);;
	e->ray.loc = e->camera.loc;
}

static uint32_t	find_colour(t_env *e)
{
	uint32_t	colour;
	t_colour	temp_c;

	if (e->hit == NULL)
		return (0x7F7F7F);
	temp_c = diffuse_shade(e);
	colour = 0;
	colour |= (int)(temp_c.r * 255.0) << 16;
	colour |= (int)(temp_c.g * 255.0) << 8;
	colour |= (int)(temp_c.b * 255.0);
	return (colour);
}

static void		draw_frame(t_env *e, SDL_Rect *draw)
{
	t_camera_ray	cr;
	size_t			pixel;
	int				stopx;
	int				stopy;
	int				x;
//	t_vector		hit;

	stopx = draw->x + draw->w;
	stopy = draw->y + draw->h;
	setup_camera_plane(e, &cr);
	while (draw->y < stopy && draw->y < WIN_Y)
	{
		x = draw->x;
		while (x < stopx && x < WIN_X)
		{
			get_ray_dir(e, &cr, (double)x, (double)draw->y);
			intersect_scene(e);
			pixel = (draw->y * e->px_pitch + x * 4);
			*(uint32_t *)(e->px + pixel) = find_colour(e);
//			hit = vector_mult(e->ray.dir, e->t);
//printf("LOC: %lf, %lf, %lf    ", e->ray.loc.x, e->ray.loc.y, e->ray.loc.z);
//printf("DIR: %lf, %lf, %lf    ",
//	e->ray.loc.x - e->ray.dir.x * cr.d,
//	e->ray.loc.y - e->ray.dir.y * cr.d,
//	e->ray.loc.z - e->ray.dir.z * cr.d);
//printf("HIT: %lf, %lf, %lf\n", hit.x, hit.y, hit.z);
			++x;
		}
		++draw->y;
	}
}

void			draw(t_env *e, SDL_Rect draw)
{
	SDL_LockTexture(e->img, NULL, &e->px, &e->px_pitch);
	draw_frame(e, &draw);
	SDL_UnlockTexture(e->img);
	SDL_RenderCopy(e->rend, e->img, NULL, NULL);
	SDL_RenderPresent(e->rend);
	ft_putstr("Frame drawn\n");
}
