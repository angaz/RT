/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adippena <angusdippenaar@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/08 20:00:42 by adippena          #+#    #+#             */
/*   Updated: 2016/08/29 21:19:00 by adippena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void	scene_attributes(t_env *e, char *line)
{
	t_split_string	split;
	t_split_string	render;

	split = ft_nstrsplit(line, '\t');
	if (split.strings[0][0] != '#' && split.words != 2)
		err(FILE_FORMAT_ERROR, "scene_arrtibutes", e);
	if (!ft_strcmp(split.strings[0], "MAXDEPTH"))
		e->maxdepth = MAX(ft_atoi(split.strings[1]), 1);
	if (!ft_strcmp(split.strings[0], "RENDER"))
	{
		render = ft_nstrsplit(split.strings[1], ' ');
		if (render.words != 2)
			err(FILE_FORMAT_ERROR, "RENDER [tab] x-res y-res", e);
		e->x = ft_atoi(render.strings[0]);
		e->y = ft_atoi(render.strings[1]);
	}
	ft_free_split(&split);
}

static void	call_type(t_env *e, int fd, char **line)
{
	char	*temp_line;

	temp_line = ft_strtrim(*line);
	ft_strdel(line);
	if (!ft_strcmp(temp_line, "PRIMITIVE"))
		get_primitive_attributes(e, fd);
	if (!ft_strcmp(temp_line, "OBJECT"))
		get_object_attributes(e, fd);
	else if (!ft_strcmp(temp_line, "CAMERA"))
		get_camera_attributes(e, fd);
	else if (!ft_strcmp(temp_line, "LIGHT"))
		get_light_attributes(e, fd);
	else if (!ft_strcmp(temp_line, "MATERIAL"))
		get_material_attributes(e, fd);
	ft_strdel(&temp_line);
}

static void	get_quantities(t_env *e, int fd)
{
	char	*temp;
	char	*line;

	temp = NULL;
	while (ft_gnl(fd, &temp) || temp != NULL)
	{
		line = ft_strtrim(temp);
		ft_strdel(&temp);
		if (!ft_strcmp(line, "LIGHT"))
			++e->lights;
		else if (!ft_strcmp(line, "MATERIAL"))
			++e->materials;
		else if (!ft_strcmp(line, "PRIMITIVE"))
			++e->prims;
		else if (!ft_strcmp(line, "OBJECT"))
			++e->objects;
		ft_strdel(&line);
	}
	ft_printf("%d:\tLIGHTS\n%d:\tMATERIALS\n%d:\tPRIMITIVES\n%d:\tOBJECTS\n",\
		(int)e->lights, (int)e->materials, (int)e->prims, (int)e->objects);
	e->light = (t_light **)malloc(sizeof(t_light *) * e->lights);
	e->material = (t_material **)malloc(sizeof(t_material *) * ++e->materials);
	e->prim = (t_prim **)malloc(sizeof(t_prim *) * e->prims);
	e->object = (t_object **)malloc(sizeof(t_object *) * e->objects);
	close(fd);
}

static void	init_read_scene(t_env *e, int fd)
{
	get_quantities(e, fd);
	e->lights = 0;
	e->materials = 0;
	e->prims = 0;
	e->objects = 0;
	e->material[0] = (t_material *)malloc(sizeof(t_material));
	init_material(e->material[0]);
	ft_strdel(&e->material[0]->name);
	e->material[e->materials]->name = ft_strdup("DEFAULT");
	++e->materials;
}

void		read_scene(char *file, t_env *e)
{
	int			fd;
	char		*line;
	char		*temp_line;

	if ((fd = open(file, O_RDONLY)) == -1)
		err(FILE_OPEN_ERROR, "read_scene", e);
	if ((ft_gnl(fd, &line) == -1) || (ft_strcmp(line, "# SCENE RT")))
		err(FILE_FORMAT_ERROR, "read_scene", e);
	ft_strdel(&line);
	init_read_scene(e, fd);
	if ((fd = open(file, O_RDONLY)) == -1)
		err(FILE_OPEN_ERROR, "read_scene", e);
	while (ft_gnl(fd, &temp_line))
	{
		if (temp_line[0] == '\0')
			break ;
		line = ft_strtrim(temp_line);
		ft_strdel(&temp_line);
		scene_attributes(e, line);
		ft_strdel(&line);
	}
	ft_strdel(&temp_line);
	while (ft_gnl(fd, &temp_line))
		call_type(e, fd, &temp_line);
	close(fd);
}
