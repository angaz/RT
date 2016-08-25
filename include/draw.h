/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adippena <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/17 11:01:32 by adippena          #+#    #+#             */
/*   Updated: 2016/08/22 19:39:59 by adippena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_H
# define DRAW_H

# include "rt.h"

typedef struct	s_chunk
{
	t_env			*e;
	SDL_Rect		d;
	t_camera_ray	cr;
	size_t			pixel;
	int				stopx;
	int				stopy;
	int				x;
}				t_chunk;

typedef struct	s_make_chunks
{
	size_t			tids;
	size_t			thread;
	size_t			chunk_x;
	size_t			chunk_y;
	pthread_t		*tid;
	t_camera_ray	cr;
	t_chunk			*c;
}				t_make_chunks;

#endif
