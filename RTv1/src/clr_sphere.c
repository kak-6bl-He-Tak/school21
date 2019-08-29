/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clr_sphere.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtreutel <dtreutel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 20:03:21 by udraugr-          #+#    #+#             */
/*   Updated: 2019/08/29 21:00:16 by dtreutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"



void		clr_sphere(t_obj *cam, t_obj *obj, t_ray *ray)
{
	float		oc[3];
	float		k[3];
	float		roots[2];
	float		*cam_xyz;
	t_sphere	*sphere;

	sphere = (t_sphere *)obj->shape;
	cam_xyz = (float *)cam->shape;
	roots[0] = 0.0;
	roots[1] = 0.0;
	oc[0] = cam_xyz[0] - sphere->sphere_center[0];
	oc[1] = cam_xyz[1] - sphere->sphere_center[1];
	oc[2] = cam_xyz[2] - sphere->sphere_center[2];
	k[0] = ray->d[0] * ray->d[0] + ray->d[1] * ray->d[1] +
		ray->d[2] * ray->d[2];
	k[1] = 2 * (oc[0] * ray->d[0] + oc[1] * ray->d[1] + oc[2] * ray->d[2]);
	k[2] = (oc[0] * oc[0] + oc[1] * oc[1] + oc[2] * oc[2]) -
		sphere->sphere_radius * sphere->sphere_radius;
	if (roots_quadratic_equation(k[0], k[1], k[2], roots) == FAIL)
		return ;
	nearest_object(ray, roots, obj);
}
