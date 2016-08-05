/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adippena <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/26 14:48:30 by adippena          #+#    #+#             */
/*   Updated: 2016/08/05 10:34:45 by adippena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

/*
** 3D VECTOR STRUCTURE
*/
typedef struct	s_vector
{
	double	x;
	double	y;
	double	z;
}				t_vector;

/*
** MATERIAL AND COLOUR STRUCTURES
*/
typedef struct	s_colour
{
	double	r;
	double	g;
	double	b;
	double	intensity;
}				t_colour;

typedef struct	s_material
{
	char		*name;
	t_colour	diff;
	t_colour	spec;
}				t_material;

/*
** OBJECT STRUCTURE
*/
typedef struct	s_object
{
	int			type;
	size_t		material;
	double		radius;
	double		angle;
	t_vector	loc;
	t_vector	dir;
	t_vector	normal;
}				t_object;

/*
** RAY, CAMERA AND LIGHT STRUCTURE
*/
typedef struct	s_ray
{
	t_vector	loc;
	t_vector	dir;
}				t_ray;

typedef struct	s_camera
{
	t_vector	loc;
	t_vector	dir;
	t_vector	up;
}				t_camera;

typedef struct	s_light
{
	t_vector	loc;
	t_colour	colour;
	double		lm;
	double		half;
}				t_light;

/*
** ENVIRNMENT STRUCTURE
*/
typedef struct	s_env
{
	SDL_Window		*win;
	SDL_Renderer	*rend;
	SDL_Texture		*img;
	void			*px;
	int				px_pitch;
	t_ray			ray;
	t_camera		camera;
	t_object		*hit;
	t_object		**object;
	size_t			objects;
	t_light			**light;
	size_t			lights;
	t_material		**material;
	size_t			materials;
	double			t;
}				t_env;

typedef struct	s_camera_ray
{
	t_vector	n;
	t_vector	u;
	t_vector	v;
	t_vector	l;
	t_vector	c;
	double		d;
	double		w;
	double		h;
}				t_camera_ray;

#endif
