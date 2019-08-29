/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clr_sphere.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udraugr- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 20:03:21 by udraugr-          #+#    #+#             */
/*   Updated: 2019/08/29 13:34:06 by udraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void		ft_koroche(t_ray *ray, float roots[2], t_obj *obj)
{
	if (roots[0] > 1 && roots[0] < ray->t)
	{
		ray->t = roots[0];
		ray->clr = obj->clr;
		ray->obj = obj;
	}
	if (roots[1] > 1 && roots[1] < ray->t)
	{
		ray->t = roots[1];
		ray->clr = obj->clr;
		ray->obj = obj;
	}
}

void		clr_sphere(t_obj *cam, t_obj *obj, t_ray *ray)
{
	float	oc[3];
	float	k[3];
	float	roots[2];

	roots[0] = 0.0;
	roots[1] = 0.0;
	oc[0] = cam->xyz[0] - obj->xyz[0];
	oc[1] = cam->xyz[1] - obj->xyz[1];
	oc[2] = cam->xyz[2] - obj->xyz[2];
	k[0] = ray->d[0] * ray->d[0] + ray->d[1] * ray->d[1] +
		ray->d[2] * ray->d[2];
	k[1] = 2 * (oc[0] * ray->d[0] + oc[1] * ray->d[1] + oc[2] * ray->d[2]);
	k[2] = (oc[0] * oc[0] + oc[1] * oc[1] + oc[2] * oc[2]) - obj->r * obj->r;
	if (roots_quadratic_equation(k[0], k[1], k[2], roots) == FAIL)
		return ;
	ft_koroche(ray, roots, obj);
}
