/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adippena <angusdippenaar@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/08 20:00:42 by adippena          #+#    #+#             */
/*   Updated: 2016/08/10 18:08:18 by rojones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static t_objcount	count_object(char *file, t_env *e)
{
	t_objcount	re;
	char		*line;
	int			fd;

	re.obj = 0;
	re.light = 0;
	re.mat = 0;
	if ((fd = open(file, O_RDONLY)) == -1)
		err(FILE_OPEN_ERROR, "read_scene", e);
	if (!(ft_gnl(fd, &line)))
		if (ft_strcmp(line, "SCENE RT"))
			err(FILE_FORMAT_ERROR, "read_scene", e);
	while (ft_gnl(fd, &_line))
	{
		if (!ft_strcmp(temp_line, "OBJECT"))
			re.obj++;
		else if (!ft_strcmp(temp_line, "LIGHT"))
			re.light++;
		else if (!ft_strcmp(temp_line, "MATERIAL"))
			re.mat++;
		free(line);
	}
}

/*static void	scene_attributes(t_env *e, char *line)
{
	t_split_string	split;
	size_t			quantity;

	split = ft_nstrsplit(line, '\t');
	if (split.words != 2)
		err(FILE_FORMAT_ERROR, "scene_arrtibutes", e);
	if (!ft_strcmp(split.strings[0], "OBJECTS"))
	{
		quantity = ft_atoi(split.strings[1]);
		e->object = (t_object **)malloc(sizeof(t_object *) * quantity);
	}
	else if (!ft_strcmp(split.strings[0], "LIGHTS"))
	{
		quantity = ft_atoi(split.strings[1]);
		e->light = (t_light **)malloc(sizeof(t_light *) * quantity);
	}
	else if (!ft_strcmp(split.strings[0], "MATERIALS"))
	{
		quantity = ft_atoi(split.strings[1]);
		e->material = (t_material **)malloc(sizeof(t_material *) * quantity);
	}
	else if (!ft_strcmp(split.strings[0], "MAXDEPTH"))
	{
		e->maxdepth = ft_atoi(split.strings[1]);
		if (e->maxdepth < 0)
			e->maxdepth = -1 * e->maxdepth;
	}
	ft_free_split(&split);
}*/

static void	scene_attributes(t_env *e, char *line)
{
	t_split_string	split;
	size_t			quantity;

	split = ft_nstrsplit(line, '\t');
	if (split.words != 2)
		err(FILE_FORMAT_ERROR, "scene_arrtibutes", e);
	if (!ft_strcmp(split.strings[0], "OBJECTS"))
	{
		quantity = ft_atoi(split.strings[1]);
		e->object = (t_object **)malloc(sizeof(t_object *) * quantity);
	}
	else if (!ft_strcmp(split.strings[0], "LIGHTS"))
	{
		quantity = ft_atoi(split.strings[1]);
		e->light = (t_light **)malloc(sizeof(t_light *) * quantity);
	}
	else if (!ft_strcmp(split.strings[0], "MATERIALS"))
	{
		quantity = ft_atoi(split.strings[1]);
		e->material = (t_material **)malloc(sizeof(t_material *) * quantity);
	}
	else if (!ft_strcmp(split.strings[0], "MAXDEPTH"))
	{
		e->maxdepth = ft_atoi(split.strings[1]);
		if (e->maxdepth < 0)
			e->maxdepth = -1 * e->maxdepth;
	}
	ft_free_split(&split);
}

static void	call_type(t_env *e, int fd, char **line)
{
	char	*temp_line;

	temp_line = ft_strtrim(*line);
	ft_strdel(line);
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

void		read_scene(char *file, t_env *e)
{
	int			fd;
	char		*line;
	char		*temp_line;
	t_objcount	counts;

	if ((fd = open(file, O_RDONLY)) == -1)
		err(FILE_OPEN_ERROR, "read_scene", e);
	if (!(ft_gnl(fd, &line)))
		if (ft_strcmp(line, "SCENE RT"))
			err(FILE_FORMAT_ERROR, "read_scene", e);
	ft_strdel(&line);
	while (ft_gnl(fd, &temp_line))
	{
		if (temp_line[0] == '\0')
		{
			ft_strdel(&line);
			break ;
		}
		line = ft_strtrim(temp_line);
		ft_strdel(&temp_line);
		//scene_attributes(e, line);
		ft_strdel(&line);
	}
	scene_attributes(e, counts);
	while (ft_gnl(fd, &temp_line))
		call_type(e, fd, &temp_line);
}
