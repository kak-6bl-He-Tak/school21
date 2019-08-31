/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal_intersection_dot.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtreutel <dtreutel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 20:11:45 by dtreutel          #+#    #+#             */
/*   Updated: 2019/08/31 13:46:05 by dtreutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

/*
**- N = (< D ; V > ) < 0 ? -V : V - нормаль - вектор перпендикулярныйповерхности
**- поверхности на котоорую попал луч от точки зрения
**- (< D ; V >) - скалярное произведение луча падающего на плоскость D (ray->d)
**- и нормали плоскости заданной в сцене V (plane->normal)
**- Если скалярное произведение меньше нуля, то заданная в сцене нормаль
**- направлена от зрителя и ее нужно развернуть (умножить на -1.0)
*/

static void	normal_plane(t_ray *ray)
{
	float	dot_prod;
	t_plane	*plane;

	plane = ray->obj->shape;
	dot_prod = dot_product(ray->d, plane->normal);
	if (dot_prod < 0.0)
		multiplication_point(plane->normal, -1.0, ray->normal);
	else
		multiplication_point(plane->normal, 1.0, ray->normal);
}

/*
**- N = norm(P - C) : нормаль - вектор перпендикулярный поверхности на котоорую
**- попал луч от точки зрения (Для дяди Серёжи N = (P - C)/ len_vector(C_P))
**- P (p[3]) - точкa пересечения луча с поверхностью сферы
**- С (center_sphere) - координаты центра сферы
**- P = O + D * t : параметрическое уравнение прямой, где Р точка на прямой,
**- 	О(cam->shape) - коордиаты точки зрения
**		D(ray->d) - вектор взгляда
**- 	t(ray->t) - переменная
*/

static void	normal_sphere(t_ray *ray, t_obj *cam)
{
	float		p[3];
	float		*center_sphere;
	t_sphere	*sphere;
	float		d_t[3];
	float		c_p[3];

	sphere = (t_sphere *)ray->obj->shape;
	center_sphere = sphere->center;
	multiplication_point(ray->d, ray->t, d_t);
	addition_point((float *)cam->shape, d_t, p);
	subtraction_point(p, sphere->center, c_p);
	multiplication_point(c_p, 1.0 / len_vector(c_p), ray->normal);
}

static void	normal_cylinder(t_ray *ray, t_obj *cam)
{
	float		*p[3];
	float		*d_t[3];
	float		*c_p[3];
	t_cylinder	*cylinder;
	float		m;

	cylinder = ray->obj->shape;
	multiplication_point(ray->d, ray->t, d_t);
	addition_point((float *)cam->shape, d_t, p);
	subtraction_point(p, cylinder->start, c_p);
	m = sqrt(pow(len_vector(c_p), 2) - pow(cylinder->radius, 2));
	multiplication_point(cylinder->axis, -m, ray->normal);
	subtraction_point(ray->normal, cylinder->start, ray->normal);
	addition_point(p, ray->normal, ray->normal);
}

static void	normal_cone(t_ray *ray, t_obj *cam)
{
	void *a;
	a = ray;
	a = cam;
}

void	normal_intersection_dot(t_ray *ray, t_obj *cam)
{
	if (ray->obj->type == PLANE)
		normal_plane(ray);
	else if (ray->obj->type == SPHERE)
		normal_sphere(ray, cam);
	else if (ray->obj->type == CYLINDER)
		normal_cylinder(ray, cam);
	else
		normal_cone(ray, cam);
}
