/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/15 11:59:15 by rojones           #+#    #+#             */
/*   Updated: 2016/08/31 21:04:29 by adippena         ###   ########.fr       */
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

static void	save_render(t_env *e, int fd)
{
	char	*tempx;
	char	*tempy;
	char	*print;

	ft_putstr_fd("	RENDER		", fd);
	tempx = ft_itoa(e->x);
	tempy = ft_itoa(e->y);
	print = ft_strjoin(tempx, " ");
	ft_strdel(&tempx);
	tempx = print;
	print = ft_strjoin(tempx, tempy);
	ft_strdel(&tempy);
	ft_putendl_fd(print, fd);
	ft_strdel(&print);
}

void		save(t_env *e)
{
	int		fd;
	char	*temp;

	ft_putstr("Saving file... ");
	temp = NULL;
	if ((fd = open(e->file_name, O_WRONLY | O_TRUNC)) == -1)
		err(FILE_OPEN_ERROR, "Could not save the file", e);
	ft_putstr_fd("# SCENE RT\n", fd);
	ft_putstr_fd("	MAXDEPTH	", fd);
	temp = ft_itoa(e->maxdepth);
	ft_putendl_fd(temp, fd);
	ft_strdel(&temp);
	save_render(e, fd);
	ft_putstr_fd("\n", fd);
	save_camra(&e->camera, fd);
	save_lights(e->light, e->lights, fd);
	save_materials(e->material, e->materials, fd);
	save_prims(e->prim, e->material, e->prims, fd);
	save_objects(e->object, e->objects, e->material, fd);
	close(fd);
	ft_putstr("Done\n");
}
