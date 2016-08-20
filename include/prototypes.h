/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prototypes.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adippena <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/26 14:49:05 by adippena          #+#    #+#             */
/*   Updated: 2016/08/20 09:26:54 by rojones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTOTYPES_H
# define PROTOTYPES_H

/*
** src/vector_maths
*/
double		vdot(t_vector v1, t_vector v2);
double		vnormalize(t_vector v);
t_vector	vmult(t_vector v, double s);
t_vector	vdiv(t_vector v, double d);
t_vector	vadd(t_vector v1, t_vector v2);
t_vector	vsub(t_vector v1, t_vector v2);
t_vector	vcross(t_vector v1, t_vector v2);
t_vector	vunit(t_vector v);
t_vector	vproject(t_vector a, t_vector b);
t_vector	colour_to_vector(t_colour colour);
int			vcomp(t_vector v1, t_vector v2);
t_vector	vrotx(t_vector v, double angle);
t_vector	vroty(t_vector v, double angle);
t_vector	vrotz(t_vector v, double angle);
t_vector	vrot(t_vector v, double angle);

/*
** src/loop.c
*/
void		event_loop(t_env *e);

/*
** src/init_env.c
*/
void		init_env(t_env *e);
void		nullify_pointers(t_env *e);

/*
** src/error.c
*/
void		err(int error_no, char *function, t_env *e);
void		exit_rt(t_env *e, int code);

/*
** src/read_scene
*/
void		read_scene(char *file, t_env *e);
void		get_primitive_attributes(t_env *e, int fd);
void		get_object_attributes(t_env *e, int fd);
size_t		get_material_number(t_env *e, char *str);
void		get_camera_attributes(t_env *e, int fd);
void		get_light_attributes(t_env *e, int fd);
t_colour	get_colour(t_env *e, t_split_string values);
t_vector	get_vector(t_env *e, t_split_string values);
t_vector	get_unit_vector(t_env *e, t_split_string values);
void		get_tri(t_env *e, t_prim *o, t_split_string *values);
void		get_material_attributes(t_env *e, int fd);
void		read_obj(t_env *e, int fd);
void		init_material(t_material *m);

/*
** src/draw.c
*/
void		draw(t_env *e, SDL_Rect draw);
int			intersect_prim(t_env *e, t_ray *ray, size_t prim, double *t);

/*
** src/free
*/
void    free_light(t_light **light, size_t num_light);
void    free_material(t_material **material, size_t num_mat);
void	free_obj_vert(void **v, size_t num_v);
void    free_object(t_object **obj, size_t num_obj);
void    free_prim(t_prim ***prim, size_t num_prim);

/*
** src/intersect
*/
void		intersect_scene(t_env *e);
int			intersect_sphere(t_ray *r, t_prim *s, double *t);
int			intersect_plane(t_ray *r, t_prim *o, double *t);
int			intersect_cylinder(t_ray *r, t_prim *o, double *t);
int			intersect_cone(t_ray *r, t_prim *o, double *t);
int			intersect_disk(t_ray *r, t_prim *o, double *t);
int			intersect_triangle(t_ray *r, t_face *f, double *t);
int			intersect_box(t_ray *r, t_vector box[2]);
int			intersect_object(t_env *e, t_object *o, double *t);

/*
** src/save
*/
void    save(t_env *e);
void    save_lights(t_light **lights, size_t num_light, int fd);
void    save_materials(t_material **material, size_t materials, int fd);
void    save_objects(t_object **obj, size_t objects, t_material **mat, int fd);
void    save_prims(t_prim **prim, t_material **mat, size_t prims, int fd);
void	write_coord(t_vector v, int fd);

/*
** src/diffuse.c
*/
t_colour	prim_diffuse(t_env *e);
t_colour	face_diffuse(t_env *e);

/*
** src/find_colour_struct.c
*/
t_colour    find_colour_struct(t_env *e, int depth);

/*
** src/reflect.c
*/
t_colour    reflect(t_env *e, int depth);

/*
** src/refract.c
*/
t_colour    refract(t_env *e, int depth, t_colour colour);

/*
** src/shadow.c
*/
int			in_shadow(t_env *e, t_light *light);

/*
** src/camera_setup.c
*/
void		setup_camera_plane(t_env *e, t_camera_ray *c);
void		get_ray_dir(t_env *e, t_camera_ray *cr, double x, double y);

/*
** src/get_normal.c
*/
t_vector    get_normal(t_env *e, t_vector ray);

/*
** src/copy_env.c
*/
t_env	*copy_env(t_env *e);

/*
** src/read_file/count_structurs.c
*/
//t_objcount  count_object(char *file, t_env *e);

#endif
