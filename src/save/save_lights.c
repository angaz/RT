/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_lights.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/15 13:52:36 by rojones           #+#    #+#             */
/*   Updated: 2016/08/16 09:49:44 by rojones          ###   ########.fr       */
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
	int		temp2;

	temp2 = 0;
	temp2 = (int)(col->r * 255.0);
	write_color_segment(temp2, fd);
	temp2 = 0;
	temp2 = (int)(col->g * 255.0);
	write_color_segment(temp2, fd);
	temp2 = 0;
	temp2 = (int)(col->b * 255.0);
	write_color_segment(temp2, fd);
	temp2 = 0;
	ft_putchar_fd('\n', fd);
}

static void	save_light(t_light *light, int fd)
{
	char	doub[20];

	ft_putstr_fd("\tLIGHT\n", fd);
	ft_putstr_fd("\t\tLOC\t\t\t", fd);
	write_coord(light->loc, fd);
	ft_putstr_fd("\t\tCOLOUR\t\t", fd);
	write_colour(&light->colour, fd);
	ft_putstr_fd("\t\tINTENSITY\t", fd);
	sprintf(doub, "%f\n", light->lm / 3.415);
	ft_putstr_fd(doub, fd);
	ft_bzero(doub, 20);
	ft_putstr_fd("\t\tHALF\t\t", fd);
	sprintf(doub, "%f\n\n", light->half);
	ft_putstr_fd(doub, fd);
	ft_bzero(doub, 20);
}

void		save_lights(t_light **lights, size_t num_light, int fd)
{
	size_t	i;

	i = 0;
	while (i < num_light)
	{
		save_light(lights[i], fd);
		i++;
	}
}
