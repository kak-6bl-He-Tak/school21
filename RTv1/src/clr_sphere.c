/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clr_sphere.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtreutel <dtreutel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 20:03:21 by udraugr-          #+#    #+#             */
/*   Updated: 2019/08/30 14:43:41 by udraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

/*
** Solution the intersection of the  line and the sphere
** reduces to solution the quadratic equation
** with coefficient
** a = < D ; D >
** b = 2 * < O - C ; D > 
** c = < O - C ; O - C > - r * r
** where:
** C - sphere's centre
** r - sphere's radius
** O - view point
** D - vector of view
*/

void		clr_sphere(t_obj *cam, t_obj *obj, t_ray *ray)
{
	float		o_c[3];
	float		coefficient_quadratic_equation[3];
	float		roots[2];
	t_sphere	*sphere;

	sphere = (t_sphere *)obj->shape;
	subtraction_point((float *)cam->shape, sphere->sphere_center, o_c);
	coefficient_quadratic_equation[0] = dot_product(ray->d, ray->d);
	coefficient_quadratic_equation[1] = 2 * dot_product(o_c, ray->d);
	coefficient_quadratic_equation[2] = dot_product(o_c, o_c) -
		sphere->sphere_radius * sphere->sphere_radius;
	if (roots_quadratic_equation(coefficient_quadratic_equation[0],
								coefficient_quadratic_equation[1],
								coefficient_quadratic_equation[2],
								roots) == FAIL)
		return ;
	nearest_objects(ray, roots, obj);
}
