/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_materials.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/15 14:39:54 by rojones           #+#    #+#             */
/*   Updated: 2016/08/15 18:03:15 by rojones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void	write_colour(t_colour *col, int fd)
{
	char	*temp;
	int		temp2;

	temp2 = 0;
	temp2 |= (int)(col->r * 255) << 16;
	temp2 |= (int)(col->g * 255) << 8;
	temp2 |= (int)(col->b * 255);
	ft_printf("color %d \n", temp2);
	temp = ft_itoa_base(temp2, 16);
	ft_putstr_fd(temp, fd);
	ft_putchar_fd('\t', fd);
	ft_strdel(&temp);
	temp = ft_dtoa(col->intensity, 6);
	ft_putstr_fd(temp, fd);
	ft_strdel(&temp);
	ft_putchar_fd('\n', fd);
}

static void	save_mat(t_material *mat, int fd)
{
	char	*temp;

	ft_putstr_fd("\tMATERIAL\n", fd);
	ft_putstr_fd("\t\tNAME\t\t", fd);
	ft_putstr_fd(mat->name, fd);
	ft_putchar_fd('\n', fd);
	ft_putstr_fd("\t\tDIFFUSE\t", fd);
	write_colour(&mat->diff, fd);
	ft_putstr_fd("\t\tSPECULAR\t", fd);
	write_colour(&mat->spec, fd);
	ft_putstr_fd("\t\tREFLECT\t", fd);
	temp = ft_dtoa(mat->reflect, 6);
	ft_putstr_fd(temp, fd);
	ft_putchar_fd('\n', fd);
	ft_strdel(&temp);
	ft_putstr_fd("\t\tREFRACT\t", fd);
	temp = ft_dtoa(mat->refract, 6);
	ft_putstr_fd(temp, fd);
	ft_putchar_fd('\n', fd);
	ft_strdel(&temp);
	ft_putstr_fd("\t\tIOR\t", fd);
	temp = ft_dtoa(mat->ior, 6);
	ft_putstr_fd(temp, fd);
	ft_putstr_fd("\n\n", fd);
	ft_strdel(&temp);
}

void	save_materials(t_material **material, size_t materials, int fd)
{
	size_t	i;

	i = 1;
	while(i < materials)
	{
		save_mat(material[i], fd);
		i++;
	}
}
