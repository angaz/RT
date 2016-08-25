# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adippena <angusdippenaar@gmail.com>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/07/09 12:47:08 by adippena          #+#    #+#              #
#    Updated: 2016/08/25 17:05:37 by adippena         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	RT
LIBFT		=	-I libft/include -L libft -lft
SDL2		=	$(shell sdl2-config --cflags --libs)
INCLUDE		=	-I include
CFLAGS		=	-Wall -Wextra -Werror -pthread -O3 -g3
LIBS		=	-lm

## PLEASE TRY AND KEEP THE SOURCE FILES IN ALPHABETICAL ORDER ##

FREE		=	src/free/free_light.c				\
				src/free/free_material.c			\
				src/free/free_obj_vert.c			\
				src/free/free_object.c				\
				src/free/free_prim.c

INTERSECT	=	src/intersect/intersect_box.c		\
				src/intersect/intersect_scene.c		\
				src/intersect/intersect_sphere.c	\
				src/intersect/intersect_plane.c		\
				src/intersect/intersect_cylinder.c	\
				src/intersect/intersect_cone.c		\
				src/intersect/intersect_triangle.c	\
				src/intersect/intersect_object.c	\
				src/intersect/intersect_disk.c

READ_SCENE	=	src/read_scene/camera_values.c		\
				src/read_scene/light_values.c		\
				src/read_scene/material_values.c	\
				src/read_scene/object_values.c		\
				src/read_scene/primitive_values.c	\
				src/read_scene/read_colour.c		\
				src/read_scene/read_scene.c			\
				src/read_scene/read_obj.c			\
				src/read_scene/read_vector.c

MATHS		=	src/vector_maths/colour_to_unit.c	\
				src/vector_maths/vector_comp.c		\
				src/vector_maths/vector_add.c		\
				src/vector_maths/vector_cross.c		\
				src/vector_maths/vector_div.c		\
				src/vector_maths/vector_dot.c		\
				src/vector_maths/vector_mult.c		\
				src/vector_maths/vector_normalize.c	\
				src/vector_maths/vector_project.c	\
				src/vector_maths/vector_rot.c		\
				src/vector_maths/vector_sub.c		\
				src/vector_maths/vector_unit.c

SAVE		=	src/save/save.c						\
				src/save/save_lights.c				\
				src/save/save_materials.c			\
				src/save/save_objects.c				\
				src/save/save_prims.c				\
				src/save/write_coord.c

SRC			=	$(FREE)								\
				$(INTERSECT)						\
				$(MATHS)							\
				$(READ_SCENE)						\
				$(SAVE)								\
				src/camera_setup.c					\
				src/diffuse.c						\
				src/draw.c							\
				src/error.c							\
				src/init_env.c						\
				src/loop.c							\
				src/main.c							\
				src/shadow.c						\
				src/get_normal.c					\
				src/reflect.c						\
				src/refract.c						\
				src/find_colour_struct.c			\
				src/copy_env.c						\
				src/user_input/mouse_click.c		\
				src/user_input/key_press.c			\
				src/user_input/grab.c				\
				src/user_input/cam_move.c

all: $(NAME)

$(NAME):
	make -C libft all
	gcc $(CFLAGS) $(INCLUDE) $(SRC) $(SDL2) $(LIBFT) $(LIBS) -o $(NAME)

clean:
	make -C libft clean

fclean:
	make -C libft fclean
	rm -f $(NAME)
	rm -rf $(NAME).dSYM

re: fclean all

run:
	rm -f $(NAME)
	@$(MAKE) all
	@clear
