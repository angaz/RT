/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   material_values.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adippena <angusdippenaar@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/09 12:40:41 by adippena          #+#    #+#             */
/*   Updated: 2016/09/04 15:06:05 by adippena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static double	to_range(double value, double min, double max)
{
	value = (value < min) ? min : value;
	value = (value > max) ? max : value;
	return (value);
}

static void		set_material_values(t_env *e, char *pt1, char *pt2)
{
	t_split_string	values;

	values = ft_nstrsplit(pt2, ' ');
	if (!ft_strcmp(pt1, "NAME"))
	{
		ft_strdel(&e->material[e->materials]->name);
		e->material[e->materials]->name = ft_strdup(values.strings[0]);
	}
	else if (!ft_strcmp(pt1, "DIFFUSE"))
		e->material[e->materials]->diff = get_colour(e, values);
	else if (!ft_strcmp(pt1, "SPECULAR"))
		e->material[e->materials]->spec = get_colour(e, values);
	else if (!ft_strcmp(pt1, "REFLECT"))
		e->material[e->materials]->reflect =
			to_range(ft_atod(values.strings[0]), 0.0, 1.0);
	else if (!ft_strcmp(pt1, "REFRACT"))
		e->material[e->materials]->refract =
			to_range(ft_atod(values.strings[0]), 0.0, 1.0);
	else if (!ft_strcmp(pt1, "IOR"))
		e->material[e->materials]->ior = ft_atod(values.strings[0]);
	ft_free_split(&values);
}

void			init_material(t_material *m)
{
	m->name = ft_strdup("UNNAMED");
	m->reflect = 0.0;
	m->refract = 0.0;
	m->ior = 1;
	m->diff = (t_colour){1.0, 0.0, 0.870588235294, 1.0};
	m->spec = (t_colour){1.0, 1.0, 1.0, 0.5};
}

void			get_material_attributes(t_env *e, int fd)
{
	t_split_string	attr;
	char			*temp_line;

	attr.words = 0;
	e->material[e->materials] = (t_material *)malloc(sizeof(t_material));
	init_material(e->material[e->materials]);
	while (ft_gnl(fd, &temp_line))
	{
		if (temp_line[0] == '\0')
			break ;
		attr = ft_nstrsplit(temp_line, '\t');
		ft_strdel(&temp_line);
		if (attr.words < 2)
			err(FILE_FORMAT_ERROR, "Material attributes", e);
		set_material_values(e, attr.strings[0], attr.strings[1]);
		ft_free_split(&attr);
	}
	ft_strdel(&temp_line);
	++e->materials;
}
