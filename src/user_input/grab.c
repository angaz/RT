/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grab.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arnovan- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/15 17:07:36 by arnovan-          #+#    #+#             */
/*   Updated: 2016/08/16 18:27:59 by arnovan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	grab(t_env *e, SDL_Event event)
{
	SDL_SetRelativeMouseMode(1);
	if (e->p_selected)
	{
		if (e->orig_loc.x == 0 && e->orig_loc.y == 0 && e->orig_loc.z == 0)
			e->orig_loc = (t_vector)
		{e->p_selected->loc.x, e->p_selected->loc.y, e->p_selected->loc.z};
		draw(e, (SDL_Rect){0, 0, WIN_X, WIN_Y});	
		e->p_selected->loc.x += (double)event.motion.xrel * 0.015;
		e->p_selected->loc.z -= (double)event.motion.yrel * 0.015;
		draw(e, (SDL_Rect){0, 0, WIN_X, WIN_Y});	
	}
}
