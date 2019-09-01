/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtreutel <dtreutel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 10:06:18 by dtreutel          #+#    #+#             */
/*   Updated: 2019/08/31 17:02:37 by dtreutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H

# include "libft.h"
# include "mlx.h"

# include "shapes.h"

# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <math.h>

# define W 1300
# define H 1300
# define BUFF_SIZE 111
# define BG_CLR 0

# define SUCCESS 0
# define FAIL 1

typedef struct			s_obj
{
	char				type;
	void				*shape;
	float				xyz[3];
	float				r;
	int					clr;

	struct s_obj		*next;
}						t_obj;

typedef struct			s_rt
{
	void				*mlx_ptr;
	void				*win_ptr;
	void				*img_ptr;
	int					*img_data;
	t_obj				*obj;
	t_obj				*light;
	int					i;
}						t_rt;

typedef struct			s_ray
{
	float				d[3];
	float				t;
	float				p[3];
	int					clr;
	float				normal[3];
	t_obj				*obj;
}						t_ray;

int						ft_exit(t_rt *rt);
int						pars_scene(char *str, t_rt *rt);
int						get_next_line(const int fd, char **line);

float					ft_atof(const char *str);
float					ft_scan_digit(char **str);
float					diffuse_reflection(t_rt *rt, t_ray *ray);

t_obj					*new_obj(t_obj **obj);

void					trace_ray(t_rt *rt);
void					dell_all_obj(t_obj **obj);
void					print_all(t_obj *obj, t_obj *light);

void					clr_sphere(t_obj *cam, t_obj *obj, t_ray *ray);
void					clr_cone(t_obj *cam, t_obj *current_obj, t_ray *ray);
void					clr_plane(t_obj *cam, t_obj *current_obj, t_ray *ray);
void					clr_cylinder(t_obj *cam, t_obj *current_obj,
																t_ray *ray);

void					normal_intersection_dot(t_ray *ray, t_obj *cam);
void					nearest_object(t_ray *ray, float root, t_obj *obj, t_obj *cam);
void					nearest_objects(t_ray *ray, float roots[2], t_obj *obj, t_obj *cam);

int						roots_quadratic_equation(float a, float b, float c,
												float roots[2]);
float					len_vector(float vector[3]);
float					dot_product(float first_point[3],
									float second_point[3]);
void					multiplication_point(float first_point[3], float k,
											float destination[3]);
void					addition_point(float first_point[3],
									float second_point[3],
									float destination[3]);
void					subtraction_point(float first_point[3],
										float second_point[3],
										float destination[3]);

#endif
