/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtreutel <dtreutel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 12:59:53 by dtreutel          #+#    #+#             */
/*   Updated: 2019/10/26 16:22:24 by dtreutel         ###   ########.fr       */
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
//


int					equal_custom(float a, float b);
int					equal_tuples(t_tuple a, t_tuple b);
int					equal_matrix(t_matrix *a, t_matrix *b);
int					valid_invertion_matrix(t_matrix *a);



unsigned int		rgb_to_ui(int red, int green, int blue);


float				len_vector(t_tuple a);
float				dot_product(t_tuple a, t_tuple b);
float				determinant_matrix(t_matrix *a);
float				determinant_matrix_four(t_matrix *a);
float				determinant_matrix_three(t_matrix *a);
float				determinant_matrix_two(float *a, float *b);
float				minor_matrix_three(t_matrix *a, int del_y, int del_x);
float				cofactor_minor_matrix(t_matrix *a, int del_y, int del_x);

t_tuple				norm_vector(t_tuple a);
t_tuple				add_tuples(t_tuple a, t_tuple b);
t_tuple				cross_product(t_tuple a, t_tuple b);
t_tuple				subtract_tuples(t_tuple a, t_tuple b);
t_tuple				multiply_tuple_with_scal(t_tuple a, float b);
t_tuple				multiply_matrix_with_tuple(t_matrix *a, t_tuple b);
t_tuple				multiply_identity_matrix_with_tuple(t_tuple b);

t_tuple				new_point(float x, float y, float z);
t_tuple				new_vector(float x, float y, float z);

t_matrix			*new_matrix(int size);
t_matrix			*transposing_matrix(t_matrix *a);
t_matrix			*inverse_matrix(t_matrix *a, t_matrix *dest);
t_matrix			*multiply_identity_matrix(t_matrix *a, t_matrix *dest);
t_matrix			*multiply_matrix(t_matrix *a, t_matrix *b, t_matrix *dest);
t_matrix			*spot_submatrix(t_matrix *a, t_matrix *dest, int del_y, int del_x);

void				dell_matrix(t_matrix *mat);

void				set_pixel_sdl(SDL_Surface *surface, int x, int y, Uint32 pixel);
void				clear_surface(SDL_Surface *surface, int x, int y);

#endif


// typedef struct			s_obj
// {
// 	char				type;
// 	void				*shape;
// 	int					clr;

// 	struct s_obj		*next;
// }						t_obj;

// typedef struct			s_rt
// {
// 	SDL_Window			*win_ptr;
// 	SDL_Surface			*sur_ptr;
// 	SDL_Event			event;

// 	int					*img_data;
// 	t_obj				*obj;
// 	t_obj				*light;
// 	int					i;
// }						t_rt;

// typedef struct			s_ray
// {
// 	float				d[3];
// 	float				t;
// 	float				p[3];
// 	int					clr;
// 	float				normal[3];
// 	t_obj				*obj;
// 	float				min_t;
// }						t_ray;

// typedef struct			s_pthread_ray
// {
// 	int					y;
// 	t_rt				*rt;
// }						t_pthread_ray;

// int						ft_exit(t_rt *rt);
// int						valid_data(t_rt *rt);
// int						open_file(char *str);
// int						pars_scene(char *str, t_rt *rt);
// int						set_cone(t_obj **obj, char *gnl);
// int						set_plane(t_obj **obj, char *gnl);
// int						set_light(t_obj **obj, char *gnl);
// int						set_sphere(t_obj **obj, char *gnl);
// int						set_cylinder(t_obj **obj, char *gnl);
// int						get_next_line(const int fd, char **line);
// int						check_shadow(t_rt *rt, t_ray *ray, t_light *light);
// int						clr_sphere(t_obj *cam, t_obj *obj, t_ray *ray,
// 															float roots[2]);
// int						clr_cone(t_obj *cam, t_obj *current_obj, t_ray *ray,
// 															float roots[2]);
// int						clr_plane(t_obj *cam, t_obj *current_obj, t_ray *ray,
// 															float roots[2]);
// int						clr_cylinder(t_obj *cam, t_obj *current_obj,
// 												t_ray *ray, float roots[2]);
// int						roots_quadratic_equation(float a, float b, float c,
// 												float roots[2]);

// float					ft_atof(const char *str);
// float					ft_scan_digit(char **str);
// float					len_vector(float vector[3]);
// float					diffuse_reflection(t_rt *rt, t_ray *ray);
// float					dot_product(float first_point[3],
// 									float second_point[3]);

// t_obj					*new_obj(t_obj **obj);

// void					trace_ray(t_rt *rt);
// void					hooks(int key, t_rt *rt);
// void					dell_all_obj(t_obj **obj);
// void					normal_intersection_dot(t_ray *ray, t_obj *cam);
// void					nearest_object(t_ray *ray, float root,
// 												t_obj *obj, t_obj *cam);
// void					nearest_objects(t_ray *ray, float roots[2],
// 												t_obj *obj, t_obj *cam);
// void					multiplication_point(float first_point[3], float k,
// 											float destination[3]);
// void					addition_point(float first_point[3],
// 									float second_point[3],
// 									float destination[3]);
// void					subtraction_point(float first_point[3],
// 										float second_point[3],
// 										float destination[3]);
// void					rotation_on_z(float vector[3], float angle,
// 										float destination[3]);
// void					rotation_on_x(float vector[3], float angle,
// 										float destination[3]);
// void					rotation_on_y(float vector[3], float angle,
// 										float destination[3]);
