# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adippena <angusdippenaar@gmail.com>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/08/26 18:13:07 by adippena          #+#    #+#              #
#    Updated: 2016/08/27 11:55:44 by adippena         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libft.a
INCLUDE	=	-I include
CFLAGS	=	-Wall -Wextra -Werror -Ofast -Wno-unused-result

INC		=	$(shell find include -name "*.h")
SRC		=	$(shell find src -name "*.c")
OBJ		=	$(SRC:src/%.c=build/%.o)

all: $(NAME)

build/%.o: src/%.c $(INC)
	@echo "\033[94mLFT CC    $@\033[0m"
	@mkdir -p $(dir $@)
	@gcc $(CFLAGS) $(INCLUDE) -c $< -o $@

$(NAME): $(OBJ)
	@echo "\033[94mLFT AR    $@\033[0m"
	@ar cr $@ $^
	@ranlib $@

clean:
	@echo "\033[94mLFT RM    object files\033[0m"
	@rm -rf build

fclean: clean
	@echo "\033[94mLFT RM    $(NAME)\033[0m"
	@rm -f $(NAME)

re: fclean all
