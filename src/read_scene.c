/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adippena <angusdippenaar@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/08 20:00:42 by adippena          #+#    #+#             */
/*   Updated: 2016/07/26 17:36:09 by adippena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

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
	int		fd;
	char	*line;
	char	*temp_line;

	if ((fd = open(file, O_RDONLY)) == -1)
		err(FILE_OPEN_ERROR, "read_scene", e);
	if (!(ft_gnl(fd, &line)))
		if (ft_strcmp(line, "SCENE RTV1"))
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
		scene_attributes(e, line);
		ft_strdel(&line);
	}
	while (ft_gnl(fd, &temp_line))
		call_type(e, fd, &temp_line);
}
