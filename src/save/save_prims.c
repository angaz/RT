/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_prims.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/15 15:05:07 by rojones           #+#    #+#             */
/*   Updated: 2016/08/15 17:18:04 by rojones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void put_type(int type, int fd)
{
	char *temp;

	temp = NULL;
	if (type == PRIM_SPHERE)
		temp = "sphere";
	else if (type == PRIM_PLANE)
		temp = "plane";
	else if (type == PRIM_CONE)
		temp = "cone";
	else if (type == PRIM_CYLINDER)
		temp = "cylinder";
	else if (type == PRIM_TRIANGLE)
		temp = "triangle";
	ft_putstr_fd(temp, fd);
	ft_putchar_fd('\n', fd);
}

static void	save_prim(t_prim *prim, t_material **mat, int fd)
{
	char	*temp;

	temp = NULL;
	ft_putstr_fd("\tPRIMITIVE\n", fd);
	ft_putstr_fd("\t\tTYPE\t\t", fd);
	put_type(prim->type, fd);
	ft_putstr_fd("\t\tLOC\t\t", fd);
	write_coord(prim->loc, fd);
	ft_putstr_fd("\t\tDIR\t\t", fd);
	write_coord(prim->dir, fd);
	ft_putstr_fd("\t\tNORMAL\t", fd);
	write_coord(prim->normal, fd);
	ft_putstr_fd("\t\tRADIUS\t", fd);
	temp = ft_dtoa(prim->radius, 6);
	ft_putstr_fd(temp, fd);
	ft_putchar_fd('\n',fd);
	ft_strdel(&temp);
	ft_putstr_fd("\t\tANGLE\t", fd);
	temp = ft_dtoa(prim->angle, 6);
	ft_putstr_fd(temp, fd);
	ft_putchar_fd('\n',fd);
	ft_strdel(&temp);
	ft_putstr_fd("\t\tMATERIAL\t", fd);
	ft_putstr_fd(mat[prim->material]->name, fd);
	ft_putstr_fd("\n\n", fd);
}

void	save_prims(t_prim **prim, t_material **mat, size_t prims, int fd)
{
	size_t	i;

	i = 0;
	while (i < prims)
	{
		save_prim(prim[i], mat, fd);
		i++;
	}
}
