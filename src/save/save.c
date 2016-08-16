/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/15 11:59:15 by rojones           #+#    #+#             */
/*   Updated: 2016/08/16 09:45:40 by rojones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void	save_camra(t_camera *cam, int fd)
{
	ft_putstr_fd("	CAMERA\n", fd);
	ft_putstr_fd("\t\tLOC\t", fd);
	write_coord(cam->loc, fd);
	ft_putstr_fd("\t\tDIR\t", fd);
	write_coord(cam->dir, fd);
	ft_putstr_fd("\t\tUP\t", fd);
	write_coord(cam->up, fd);
	ft_putchar_fd('\n', fd);
}

void		save(t_env *e)
{
	int		fd;
	char	*temp;

	temp = NULL;
	fd = open(e->file_name, O_WRONLY | O_TRUNC);
	if (fd == -1)
		err(FILE_OPEN_ERROR, "save", e);
	ft_putstr_fd("# SCENE RT\n", fd);
	ft_putstr_fd("	MAXDEPTH	", fd);
	temp = ft_dtoa(e->maxdepth, 6);
	ft_putstr_fd(temp, fd);
	ft_strdel(&temp);
	ft_putstr_fd("\n\n", fd);
	save_camra(&e->camera, fd);
	save_lights(e->light, e->lights, fd);
	save_materials(e->material, e->materials, fd);
	save_prims(e->prim, e->material, e->prims, fd);
	save_objects(e->object, e->objects, e->material, fd);
	close(fd);
}
