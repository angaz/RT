# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adippena <angusdippenaar@gmail.com>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/07/09 12:47:08 by adippena          #+#    #+#              #
#    Updated: 2016/08/01 20:00:37 by adippena         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= RT
LIBFT	= -I libft/include -L libft -lft
SDL2	= $(shell sdl2-config --cflags --libs)
INCLUDE	= -I include
CFLAGS	= -Wall -Wextra -Werror -pthread
LIBS	= -lm

SRC		=	src/main.c					\
			src/vector_maths.c			\
			src/vector_maths2.c			\
			src/loop.c					\
			src/error.c					\
			src/init_env.c				\
			src/read_scene.c			\
			src/camera_values.c			\
			src/material_values.c		\
			src/object_values.c			\
			src/light_values.c			\
			src/draw.c					\
			src/intersect_scene.c		\
			src/intersect_sphere.c		\
			src/intersect_plane.c		\
			src/intersect_cylinder.c	\
			src/intersect_cone.c		\
			src/diffuse.c				\
			src/shadow.c

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
	@./$(NAME) scene
