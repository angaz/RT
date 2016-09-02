/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adippena <angusdippenaar@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/08 19:58:53 by adippena          #+#    #+#             */
/*   Updated: 2016/08/28 23:46:50 by adippena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	exit_rt(t_env *e, int code)
{
	if (code != USAGE_ERROR)
	{
		if (e->file_name)
			free(e->file_name);
		if (e->img)
			SDL_FreeSurface(e->img);
		if (e->win)
			SDL_DestroyWindow(e->win);
		free_light(e->light, e->lights);
		free_material(e->material, e->materials);
		free_object(e->object, e->objects);
		free_prim(&e->prim, e->prims);
	}
	SDL_Quit();
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
	exit_rt(e, error_no);
}
