/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_coord.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/15 13:51:06 by rojones           #+#    #+#             */
/*   Updated: 2016/08/15 16:40:32 by rojones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	write_coord(t_vector v, int fd) 
{
	char    *temp;

	temp = ft_dtoa(v.x, 6); 
	ft_putstr_fd(temp, fd);
	ft_putstr_fd(" ", fd);
	if (temp)
		free(temp);
	temp = ft_dtoa(v.y, 6); 
	ft_putstr_fd(temp, fd);
	ft_putstr_fd(" ", fd);
	if (temp)
		free(temp);
	temp = ft_dtoa(v.z, 6); 
	ft_putstr_fd(temp, fd);
	ft_putstr_fd("\n", fd);
	if (temp)
		free(temp);
}

