/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diffuse_reflection.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtreutel <dtreutel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 15:54:27 by dtreutel          #+#    #+#             */
/*   Updated: 2019/08/31 14:06:03 by udraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

/*float	diffuse_reflection(t_rt *rt, t_ray *ray)
{
	float	i;
	t_obj	*light;
	float	*o;
	float	p[3];
	float	n[3];
	float	l[3];
	float	lenght_n;
	float	lenght_l;
	float	x;


	i = 0.0;
	light = rt->light;
	o = rt->obj->xyz;

	p[0] = o[0] + ray->t * ray->d[0];
	p[1] = o[1] + ray->t * ray->d[1];
	p[2] = o[2] + ray->t * ray->d[2];

	n[0] = p[0] - ray->obj->xyz[0];
	n[1] = p[1] - ray->obj->xyz[1];
	n[2] = p[2] - ray->obj->xyz[2];



	lenght_n = sqrt(pow(n[0], 2) + pow(n[1], 2) + pow(n[2], 2));

	n[0] = n[0] / lenght_n;
	n[1] = n[1] / lenght_n;
	n[2] = n[2] / lenght_n;


	while (light->next)
	{
		if (!light->type)
			i += light->r;
		else
		{
			if (light->type == 1)
			{
				l[0] = light->xyz[0] - p[0];
				l[1] = light->xyz[1] - p[1];
				l[2] = light->xyz[2] - p[2];

			}
			else
			{
				l[0] = light->xyz[0];
				l[1] = light->xyz[1];
				l[2] = light->xyz[2];
			}
			x = n[0] * l[0] + n[1] * l[1] + n[2] * l[2];
			if (x > 0)
			{
				lenght_n = sqrt(pow(n[0], 2) + pow(n[1], 2) + pow(n[2], 2));
				lenght_l = sqrt(pow(l[0], 2) + pow(l[1], 2) + pow(l[2], 2));
				i += light->r * x / (lenght_l * lenght_n);
			}
		}
		light = light->next;
	}
	if (!light->type)
			i += light->r;
		else
		{
			if (light->type == 1)
			{
				l[0] = light->xyz[0] - p[0];
				l[1] = light->xyz[1] - p[1];
				l[2] = light->xyz[2] - p[2];

			}
			else
			{
				l[0] = light->xyz[0];
				l[1] = light->xyz[1];
				l[2] = light->xyz[2];
			}
			x = n[0] * l[0] + n[1] * l[1] + n[2] * l[2];
			if (x > 0)
			{
				lenght_n = sqrt(pow(n[0], 2) + pow(n[1], 2) + pow(n[2], 2));
				lenght_l = sqrt(pow(l[0], 2) + pow(l[1], 2) + pow(l[2], 2));
				i += light->r * x / (lenght_l * lenght_n);
			}
		}
	return (i);
}*/

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
		if (light->type != 0)
		{
			intensive_current_light = light->intensive *
					dot_product(ray->normal, light->vector) /
						(len_vector(ray->normal) * len_vector(light->vector));
			if (intensive_current_light > 0.0)
				intensive_light += intensive_current_light;
		}
		else
			if (light->intensive > 0.0)
				intensive_light += light->intensive;
		curr_light = curr_light->next;
	}
	return (intensive_light);
}
