/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/08 13:16:30 by rojones           #+#    #+#             */
/*   Updated: 2016/08/18 15:08:06 by rojones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_env	*copy_env(t_env *e)
{
	t_env	*res;

	res = (t_env *)malloc(sizeof(t_env));
	res = (t_env *)ft_memcpy(res, e, sizeof(t_env));
	/*res->win = e->win;
	res->rend = e->rend;
	res->img = e->img;
	res->px = e->px;
	res->file_name = e->file_name;
	res->px_pitch = e->px_pitch;
	res->ray = (t_ray){1, (t_vector){0, 0, 0}, (t_vector){0, 0, 1}, NULL, NULL};
	res->camera = e->camera;*/
	res->p_hit = NULL;
	/*res->hit_type = e->hit_type;
	res->prim = e->prim;
	res->prims = e->prims;
	res->o_hit = e->o_hit;
	res->object_hit = e->object_hit;
	res->object = e->object;
	res->objects = e->objects;
	res->light = e->light;
	res->lights = e->lights;
	res->material = e->material;
	res->materials = e->materials;*/
	res->t = INFINITY;
	/*res->maxdepth = e->maxdepth;*/
	return (res);
}
