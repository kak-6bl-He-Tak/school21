/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal_intersection_dot.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtreutel <dtreutel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 20:11:45 by dtreutel          #+#    #+#             */
/*   Updated: 2019/08/30 20:20:54 by dtreutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void	normal_plane(t_ray *ray, t_obj *cam)
{
	void *a;
	a = ray;
	a = cam;
}

static void	normal_sphere(t_ray *ray, t_obj *cam)
{
	void *a;
	a = ray;
	a = cam;
}

static void	normal_cylinder(t_ray *ray, t_obj *cam)
{
	void *a;
	a = ray;
	a = cam;
}

static void	normal_cone(t_ray *ray, t_obj *cam)
{
	void *a;
	a = ray;
	a = cam;
}

void	normal_intersection_dot(t_ray *ray, t_obj *cam)
{
	if (ray->obj->type == PLANE)
		normal_plane(ray, cam);
	else if (ray->obj->type == SPHERE)
		normal_sphere(ray, cam);
	else if (ray->obj->type == CYLINDER)
		normal_cylinder(ray, cam);
	else
		normal_cone(ray, cam);
}
