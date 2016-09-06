/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adippena <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/17 11:01:32 by adippena          #+#    #+#             */
/*   Updated: 2016/09/03 16:06:46 by adippena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_H
# define DRAW_H

# include "rt.h"
# include <sys/time.h>

typedef struct	s_chunk
{
	t_env			*e;
	SDL_Rect		d;
	uint32_t		*px;
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
	t_chunk			*c;
}				t_make_chunks;

typedef struct	s_render
{
	size_t		i;
	double		angle;
	double		angle_step;
	t_vector	cam_origin;
}				t_render;

#endif
