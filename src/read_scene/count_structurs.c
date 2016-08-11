/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_structurs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/11 09:28:52 by rojones           #+#    #+#             */
/*   Updated: 2016/08/11 10:13:19 by rojones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static	void	inc_count(t_objcount *re, int fd, char *line)
{
	char	*temp_line;
	char	*temp_line2;

	temp_line = ft_strtrim(line);
		if (!ft_strcmp(temp_line, "OBJECT"))
			re->obj++;
		else if (!ft_strcmp(temp_line, "LIGHT"))
			re->light++;
		else if (!ft_strcmp(temp_line, "MATERIAL"))
			re->mat++;
		while (ft_gnl(fd, &temp_line2))
		{   
			if (temp_line2[0] == '\0')
			{   
				ft_strdel(&temp_line2);
				break ;
			}
			ft_strdel(&temp_line2);
		}	
		ft_strdel(&temp_line);
}

t_objcount	count_object(char *file, t_env *e)
{
	t_objcount	re;
	char		*temp_line;
	int			fd;

	re.obj = 0;
	re.light = 0;
	re.mat = 0;
	if ((fd = open(file, O_RDONLY)) == -1)
		err(FILE_OPEN_ERROR, "read_scene", e);
	if (!(ft_gnl(fd, &temp_line)))
		if (ft_strcmp(temp_line, "SCENE RT"))
			err(FILE_FORMAT_ERROR, "read_scene", e);
	ft_strdel(&temp_line);
	while (ft_gnl(fd, &temp_line))
	{
		if (temp_line[0] == '\0')
		{
			ft_strdel(&temp_line);
			break ;
		}
		ft_strdel(&temp_line);
	}
	while (ft_gnl(fd, &temp_line))
	{
		inc_count(&re, fd, temp_line);
		ft_strdel(&temp_line);
	}
	close(fd);
	return (re);
}
