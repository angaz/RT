/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adippena <angusdippenaar@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/08 20:00:42 by adippena          #+#    #+#             */
/*   Updated: 2016/08/09 01:34:21 by adippena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void	call_type(t_env *e, int fd, char **line)
{
	char	*temp_line;

	temp_line = ft_strtrim(*line);
	ft_strdel(line);
	if (!ft_strcmp(temp_line, "PRIMITIVE"))
		get_primitive_attributes(e, fd);
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
		ft_strdel(&line);
	}
	ft_printf("%d :\tLIGHTS\n", (int)e->lights);
	ft_printf("%d :\tMATERIALS\n", (int)e->materials);
	ft_printf("%d :\tPRIMITIVES\n", (int)e->prims);
	e->light = (t_light **)malloc(sizeof(t_light *) * e->lights);
	e->material = (t_material **)malloc(sizeof(t_material *) * e->materials);
	e->prim = (t_prim **)malloc(sizeof(t_prim *) * e->prims);
	close(fd);
}

void		read_scene(char *file, t_env *e)
{
	int		fd;
	char	*line;
	char	*temp_line;

	if ((fd = open(file, O_RDONLY)) == -1)
		err(FILE_OPEN_ERROR, "read_scene", e);
	if (!(ft_gnl(fd, &line)))
		if (ft_strcmp(line, "SCENE RT"))
			err(FILE_FORMAT_ERROR, "read_scene", e);
	ft_strdel(&line);
	get_quantities(e, fd);
	e->lights = 0;
	e->materials = 0;
	e->prims = 0;
	if ((fd = open(file, O_RDONLY)) == -1)
		err(FILE_OPEN_ERROR, "read_scene", e);
	while (ft_gnl(fd, &temp_line))
		call_type(e, fd, &temp_line);
	close(fd);
}
