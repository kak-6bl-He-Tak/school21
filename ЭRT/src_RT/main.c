/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtreutel <dtreutel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 12:50:02 by dtreutel          #+#    #+#             */
/*   Updated: 2019/10/23 22:23:22 by dtreutel         ###   ########.fr       */
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


int		main(/*int argc, char **argv*/)
{
	t_rt rt;

	if (init_sdl(&rt) == FAIL)
	{
		ft_putendl("fail SDL");
		return(1);
	}
	clear_surface(rt.surfase_window, rt.surfase_window->w, rt.surfase_window->h);

	t_matrix *a = new_matrix(3);
	t_matrix *b = new_matrix(3);
	b->matrix[2][2] = 1.1;
	ft_putnbr(equal_matrix(a, b));



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
