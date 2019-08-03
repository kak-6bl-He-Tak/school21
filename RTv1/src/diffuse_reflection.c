/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diffuse_reflection.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtreutel <dtreutel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 15:54:27 by dtreutel          #+#    #+#             */
/*   Updated: 2019/08/03 17:27:00 by dtreutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

float	diffuse_reflection(t_rt *rt, t_ray *ray)
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
}
