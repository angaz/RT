/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_obj.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adippena <angusdippenaar@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/11 19:48:22 by adippena          #+#    #+#             */
/*   Updated: 2016/08/11 20:04:44 by adippena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void	make_box(t_object *o)
{
	size_t	vertex;

	vertex = 1;
	o->box[0] = (t_vector){o->v[0]->x, o->v[0]->y, o->v[0]->z};
	o->box[1] = o->box[0];
	while (vertex < o->verticies)
	{
		if (o->v[vertex]->x < o->box[0].x)
			o->box[0].x = o->v[vertex]->x;
		if (o->v[vertex]->y < o->box[0].y)
			o->box[0].y = o->v[vertex]->y;
		if (o->v[vertex]->z < o->box[0].z)
			o->box[0].z = o->v[vertex]->z;
		if (o->v[vertex]->x > o->box[1].x)
			o->box[1].x = o->v[vertex]->x;
		if (o->v[vertex]->y > o->box[1].y)
			o->box[1].y = o->v[vertex]->y;
		if (o->v[vertex]->z > o->box[1].z)
			o->box[1].z = o->v[vertex]->z;
		++vertex;
	}
printf("%lf, %lf, %lf\n", o->box[0].x, o->box[0].y, o->box[0].z);
printf("%lf, %lf, %lf\n", o->box[1].x, o->box[1].y, o->box[1].z);
}

void		read_obj(t_env *e, int fd)
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
				o->v[o->verticies] = (t_vector *)malloc(sizeof(t_vector));
				o->v[o->verticies]->x = ft_atod(values.strings[1]);
				o->v[o->verticies]->y = ft_atod(values.strings[2]);
				o->v[o->verticies]->z = ft_atod(values.strings[3]);
				++o->verticies;
			}
			if (!ft_strcmp(values.strings[0], "vn") && values.words == 4)
			{
				o->vn[o->vnormals] = (t_vector *)malloc(sizeof(t_vector));
				o->vn[o->vnormals]->x = ft_atod(values.strings[1]);
				o->vn[o->vnormals]->y = ft_atod(values.strings[2]);
				o->vn[o->vnormals]->z = ft_atod(values.strings[3]);
				++o->vnormals;
			}
			if (!ft_strcmp(values.strings[0], "f") && values.words == 4)
			{
				o->face[o->faces] = (t_face *)malloc(sizeof(t_face));
				o->face[o->faces]->v0 = o->v[ft_atoi(values.strings[1]) - 1];
				o->face[o->faces]->v1 = o->v[ft_atoi(values.strings[2]) - 1];
				o->face[o->faces]->v2 = o->v[ft_atoi(values.strings[3]) - 1];
				o->face[o->faces]->n =\
					o->vn[ft_atoi(ft_strrchr(values.strings[1], '/') + 1) - 1];
				++o->faces;
			}
			ft_free_split(&values);
		}
		ft_strdel(&line);
	}
	make_box(o);
}

