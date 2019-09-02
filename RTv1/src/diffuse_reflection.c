/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diffuse_reflection.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtreutel <dtreutel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 15:54:27 by dtreutel          #+#    #+#             */
/*   Updated: 2019/09/02 19:39:48 by udraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

float			diffuse_reflection(t_rt *rt, t_ray *ray)
{
	float		intensive_light;
	float		intensive_current_light;
	t_light		*light;
	t_obj		*curr_light;

	intensive_light = 0.0;
	curr_light = rt->light;
	while (curr_light)
	{
		light = curr_light->shape;
		if (light->type == 0 && light->intensive > 0.0)
			intensive_light += light->intensive;
		else if (light->type != 0 && check_shadow(rt, ray, light) == SUCCESS)
		{
			if (light->type == 1)
			{
				subtraction_point(light->center, ray->p, light->vector);
				multiplication_point(light->vector,
					1.0 / len_vector(light->vector), light->vector);
			}
			intensive_current_light = light->intensive *
					dot_product(ray->normal, light->vector) /
						(len_vector(ray->normal) * len_vector(light->vector));
			if (dot_product(ray->normal, light->vector) > 0.0)
				intensive_light += intensive_current_light;
			//блики
	
			float l[3];
			float r[3];
			float d_minus[3];
			float r_dot_v;

			subtraction_point(light->center, ray->p, l);
			multiplication_point(ray->d, -1.0, d_minus);
			multiplication_point(ray->normal,
								2 * dot_product(ray->normal, l), r);
			subtraction_point(r, l, r);
			if ((r_dot_v = dot_product(d_minus, r)) > 0.0)
				intensive_light += light->intensive *
					pow((r_dot_v / (len_vector(r) * len_vector(ray->d))), 50);

			//конец бликов
		}
		curr_light = curr_light->next;
	}
	return (intensive_light);
}
