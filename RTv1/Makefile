# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dtreutel <dtreutel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/30 10:04:46 by dtreutel          #+#    #+#              #
#    Updated: 2019/08/03 15:54:40 by dtreutel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = RTv1

SRC_DIR=./src
OBJ_DIR=./objects
C_FILES=	main.c \
			ft_exit.c \
			new_obj.c \
			ft_atof.c \
			trace_ray.c \
			pars_scene.c \
			dell_all_obj.c \
			ft_scan_digit.c \
			get_next_line.c \
			diffuse_reflection.c \

O_FILES = $(C_FILES:.c=.o)

SRC=$(addprefix $(SRC_DIR)/,$(C_FILES))
OBJ=$(addprefix $(OBJ_DIR)/,$(O_FILES))
LIBFT_A=./libft/libft.a
MLX=-L minilibx_macos -lmlx -framework OpenGL -framework AppKit
INCLUD=-I includes
WWW = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(LIBFT_A) $(OBJ_DIR) $(OBJ)
	gcc $(WWW) $(OBJ) $(LIBFT_A) $(INCLUD) $(MLX) -o $(NAME)

$(LIBFT_A):
	make -C libft
	make -C minilibx_macos

$(OBJ_DIR):
	mkdir $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c ./includes/rtv1.h
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
