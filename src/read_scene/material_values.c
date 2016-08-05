/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   material_values.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adippena <angusdippenaar@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/09 12:40:41 by adippena          #+#    #+#             */
/*   Updated: 2016/08/05 15:32:25 by adippena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_colour	get_colour(t_env *e, t_split_string values)
{
	t_colour	res;
	char		*temp;

	res = (t_colour){0.0, 0.0, 0.0, 1.0};
	if (values.words == 1 || values.words == 2)
	{
		if (ft_strlen(values.strings[0]) != 6)
			err(FILE_FORMAT_ERROR, "get_colour", e);
		temp = ft_strnew(3);
		temp = ft_strncpy(temp, values.strings[0], 2);
		res.r = ft_atoi_hex(temp) / 255.0;
		temp = ft_strncpy(temp, values.strings[0] + 2, 2);
		res.g = ft_atoi_hex(temp) / 255.0;
		temp = ft_strncpy(temp, values.strings[0] + 4, 2);
		res.b = ft_atoi_hex(temp) / 255.0;
		ft_strdel(&temp);
	}
	if (values.words == 2)
		res.intensity = ft_atod(values.strings[1]);
	if (values.words > 2)
		err(FILE_FORMAT_ERROR, "get_colour", e);
	return (res);
}

t_vector	get_vector(t_env *e, t_split_string values)
{
	t_vector	res;

	if (values.words != 3)
		err(FILE_FORMAT_ERROR, "get_vector", e);
	res = (t_vector){
		ft_atod(values.strings[0]),
		ft_atod(values.strings[1]),
		ft_atod(values.strings[2])};
	return (res);
}

t_vector	get_unit_vector(t_env *e, t_split_string values)
{
	t_vector	res;

	if (values.words != 3)
		err(FILE_FORMAT_ERROR, "get_vector", e);
	res = vunit((t_vector){
		ft_atod(values.strings[0]),
		ft_atod(values.strings[1]),
		ft_atod(values.strings[2])});
	return (res);
}

static void	set_material_values(t_env *e, char *pt1, char *pt2)
{
	t_split_string	values;

	values = ft_nstrsplit(pt2, ' ');
	if (!ft_strcmp(pt1, "NAME"))
		e->material[e->materials]->name = ft_strdup(values.strings[0]);
	else if (!ft_strcmp(pt1, "DIFFUSE"))
		e->material[e->materials]->diff = get_colour(e, values);
	else if (!ft_strcmp(pt1, "SPECULAR"))
		e->material[e->materials]->spec = get_colour(e, values);
	ft_free_split(&values);
}

void		get_material_attributes(t_env *e, int fd)
{
	t_split_string	attr;
	char			*temp_line;

	attr.words = 0;
	e->material[e->materials] = (t_material *)malloc(sizeof(t_material));
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
			err(FILE_FORMAT_ERROR, "get_material_attributes", e);
		set_material_values(e, attr.strings[0], attr.strings[1]);
		ft_free_split(&attr);
	}
	++e->materials;
}
