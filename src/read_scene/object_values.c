/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_values.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adippena <angusdippenaar@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/09 21:36:49 by adippena          #+#    #+#             */
/*   Updated: 2016/08/09 23:50:36 by adippena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void		get_quantities(t_object *o, int fd)
{
	char	*line;

	while (ft_gnl(fd, &line))
	{
		if (!ft_strncmp(line, "v ", 2))
			++o->verticies;
		if (!ft_strncmp(line, "vn", 2))
			++o->vnormals;
		if (!ft_strncmp(line, "f ", 2))
			++o->faces;
		ft_strdel(&line);
	}
	o->face = (t_face *)malloc(sizeof(t_face) * o->faces);
	o->v = (t_vector *)malloc(sizeof(t_vector) * o->verticies);
	o->vn = (t_vector *)malloc(sizeof(t_vector) * o->vnormals);
	o->faces = 0;
	o->verticies = 0;
	o->vnormals = 0;
}

static void		read_obj(t_env *e, int fd)
{
	t_split_string	values;
	char			*line;
	t_object		*o;

	o = e->object[e->objects];
	while (ft_gnl(fd, &line))
	{
		if (line[0] != '#' || line[0] != 's')
		{
			values = ft_nstrsplit(line, ' ');
			if (!ft_strcmp(values.strings[0], "v") && values.words == 4)
			{
				o->v[o->verticies].x = ft_atod(values.strings[1]);
				o->v[o->verticies].y = ft_atod(values.strings[2]);
				o->v[o->verticies].z = ft_atod(values.strings[3]);
				++o->verticies;
			}
			if (!ft_strcmp(values.strings[0], "vn") && values.words == 4)
			{
				o->vn[o->vnormals].x = ft_atod(values.strings[1]);
				o->vn[o->vnormals].y = ft_atod(values.strings[2]);
				o->vn[o->vnormals].z = ft_atod(values.strings[3]);
				++o->vnormals;
			}
			if (!ft_strcmp(values.strings[0], "f") && values.words == 4)
			{
				o->face[o->faces].v0 = &o->v[ft_atoi(values.strings[1]) - 1];
				o->face[o->faces].v1 = &o->v[ft_atoi(values.strings[2]) - 1];
				o->face[o->faces].v2 = &o->v[ft_atoi(values.strings[3]) - 1];
				o->face[o->faces].n =\
					&o->vn[ft_atoi(ft_strrchr(values.strings[1], '/') + 1) - 1];
				++o->faces;
			}
			ft_free_split(&values);
		}
		ft_strdel(&line);
	}
}

static void		set_object_values(t_env *e, char *pt1, char *pt2)
{
	int		fd;

	if (!ft_strcmp(pt1, "FILE"))
	{
		if ((fd = open(pt2, O_RDONLY)) == -1)
			err(FILE_OPEN_ERROR, "set_object_values", e);
		get_quantities(e->object[e->objects], fd);
		close(fd);
		if ((fd = open(pt2, O_RDONLY)) == -1)
			err(FILE_OPEN_ERROR, "set_object_values", e);
		read_obj(e, fd);
		close(fd);
	}
	else if (!ft_strcmp(pt1, "MATERIAL"))
		e->object[e->objects]->material = get_material_number(e, pt2);
}

static void		init_object(t_object *o)
{
	o->face = NULL;
	o->faces = 0;
	o->material = 0;
	o->v = NULL;
	o->verticies = 0;
	o->vn = NULL;
	o->vnormals = 0;
}

void			get_object_attributes(t_env *e, int fd)
{
	t_split_string	attr;
	char			*temp_line;

	attr.words = 0;
	e->object[e->objects] = (t_object *)malloc(sizeof(t_object));
	init_object(e->object[e->objects]);
	while (ft_gnl(fd, &temp_line))
	{
ft_putendl(temp_line);
		if (temp_line[0] == '\0')
		{
			ft_strdel(&temp_line);
			break ;
		}
		attr = ft_nstrsplit(temp_line, '\t');
		ft_strdel(&temp_line);
		if (attr.words < 2)
			err(FILE_FORMAT_ERROR, "get_object_attributes", e);
		set_object_values(e, attr.strings[0], attr.strings[1]);
		ft_free_split(&attr);
	}

	size_t		i	= 0;
	t_object	*o	= e->object[e->objects];
	while (i < o->faces)
	{
		printf("FACE: %lu\n", i);
		printf("V0: %lf, %lf, %lf\n", o->face[i].v0->x,\
										o->face[i].v0->y,\
										o->face[i].v0->z);
		printf("V1: %lf, %lf, %lf\n", o->face[i].v1->x,\
										o->face[i].v1->y,\
										o->face[i].v1->z);
		printf("V2: %lf, %lf, %lf\n", o->face[i].v2->x,\
										o->face[i].v2->y,\
										o->face[i].v2->z);
		printf("N: %lf, %lf, %lf\n\n", o->face[i].n->x,\
										o->face[i].n->y,\
										o->face[i].n->z);
	++i;
	}
	++e->objects;
}
