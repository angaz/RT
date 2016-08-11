/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adippena <angusdippenaar@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/08 20:00:42 by adippena          #+#    #+#             */
/*   Updated: 2016/08/11 10:13:16 by rojones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

/*static t_objcount	count_object(char *file, t_env *e)
{
	t_objcount	re;
	char		*line;
	char		*temp_line;
	char		*temp_line2;
	char		*temp_line3;
	int			fd;

	re.obj = 0;
	re.light = 0;
	re.mat = 0;
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
		ft_strdel(&line);
	}
	while (ft_gnl(fd, &temp_line))
	{
		temp_line2 = ft_strtrim(temp_line);
		if (!ft_strcmp(temp_line2, "OBJECT"))
			re.obj++;
		else if (!ft_strcmp(temp_line2, "LIGHT"))
			re.light++;
		else if (!ft_strcmp(temp_line2, "MATERIAL"))
			re.mat++;
		while (ft_gnl(fd, &temp_line3))
		{   
			if (temp_line3[0] == '\0')
			{   
				ft_strdel(&temp_line3);
				break ;
			}
			ft_strdel(&temp_line3);
		}	
		ft_strdel(&temp_line2);
		ft_strdel(&temp_line);
	}
	close (fd);
	return (re);
}*/

static void	scene_attributes(t_env *e, char *line)
{
	t_split_string	split;

	split = ft_nstrsplit(line, '\t');
	if (split.words != 2)
		err(FILE_FORMAT_ERROR, "scene_arrtibutes", e);
	if (!ft_strcmp(split.strings[0], "MAXDEPTH"))
	{
		e->maxdepth = ft_atoi(split.strings[1]);
		if (e->maxdepth < 0)
			e->maxdepth = 1;
	}
	ft_free_split(&split);
}

static void	scene_allocate(t_env *e, t_objcount *counts)
{
	e->object = (t_object **)malloc(sizeof(t_object *) * counts->obj);
	e->light = (t_light **)malloc(sizeof(t_light *) * counts->light);
	e->material = (t_material **)malloc(sizeof(t_material *) * counts->mat);
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

	counts = count_object(file, e);
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
		scene_attributes(e, line);
		ft_strdel(&line);
	}
	scene_allocate(e, &counts);
	while (ft_gnl(fd, &temp_line))
		call_type(e, fd, &temp_line);
}
