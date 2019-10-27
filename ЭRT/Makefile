# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dtreutel <dtreutel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/30 10:04:46 by dtreutel          #+#    #+#              #
#    Updated: 2019/10/27 18:04:16 by dtreutel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all, $(NAME), norm, clean, fclean, re

NAME = RT

SRC_DIR=./src_RT

OBJ_DIR=./objects

C_FILES= \
			rays.c\
			main.c\
			matrix.c\
			shapes.c\
			tuples.c\
			intersect.c\
			custom_math.c\
			actions_with_pixels.c\


O_FILES = $(C_FILES:.c=.o)

SRC=$(addprefix $(SRC_DIR)/,$(C_FILES))

OBJ=$(addprefix $(OBJ_DIR)/,$(O_FILES))

LIBFT_A=./libft/libft.a


INCLUD		= \
			-I includes \
			-I SDL2/SDL2.framework/Headers \
			-I SDL2/SDL2_image.framework/Header/ \
			-I SDL2/SDL2_ttf.framework/Headers \
			-I SDL2/SDL2_mixer.framework/Headers

FRAMEWORK	= \
			SDL2/SDL2.framework SDL2/SDL2_image.framework \
			SDL2/SDL2_mixer.framework SDL2/SDL2_ttf.framework

FRAME_FLAGS	= \
			-F SDL2 -framework SDL2 \
			-F SDL2 -framework SDL2_image \
			-F SDL2 -framework SDL2_ttf \
			-F SDL2 -framework SDL2_mixer


WWW			= -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(LIBFT_A) $(OBJ_DIR) $(OBJ)
	gcc $(WWW) $(OBJ) $(INCLUD) $(LIBFT_A) $(FRAME_FLAGS) -o $(NAME)
	@install_name_tool -change @rpath/SDL2.framework/Versions/A/SDL2 SDL2/SDL2.framework/Versions/A/SDL2 $(NAME)
	@install_name_tool -change @rpath/SDL2_mixer.framework/Versions/A/SDL2_mixer SDL2/SDL2_mixer.framework/Versions/A/SDL2_mixer $(NAME)
	@install_name_tool -change @rpath/SDL2_image.framework/Versions/A/SDL2_image SDL2/SDL2_image.framework/Versions/A/SDL2_image $(NAME)
	@install_name_tool -change @rpath/SDL2_ttf.framework/Versions/A/SDL2_ttf SDL2/SDL2_ttf.framework/Versions/A/SDL2_ttf $(NAME)


$(LIBFT_A):
	make -C libft

$(OBJ_DIR):
	mkdir $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c ./includes/rt.h
	gcc $(INCLUD) $(WWW) -o $@ -c $<

clean:
	make clean -C libft
	rm -rf $(OBJ_DIR)
	make -C minilibx_macos clean

fclean: clean
	make fclean -C libft
	make -C minilibx_macos clean
	rm -rf $(NAME)

re: fclean all


#			hooks.c\
			new_obj.c\
			ft_exit.c\
			ft_atof.c\
			rotation.c\
			clr_cone.c\
			open_file.c\
			trace_ray.c\
			clr_plane.c\
			clr_sphere.c\
			pars_scene.c\
			valid_data.c\
			len_vector.c\
			dot_product.c\
			clr_cylinder.c\
			dell_all_obj.c\
			check_shadow.c\
			ft_scan_digit.c\
			get_next_line.c\
			nearest_object.c\
			diffuse_reflection.c\
			operation_with_point.c\
			set_shape_and_lights.c\
			normal_intersection_dot.c\
			roots_quadratic_equation.c\
