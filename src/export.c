/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adippena <angusdippenaar@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/31 20:35:15 by adippena          #+#    #+#             */
/*   Updated: 2016/09/04 12:12:13 by adippena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void		write_image(t_env *e, int fd)
{
	size_t		total;
	size_t		index;
	uint32_t	px;
	uint32_t	px_rgb;

	total = e->x * e->y;
	index = 0;
	while (index != total)
	{
		px = e->px[index++];
		px_rgb = ((px & 0xFF) << 16) | (px & 0xFF00) | ((px & 0xFF0000) >> 16);
		write(fd, &px_rgb, 3);
	}
}

void			export(t_env *e)
{
	int		fd;
	char	*temp;

	ft_putstr("Exporting rendered image... ");
	temp = NULL;
	ft_sprintf(&temp, "%s_%d.ppm", e->file_name, time(NULL));
	if ((fd = open(temp, O_WRONLY | O_TRUNC | O_CREAT, 0666)) == -1)
		err(FILE_OPEN_ERROR, "Could not export rendered image", e);
	ft_strdel(&temp);
	ft_putendl_fd("P6\n# Exported by the best RT project ever!", fd);
	temp = ft_itoa(e->x);
	ft_putstr_fd(temp, fd);
	ft_putstr_fd(" ", fd);
	ft_strdel(&temp);
	temp = ft_itoa(e->y);
	ft_putendl_fd(temp, fd);
	ft_putendl_fd("255", fd);
	write_image(e, fd);
	close(fd);
	ft_putstr("Done\n");
}
