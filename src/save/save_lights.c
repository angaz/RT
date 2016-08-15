/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_lights.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/15 13:52:36 by rojones           #+#    #+#             */
/*   Updated: 2016/08/15 17:45:03 by rojones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void write_color_segment(int col, int fd)
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
    temp2 |= (int)(col->r * 255) << 16;
    write_color_segmen(temp2, fd);
    temp2 = 0;
    temp2 |= (int)(col->g * 255) << 8;
    write_color_segmen(temp2, fd);
    temp2 = 0;
    temp2 |= (int)(col->b * 255);
    write_color_segmen(temp2, fd);
    temp2 = 0;
    ft_putchar_fd('\n', fd);
}

static void	save_light(t_light *light, int fd)
{
	char	*temp;

	ft_putstr_fd("\tLIGHT\n", fd);
	ft_putstr_fd("\t\tLOC\t" ,fd);
	write_coord(light->loc, fd);
	ft_putstr_fd("\t\tCOLOUR\t", fd);
    write_colour(light->colour, fd);
	ft_putstr_fd("\t\tINTENSITY\t", fd);
	temp = ft_dtoa(light->lm / 3.415, 6);
	ft_putstr_fd(temp, fd);
	ft_strdel(&temp);
	ft_putchar_fd('\n', fd);
	ft_putstr_fd("\t\tHALF\t", fd);
	temp = ft_dtoa(light->half, 6);
	ft_putstr_fd(temp, fd);
	ft_strdel(&temp);
	ft_putstr_fd("\n\n", fd);
}

void	save_lights(t_light **lights, size_t num_light, int fd)
{
	size_t	i;

	i = 0;
	while (i < num_light)
	{
		save_light(lights[i], fd);
		i++;
	}
}
