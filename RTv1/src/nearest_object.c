/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nearest_object.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtreutel <dtreutel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 20:58:21 by dtreutel          #+#    #+#             */
/*   Updated: 2019/09/01 10:25:48 by udraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void		nearest_object(t_ray *ray, float root, t_obj *obj, t_obj *cam)
{
	if (root > 1 && root < ray->t)
	{
		ray->t = root;
		ray->clr = obj->clr;
		ray->obj = obj;
		multiplication_point(ray->d, ray->t, ray->p);
		addition_point((float *)cam->shape, ray->p, ray->p);
		normal_intersection_dot(ray, cam);
	}
}

void		nearest_objects(t_ray *ray, float roots[2], t_obj *obj, t_obj *cam)
{
	nearest_object(ray, roots[0], obj, cam);
	nearest_object(ray, roots[1], obj, cam);
}
