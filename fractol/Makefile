# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dtreutel <dtreutel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/21 18:00:07 by dtreutel          #+#    #+#              #
#    Updated: 2019/03/21 18:22:56 by dtreutel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=fractol
LINKING=-framework OpenGL -framework AppKit
HEADER=includes/fractol.h
SRCS_DIR=./src
OBJS_DIR=./objects
LIBFT_DIR=./libft
RAW_SRCS=\
	burningass.c\
    burningship.c\
    clr_step.c\
    factors_init.c\
    fractol.c\
    ft_exit.c\
    julia.c\
    key_move.c\
    main.c\
    mandelbrot.c\
    mouse_move.c\
    mouse_press.c\
    put_buttom_const.c\
    put_buttom_fract.c\
    put_buttom_iter.c\
    put_fractol.c\
    put_line.c\
    set_pxl.c\
    zoom.c

RAW_OBJS=$(RAW_SRCS:.c=.o)
SRCS=$(addprefix $(SRCS_DIR)/,$(RAW_SRCS))
OBJS=$(addprefix $(OBJS_DIR)/,$(RAW_OBJS))
OBJS_CLEAN=$(strip $(foreach f,$(OBJS),$(wildcard $(f))))
NAME_CLEAN=$(strip $(NAME))
LIBFT_A=$(LIBFT_DIR)/libft.a
MINLIBX=-L minilibx_macos -lmlx $(LINKING)
INCLUDES:=-I includes -I $(LIBFT_DIR)/includes
FLAGS=-Wall -Wextra -Werror

RED=\033[0;31m
GREEN=\033[0;32m
BLUE=\033[0;34m
NC=\033[0mmake fclean

.PHONY: all clean fclean re

all: $(NAME)

$(OBJS_DIR):
	@echo "$(BLUE)Compiling $(NAME_CLEAN) objects files..."
	@mkdir -p $(OBJS_DIR)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c $(HEADER)
	@gcc $(INCLUDES) $(FLAGS) -o $@ -c $<

$(LIBFT_A):
	@make -C $(LIBFT_DIR)

$(NAME): $(LIBFT_A) $(OBJS_DIR) $(OBJS)
	@echo "$(BLUE)Compiling executable..."
	@gcc $(OBJS) $(LIBFT_A) $(INCLUDES) $(FLAGS) -o $(NAME) $(MINLIBX)
	@echo "$(GREEN)Bin $(NAME) is ready to use!"

clean:
ifneq ($(OBJS_CLEAN),)
	@make clean -C $(LIBFT_DIR)
	@rm -rf $(OBJS_DIR)
	@make -C minilibx_macos clean
	@echo "$(RED)$(NAME_CLEAN) objects files removed."
else
	@echo "$(RED)$(NAME_CLEAN) objects already cleaned"
endif

fclean: clean
ifneq ($(NAME_CLEAN),)
	@make fclean -C $(LIBFT_DIR)
	@rm -rf $(OBJS_DIR)
	@rm -rf $(NAME)
	@echo "$(RED)Bin $(NAME_CLEAN) removed."
else
	@echo "$(RED)Objects and bin $(NAME_CLEAN) already cleaned$"
endif

test:
	gcc $(FLAGS) -g $(SRCS) -o $(NAME) $(INCLUDES) $(LIBFT_A)

re: fclean all
