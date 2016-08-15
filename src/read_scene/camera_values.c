/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_values.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adippena <angusdippenaar@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/09 12:24:39 by adippena          #+#    #+#             */
/*   Updated: 2016/08/15 16:24:21 by rojones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void	set_camera_values(t_env *e, char *pt1, char *pt2)
{
	t_split_string	values;

	values = ft_nstrsplit(pt2, ' ');
	if (!ft_strcmp(pt1, "LOC"))
		e->camera.loc = get_vector(e, values);
	else if (!ft_strcmp(pt1, "DIR"))
		e->camera.dir = get_vector(e, values);
	else if (!ft_strcmp(pt1, "UP"))
		e->camera.up = get_vector(e, values);
	ft_free_split(&values);
}

void		get_camera_attributes(t_env *e, int fd)
{
	t_split_string	attr;
	char			*temp_line;

	attr.words = 0;
	while (ft_gnl(fd, &temp_line))
	{
		if (temp_line[0] == '\0')
		{
			ft_strdel(&temp_line);
			break ;
		}
		attr = ft_nstrsplit(temp_line, '\t');
		ft_strdel(&temp_line);
		if (attr.words < 2)
			err(FILE_FORMAT_ERROR, "get_camera_attributes", e);
		set_camera_values(e, &attr.strings[0][0], &attr.strings[1][0]);
		ft_free_split(&attr);
	}
}
