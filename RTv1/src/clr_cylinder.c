/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clr_cylinder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtreutel <dtreutel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 14:14:46 by udraugr-          #+#    #+#             */
/*   Updated: 2019/08/30 14:43:16 by udraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

/*
** Solution of пересечения прямой and cylinder
** сводится к solution of quadratic equation
** with коэффицантами
** a = < D ; D > - < D ; V > * < D ; V >
** b = 2 * ( < D ; O - C > - < V ; O - C > * < D ; V > )
** c = < O - C ; O - C > - < O - C ; V > * < O - C ; V > - R * R
** where :
** D - vector of view
** V - vector of cylinder's axis (len(V) == 1)
** O - point of view
** R - radius of cylinder
** C - point on axis of cylinder
*/

void				clr_cylinder(t_obj *cam, t_obj *current_obj, t_ray *ray)
{
	t_cylinder		*cylinder;
	float			coefficient_quadratic_equation[3];
	float			roots[2];
	float			o_c[3];
	float			tmp;

	cylinder = current_obj->shape;
	subtraction_point((float *)cam->shape, cylinder->cylinder_start, o_c);
	tmp = dot_product(ray->d, cylinder->cylinder_axis);
	coefficient_quadratic_equation[0] = dot_product(ray->d, ray->d) - tmp * tmp;
	tmp = dot_product(o_c, cylinder->cylinder_axis) *
						dot_product(ray->d, cylinder->cylinder_axis);
	coefficient_quadratic_equation[1] = 2 * (dot_product(ray->d, o_c) - tmp);
	tmp = dot_product(o_c, cylinder->cylinder_axis);
	coefficient_quadratic_equation[2] =
		dot_product(o_c, o_c) -
			(tmp * tmp + cylinder->cylinder_radius * cylinder->cylinder_radius);
	if (roots_quadratic_equation(coefficient_quadratic_equation[0],
								coefficient_quadratic_equation[1],
								coefficient_quadratic_equation[2],
								roots) == FAIL)
		return ;
	nearest_objects(ray, roots, current_obj);
}
