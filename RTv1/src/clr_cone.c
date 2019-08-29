/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clr_cone.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udraugr- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 20:52:10 by udraugr-          #+#    #+#             */
/*   Updated: 2019/08/29 21:05:05 by udraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

	cone - current_obj->shape;
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
	ft_koroche(ray, roots, current_obj);
}
}
