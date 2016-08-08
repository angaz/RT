/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prim_values.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adippena <angusdippenaar@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/09 09:54:48 by adippena          #+#    #+#             */
/*   Updated: 2016/08/09 01:32:56 by adippena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static int		get_type(char *type_str)
{
	int				type;

	type = -1;
	if (!ft_strcmp(type_str, "sphere"))
		type = PRIM_SPHERE;
	else if (!ft_strcmp(type_str, "plane"))
		type = PRIM_PLANE;
	else if (!ft_strcmp(type_str, "cone"))
		type = PRIM_CONE;
	else if (!ft_strcmp(type_str, "cylinder"))
		type = PRIM_CYLINDER;
//	else if (!ft_strcmp(type_str, "triangle"))
//		type = OBJ_TRIANGLE;
	return (type);
}

static size_t	get_material_number(t_env *e, t_split_string values)
{
	size_t	material;
	char	*warn;

	material = 0;
	if (values.words != 1)
		err(FILE_FORMAT_ERROR, "get_material_number", e);
	while (material < e->materials)
	{
		if (!ft_strcmp(e->material[material]->name, values.strings[0]))
			return (material);
		++material;
	}
	ft_sprintf(&warn, "\e[208m    WARNING: Material name: %s \
		is not a defined material name\n", values.strings[0]);
	ft_putstr_fd(warn, 2);
	ft_strdel(&warn);
	return (0);
}

static void		set_primitive_values(t_env *e, char *pt1, char *pt2)
{
	t_split_string	values;

	values = ft_nstrsplit(pt2, ' ');
	if (!ft_strcmp(pt1, "TYPE"))
		if ((e->prim[e->prims]->type = get_type(values.strings[0])) == -1)
			err(FILE_FORMAT_ERROR, "set_prim_values", e);
	if (!ft_strcmp(pt1, "LOC"))
		e->prim[e->prims]->loc = get_vector(e, values);
	else if (!ft_strcmp(pt1, "DIR"))
		e->prim[e->prims]->dir = get_unit_vector(e, values);
	else if (!ft_strcmp(pt1, "NORMAL"))
		e->prim[e->prims]->normal = get_unit_vector(e, values);
	else if (!ft_strcmp(pt1, "RADIUS"))
		e->prim[e->prims]->radius = ft_atod(values.strings[0]);
	else if (!ft_strcmp(pt1, "ANGLE"))
		e->prim[e->prims]->angle = ft_atod(values.strings[0]) * M_PI / 180;
	else if (!ft_strcmp(pt1, "MATERIAL"))
		e->prim[e->prims]->material = get_material_number(e, values);
//	else if (!ft_strcmp(pt1, "TRIANGLE"))
//		get_tri(e, e->prim[e->prims], &values);
	ft_free_split(&values);
}

static void		init_primitive(t_prim *o)
{
	o->type = PRIM_SPHERE;
	o->loc = (t_vector){0.0, 0.0, 0.0};
	o->radius = 1.0;
	o->material = 0;
}

void			get_primitive_attributes(t_env *e, int fd)
{
	t_split_string	attr;
	char			*temp_line;

	attr.words = 0;
	e->prim[e->prims] = (t_prim *)malloc(sizeof(t_prim));
	init_primitive(e->prim[e->prims]);
	while (ft_gnl(fd, &temp_line))
	{
		if (temp_line[0] == '\0')
		{
			ft_strdel(&temp_line);
			break ;
		}
		attr = ft_nstrsplit(temp_line, '\t');
		ft_strdel(&temp_line);
		if (attr.words < 2)
			err(FILE_FORMAT_ERROR, "get_primitive_attributes", e);
		set_primitive_values(e, attr.strings[0], attr.strings[1]);
		ft_free_split(&attr);
	}
	++e->prims;
}
