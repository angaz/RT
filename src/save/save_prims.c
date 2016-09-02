/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_prims.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/15 15:05:07 by rojones           #+#    #+#             */
/*   Updated: 2016/09/01 13:37:40 by adippena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void	put_type(int type, int fd)
{
	char *temp;

	temp = NULL;
	if (type == PRIM_SPHERE)
		temp = "sphere";
	else if (type == PRIM_PLANE)
		temp = "plane";
	else if (type == PRIM_HEMI_SPHERE)
		temp = "hemi_sphere";
	else if (type == PRIM_CONE)
		temp = "cone";
	else if (type == PRIM_CYLINDER)
		temp = "cylinder";
	else if (type == PRIM_DISK)
		temp = "disk";
	else if (type == PRIM_TRIANGLE)
		temp = "triangle";
	ft_putstr_fd(temp, fd);
	ft_putchar_fd('\n', fd);
}

static void	ft_putd_fd(double d, int fd)
{
	char	temp[20];

	sprintf(temp, "%f\n", d);
	ft_putstr_fd(temp, fd);
}

static void	save_prim2(const t_prim *prim, t_material **mat, const int fd)
{
	if (prim->type == PRIM_SPHERE || prim->type == PRIM_CYLINDER ||
			prim->type == PRIM_HEMI_SPHERE)
	{
		ft_putstr_fd("\t\tRADIUS\t\t", fd);
		ft_putd_fd(prim->radius, fd);
	}
	if (prim->type == PRIM_CONE)
	{
		ft_putstr_fd("\t\tANGLE\t\t", fd);
		ft_putd_fd((180 / M_PI) * prim->angle, fd);
	}
	ft_putstr_fd("\t\tMATERIAL\t", fd);
	ft_putstr_fd(mat[prim->material]->name, fd);
	ft_putstr_fd("\n\n", fd);
}

static void	save_prim(const t_prim *prim, t_material **mat, const int fd)
{
	ft_putstr_fd("\tPRIMITIVE\n", fd);
	ft_putstr_fd("\t\tTYPE\t\t", fd);
	put_type(prim->type, fd);
	ft_putstr_fd("\t\tLOC\t\t\t", fd);
	write_coord(prim->loc, fd);
	if (prim->type == PRIM_HEMI_SPHERE)
	{
		ft_putstr_fd("\t\tDIR\t\t\t", fd);
		write_coord(prim->dir, fd);
	}
	if (prim->type == PRIM_CONE || prim->type == PRIM_CYLINDER)
	{
		ft_putstr_fd("\t\tDIR\t\t\t", fd);
		write_coord(prim->dir, fd);
		ft_putstr_fd("\t\tLIMIT\t\t", fd);
		ft_putd_fd(prim->limit, fd);
	}
	if (prim->type == PRIM_PLANE || prim->type == PRIM_DISK)
	{
		ft_putstr_fd("\t\tNORMAL\t\t", fd);
		write_coord(prim->normal, fd);
	}
	save_prim2(prim, mat, fd);
}

void		save_prims(t_prim **prim, t_material **mat, size_t prims, int fd)
{
	size_t	i;

	i = 0;
	while (i < prims)
	{
		save_prim(prim[i], mat, fd);
		i++;
	}
}
