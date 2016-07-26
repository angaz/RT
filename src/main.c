/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adippena <angusdippenaar@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/08 20:00:35 by adippena          #+#    #+#             */
/*   Updated: 2016/07/26 17:25:47 by adippena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int		main(int ac, char **av)
{
	t_env	e;

	nullify_pointers(&e);
	if (ac != 2)
		err(USAGE_ERROR, NULL, &e);
	init_env(&e, av);
	draw(&e, (SDL_Rect){0, 0, WIN_X, WIN_Y});
	event_loop(&e);
	return (0);
}
