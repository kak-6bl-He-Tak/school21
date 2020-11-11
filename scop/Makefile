

NAME:=scop
#LINKING:=-framework OpenGL -framework AppKit
LINKING_LGFW:= -lft# -lglfw3 -framework OpenGL -framework AppKit
INCLUDES:=-I includes -I glfw/include
#MINLIBX=-L minilibx_macos -lmlx $(LINKING)
WWW=-Wall -Wextra -Werror

LIBRS := -L./libft# -L./glfw/lib-macos


.PHONY: all clean fclean re libft

$(NAME): libft
	gcc $(WWW) $(LIBRS) $(LINKING_LGFW) $(INCLUDES) main.c -o $(NAME) -v

libft:
	make -C ./libft


clean:
	make clean -C ./libft

fclean: clean
	make fclean -C ./libft
	rm -f $(NAME)


re: fclean
	$(NAME)
