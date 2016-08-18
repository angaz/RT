/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adippena <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/26 14:48:30 by adippena          #+#    #+#             */
/*   Updated: 2016/08/17 18:21:19 by arnovan-         ###   ########.fr       */
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
	double		reflect;
	double		refract;
	double		ior;
	t_colour	diff;
	t_colour	spec;
}				t_material;

/*
** OBJECT STRUCTURE
*/

typedef struct	s_face
{
	t_vector	*v0;
	t_vector	*v1;
	t_vector	*v2;
	t_vector	*n;
}				t_face;

typedef struct	s_object
{
	char		*name;
	t_face		**face;
	size_t		faces;
	size_t		material;
	t_vector	**v;
	size_t		verticies;
	t_vector	**vn;
	size_t		vnormals;
	t_vector	box[2];
}				t_object;

typedef struct	s_prim
{
	t_vector	loc;
	t_vector	dir;
	t_vector	normal;
	int			type;
	int			select;
	size_t		material;
	double		radius;
	double		angle;
}				t_prim;

/*
** RAY, CAMERA AND LIGHT STRUCTURE
*/
typedef struct	s_ray
{
	double		ior;
	t_vector	loc;
	t_vector	dir;
	t_prim		*p_in;
	t_object	*o_in;
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

/*
** KEYBOARD HANDLER & MOUSE STRUCTURE
*/
typedef struct	s_key
{
	int		shift;
	int		g;
	int		s;
	int		r;
	int		x;
	int		y;
	int		z;
}				t_key;

typedef struct	s_click
{
	int				mouse_x;
	int				mouse_y;
	t_camera_ray	ray_cam;
}				t_click;

/*
** SELECTED PRIMITIVE LIST STRUCTURE
*/
typedef struct	s_sel_list
{
	t_prim				primitive;
	struct s_sel_list	*next;
}				t_sel_list;

/*
** ENVIRNMENT STRUCTURE
*/
typedef struct	s_env
{
	SDL_Window		*win;
	SDL_Renderer	*rend;
	SDL_Texture		*img;
	void			*px;
	char			*file_name;
	int				px_pitch;
	t_ray			ray;
	t_camera		camera;
	t_prim			*p_hit;
	t_prim			*selected;
	size_t			selects;
	t_vector		orig_loc;
	size_t			hit_type;
	t_prim			**prim;
	size_t			prims;
	t_face			*o_hit;
	t_object		*object_hit;
	t_object		**object;
	size_t			objects;
	t_light			**light;
	size_t			lights;
	t_material		**material;
	size_t			materials;
	double			t;
	int				maxdepth;
	t_key			key;
	t_click			click;
}				t_env;

#endif
