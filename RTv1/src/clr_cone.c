/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clr_cone.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtreutel <dtreutel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 20:52:10 by udraugr-          #+#    #+#             */
/*   Updated: 2019/08/29 21:18:22 by dtreutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
/*
**
*/

void				clr_cone(t_obj *cam, t_obj *current_obj, t_ray *ray)
{
	t_cone			*cone;
	float			coefficient_quadratic_equation[3];
	float			roots[2];
	float			o_c[3];
	float			tmp;

	cone = current_obj->shape;
	subtraction_point((float *)cam->shape, cone->cone_vertex, o_c);

	tmp = dot_product(ray->d, cone->cone_axis);
	coefficient_quadratic_equation[0] = dot_product(ray->d, ray->d) -
					(tmp * tmp) * (cone->cone_angle * cone->cone_angle + 1);

	tmp = dot_product(o_c, cone->cone_axis) *
						dot_product(ray->d, cone->cone_axis);
	coefficient_quadratic_equation[1] = 2 * (dot_product(ray->d, o_c) -
							tmp * (cone->cone_angle * cone->cone_angle + 1));

	tmp = dot_product(o_c, cone->cone_axis);
	coefficient_quadratic_equation[2] =
		dot_product(o_c, o_c) -
			((tmp * tmp) * (cone->cone_angle * cone->cone_angle + 1));
	if (roots_quadratic_equation(coefficient_quadratic_equation[0],
								coefficient_quadratic_equation[1],
								coefficient_quadratic_equation[2],
								roots) == FAIL)
		return ;
	nearest_object(ray, roots, current_obj);
}
