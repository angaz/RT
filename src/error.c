/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adippena <angusdippenaar@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/08 19:58:53 by adippena          #+#    #+#             */
/*   Updated: 2016/07/09 22:34:33 by adippena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	exit_rt(t_env *e)
{
	if (e->img)
		SDL_DestroyTexture(e->img);
	if (e->rend)
		SDL_DestroyRenderer(e->rend);
	if (e->win)
		SDL_DestroyWindow(e->win);
	exit(0);
}

void	err(int error_no, char *function, t_env *e)
{
	char	*error;

	ft_putstr("\e[1;91mERROR:\e[0m ");
	if (error_no == FILE_OPEN_ERROR)
		error = ft_strjoin(function, ": File open error");
	else if (error_no == MALLOC_ERROR)
		error = ft_strjoin(function, ": Malloc error");
	else if (error_no == FREE_ERROR)
		error = ft_strjoin(function, ": Free error");
	else if (error_no == FILE_FORMAT_ERROR)
		error = ft_strjoin(function, ": Invalid file format");
	else if (error_no == USAGE_ERROR)
		error = "Invalid Usage\n    ./RTv1 [SCENE FILE]";
	if (error_no > 15)
		ft_putendl(error);
	else
		perror(error);
	if (error_no < 32)
		ft_strdel(&error);
	exit_rt(e);
}
