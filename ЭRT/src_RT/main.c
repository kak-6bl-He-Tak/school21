/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtreutel <dtreutel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 12:50:02 by dtreutel          #+#    #+#             */
/*   Updated: 2019/10/24 20:49:37 by dtreutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"


typedef struct	s_project
{
	t_tuple	pos;
	t_tuple	velosity;
}				t_project;



void one_tick(t_project *proj, t_rt *rt)
{
	proj->pos = add_tuples(proj->pos, proj->velosity);
	proj->velosity = add_tuples(proj->velosity, rt->gravity);
	proj->velosity = add_tuples(proj->velosity, rt->wind);
}


void test(t_rt *rt)
{
	t_project azaza;
	int i = -1;

	azaza.pos = new_vector(0, 1, 0);
	azaza.velosity = new_vector(1, 1.8, 0);
	azaza.velosity = norm_vector(azaza.velosity);
	azaza.velosity = multiply_tuple_with_scal(azaza.velosity, 11.25);
	while (++i < 200)
	{
		set_pixel_sdl(rt->surfase_window, azaza.pos.x, azaza.pos.y, 0xff);
		one_tick(&azaza, rt);
	}
}


int		init_sdl(t_rt *rt)
{
	if (!(rt->window = SDL_CreateWindow("RTv1", SDL_WINDOWPOS_CENTERED, \
		SDL_WINDOWPOS_CENTERED, W, H, SDL_WINDOW_SHOWN)))
		return (FAIL);
	rt->surfase_window = SDL_GetWindowSurface(rt->window);


	rt->wind = new_vector(-0.01, 0.0, 0.0);
	rt->gravity = new_vector(0, -0.1, 0);

	return (SUCCESS);
}

void	print_matrix(t_matrix *a)
{
	float **mat = a->matrix;
	int y = -1;
	int x;

	while (++y < a->size)
	{
		x = -1;
		while (++x < a->size)
		{
			printf("%f | ", mat[y][x]);
		}
		printf("\n");
	}
		printf("___________");

}

void	print_tuples(t_tuple a)
{
	printf("x = %f, y = %f, z = %f, w = %f", a.x, a.y, a.z, a.w);
}


int		main(/*int argc, char **argv*/)
{
	t_rt rt;

	if (init_sdl(&rt) == FAIL)
	{
		ft_putendl("fail SDL");
		return(1);
	}
	clear_surface(rt.surfase_window, rt.surfase_window->w, rt.surfase_window->h);

	t_matrix *a = new_matrix(4);
	a->matrix [0][0] = 1.0;
	a->matrix [0][1] = 2.0;
	a->matrix [0][2] = 3.0;
	a->matrix [0][3] = 4.0;

	a->matrix [1][0] = 2.0;
	a->matrix [1][1] = 4.0;
	a->matrix [1][2] = 4.0;
	a->matrix [1][3] = 2.0;

	a->matrix [2][0] = 8.0;
	a->matrix [2][1] = 6.0;
	a->matrix [2][2] = 4.0;
	a->matrix [2][3] = 1.0;

	a->matrix [3][0] = 0.0;
	a->matrix [3][1] = 0.0;
	a->matrix [3][2] = 0.0;
	a->matrix [3][3] = 1.0;

	// t_tuple b = new_point(1.0, 2.0, 3.0);
	// t_tuple aza = multiply_matrix_with_tuple(a, b);

	t_matrix *c = new_matrix(4);
	c = multiply_identity_matrix(a, c);
	// print_matrix(c);


	while (1)
	{
		if (SDL_PollEvent(&(rt.event)))
		{
			if (SDL_QUIT == rt.event.type)
				break ;
			if (SDLK_ESCAPE == rt.event.key.keysym.sym)
				break ;
			SDL_UpdateWindowSurface(rt.window);
		}
	}
	return(0);
}
