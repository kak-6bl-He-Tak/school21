/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clr_plane.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udraugr- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 20:13:55 by udraugr-          #+#    #+#             */
/*   Updated: 2019/08/29 14:14:13 by udraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

/*
 * t = (-1 * < O - C ; V >) / < D ; V >
 * where:
 * C - dot on plane
 * V - normal of plane
 * O - point of view
 * D - vector of view
 *
 * if (< D ; V > == 0)
 *		roots not exist (plane parallel of vector of view)
*/

float			clr_plane(t_obj *cam, t_obj *plane, t_ray *ray)
{
	float		root;
	float		delitel;
	float		tmp[3];

	delitel = dot_product(ray->d, plane->normal);
	if (delitel == 0)
		return ;
	tmp[0] = cam->xyz[0] - plane->plane_dot[0];
	tmp[1] = cam->xyz[1] - plane->plane_dot[1];
	tmp[2] = cam->xyz[2] - plane->plane_dot[2];
	root = -1.0 *  dot_product(tmp, plane->normal);
	root /= delitel;
	if (root > 1.0 && root < ray->t)
	{
		ray->t = root;
		ray->clr = plane->clr;
		ray->obj = plane;
	}
}
