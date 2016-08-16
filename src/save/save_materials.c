/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_materials.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/15 14:39:54 by rojones           #+#    #+#             */
/*   Updated: 2016/08/16 10:10:51 by rojones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void	write_color_segment(int col, int fd)
{
	char *temp;

	if (col != 0)
	{
		temp = ft_itoa_base(col, 16);
		ft_putstr_fd(temp, fd);
		ft_strdel(&temp);
	}
	else
		ft_putstr_fd("00", fd);
}

static void	write_colour(t_colour *col, int fd)
{
	char	temp[20];
	int		temp2;

	temp2 = 0;
	temp2 = (int)((col->r * 255.0));
	write_color_segment(temp2, fd);
	temp2 = 0;
	temp2 = (int)((col->g * 255.0));
	write_color_segment(temp2, fd);
	temp2 = 0;
	temp2 = (int)((col->b * 255.0));
	write_color_segment(temp2, fd);
	sprintf(temp, "\t%f\n", col->intensity);
	ft_putstr_fd(temp, fd);
}

static void	save_mat(t_material *mat, int fd)
{
	char	temp[20];

	ft_putstr_fd("\tMATERIAL\n", fd);
	ft_putstr_fd("\t\tNAME\t\t", fd);
	ft_putstr_fd(mat->name, fd);
	ft_putchar_fd('\n', fd);
	ft_putstr_fd("\t\tDIFFUSE\t\t", fd);
	write_colour(&mat->diff, fd);
	ft_putstr_fd("\t\tSPECULAR\t", fd);
	write_colour(&mat->spec, fd);
	ft_putstr_fd("\t\tREFLECT\t\t", fd);
	sprintf(temp, "%f\n", mat->reflect);
	ft_putstr_fd(temp, fd);
	ft_bzero(temp, 20);
	ft_putstr_fd("\t\tREFRACT\t\t", fd);
	sprintf(temp, "%f\n", mat->refract);
	ft_putstr_fd(temp, fd);
	ft_bzero(temp, 20);
	ft_putstr_fd("\t\tIOR\t\t\t", fd);
	sprintf(temp, "%f\n\n", mat->ior);
	ft_putstr_fd(temp, fd);
}

void		save_materials(t_material **material, size_t materials, int fd)
{
	size_t	i;

	i = 1;
	while (i < materials)
	{
		save_mat(material[i], fd);
		i++;
	}
}
