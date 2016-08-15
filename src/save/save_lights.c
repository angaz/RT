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

static int	get_col(t_colour *col)
{
	int	re;

	re = 0;
	re |= (int)(col->r * 255) << 16;
	re |= (int)(col->g * 255) << 8;
	re |= (int)(col->b * 255);
	return (re);
}

static void	save_light(t_light *light, int fd)
{
	int		tcol;
	char	*temp;

	tcol = get_col(&light->colour);
	temp = ft_itoa_base(tcol, 16);
	ft_putstr_fd("\tLIGHT\n", fd);
	ft_putstr_fd("\t\tLOC\t" ,fd);
	write_coord(light->loc, fd);
	ft_putstr_fd("\t\tCOLOUR\t", fd);
	ft_putstr_fd(temp, fd);
	ft_strdel(&temp);
	ft_putchar_fd('\n',fd);
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
