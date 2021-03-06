/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtreutel <dtreutel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 12:59:53 by dtreutel          #+#    #+#             */
/*   Updated: 2019/10/27 17:54:08 by dtreutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_H
# define RT_H

# include "shapes.h"
# include <math.h>
# include "libft.h"
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>

# include <SDL.h>
// # include <SDL_image.h>
// # include <SDL_ttf.h>
// # include <SDL_mixer.h>

# define W	1300
# define H	1300

# define BUFF_SIZE 111
# define BG_CLR 0
# define SUCCESS 0
# define FAIL 1
# define EPSILON 0.00001



typedef struct		s_matrix
{
	int				size;
	float			**matrix;
}					t_matrix;

typedef struct		s_color
{
	float			r;
	float			g;
	float			b;
}					t_color;

typedef struct		s_tuple
{
	float			x;
	float			y;
	float			z;
	float			w;
}					t_tuple;

typedef struct		s_ray
{
	char			name[10];
	t_tuple			start;
	t_tuple			direct;
}					t_ray;

typedef struct		s_shape
{
	int				id_shape;
	float			radius;
	t_tuple			location;
}					t_shape;

typedef struct			s_intersect
{
	float				xs[2];
	t_shape				*shape;
	struct s_intersect	*next;
}						t_intersect;

typedef struct		s_rt
{
	SDL_Event		event;
	SDL_Window		*window;
	SDL_Surface		*surfase_window;

	t_tuple			wind;
	t_tuple			gravity;
}					t_rt;


// удалить
void	print_matrix(t_matrix *a);
void	print_tuples(t_tuple a);
//


int					equal_custom(float a, float b);
int					equal_tuples(t_tuple a, t_tuple b);
int					equal_matrix(t_matrix *a, t_matrix *b);
int					valid_invertion_matrix(t_matrix *a);


unsigned int		rgb_to_ui(int red, int green, int blue);


float				deg_to_rad(float deg);
float				len_vector(t_tuple a);
float				dot_product(t_tuple a, t_tuple b);
float				determinant_matrix(t_matrix *a);
float				determinant_matrix_four(t_matrix *a);
float				determinant_matrix_three(t_matrix *a);
float				determinant_matrix_two(float *a, float *b);
float				minor_matrix_three(t_matrix *a, int del_y, int del_x);
float				cofactor_minor_matrix(t_matrix *a, int del_y, int del_x);
float				discriminant(t_tuple ray_der, t_tuple shape_to_ray);

t_tuple				norm_vector(t_tuple a);
t_tuple				add_tuples(t_tuple a, t_tuple b);
t_tuple				move_tuple(t_tuple src, t_tuple move);
t_tuple				shearing_tuple(t_tuple src, float shear[6]);
t_tuple				rotate_tuple(t_tuple src, t_tuple rot);
t_tuple				scale_tuple(t_tuple src, t_tuple scale);
t_tuple				rvrs_scale_tuple(t_tuple src, t_tuple scale);
t_tuple				rvrs_move_tuple(t_tuple src, t_tuple move);
t_tuple				rvrs_rotate_tuple(t_tuple src, t_tuple rot);
t_tuple				cross_product(t_tuple a, t_tuple b);
t_tuple				subtract_tuples(t_tuple a, t_tuple b);
t_tuple				multiply_tuple_with_scal(t_tuple a, float b);
t_tuple				multiply_matrix_with_tuple(t_matrix *a, t_tuple b);
t_tuple				multiply_identity_matrix_with_tuple(t_tuple b);


t_tuple				new_point(float x, float y, float z);
t_tuple				new_vector(float x, float y, float z);

t_matrix			*new_matrix(int size);
t_matrix			*get_move_matrix(t_tuple a);
t_matrix			*get_scale_matrix(t_tuple a);
t_matrix			*get_shearing_matrix(float shear[6]);
t_matrix			*get_rotate_matrix_around_ox(float angle);
t_matrix			*get_rotate_matrix_around_oy(float angle);
t_matrix			*get_rotate_matrix_around_oz(float angle);
t_matrix			*transposing_matrix(t_matrix *a);
t_matrix			*inverse_matrix(t_matrix *a, t_matrix *dest);
t_matrix			*multiply_identity_matrix(t_matrix *a, t_matrix *dest);
t_matrix			*multiply_matrix(t_matrix *a, t_matrix *b, t_matrix *dest);
t_matrix			*spot_submatrix(t_matrix *a, t_matrix *dest, int del_y, int del_x);


t_tuple				position(t_ray ray, float t);
t_ray				new_ray(t_tuple	start, t_tuple direct);


t_shape				*new_shape();
void				get_new_sphere(t_shape *dest);
int					intersect_sphere(t_shape *sphere, t_ray ray, float	xs[2]);
t_intersect			intersect(t_shape *shape, t_ray ray);


void				dell_matrix(t_matrix *mat);
void				identity_matrix(t_matrix *a);

void				set_pixel_sdl(SDL_Surface *surface, int x, int y, Uint32 pixel);
void				clear_surface(SDL_Surface *surface, int x, int y);
void				identity_matrix(t_matrix *a);

#endif

