NAME = fdf

LINKING = -framework OpenGL -framework AppKit

FUNCT = lfdf/*.c

all: $(NAME)

$(NAME):
	make -C libft fclean && make -C libft
	make -C minilibx_macos clean && make -C minilibx_macos
	cc -o $(NAME) -I includes main.c $(FUNCT) -L minilibx_macos -lmlx $(LINKING) -L libft -lft

clean:
	rm -f *.o
	make -C libft fclean
	make -C minilibx_macos clean

fclean: clean
	rm -f $(NAME)

re: fclean all
