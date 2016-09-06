/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_objects.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/15 15:50:56 by rojones           #+#    #+#             */
/*   Updated: 2016/09/04 12:03:08 by adippena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void	save_object(t_object *obj, t_material **mat, int fd)
{
	ft_putstr_fd("\n\tOBJECT\n", fd);
	ft_putstr_fd("\t\tFILE\t\t", fd);
	ft_putstr_fd(obj->name, fd);
	ft_putchar_fd('\n', fd);
	ft_putstr_fd("\t\tMATERIAL\t", fd);
	ft_putstr_fd(mat[obj->material]->name, fd);
	ft_putstr_fd("\n", fd);
}

void		save_objects(t_object **o, size_t objects, t_material **m, int fd)
{
	size_t	i;

	i = 0;
	while (i < objects)
		save_object(o[i++], m, fd);
}
