/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clr_plane.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtreutel <dtreutel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 20:13:55 by udraugr-          #+#    #+#             */
/*   Updated: 2019/08/29 19:39:39 by dtreutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

/*
** t = (-1 * < O - C ; V >) / < D ; V >
** where:
** C - dot on plane
** V - normal of plane
** O - point of view
** D - vector of view
**
** if (< D ; V > == 0)
**		roots not exist (plane parallel of vector of view)
*/

void			clr_plane(t_obj *cam, t_obj *current_obj, t_ray *ray)
{
	float		root;
	float		delitel;
	float		tmp[3];
	t_plane		*plane;
	float		*cam_xyz;

	cam_xyz = (float *)cam->shape;
	plane = (t_plane *)current_obj->shape;
	delitel = dot_product(ray->d, plane->plane_normal);
	if (delitel == 0)
		return ;
	tmp[0] = cam_xyz[0] - plane->plane_dot[0];
	tmp[1] = cam_xyz[1] - plane->plane_dot[1];
	tmp[2] = cam_xyz[2] - plane->plane_dot[2];
	root = -1.0 * dot_product(tmp, plane->plane_normal);
	root /= delitel;
	if (root > 1.0 && root < ray->t)
	{
		ray->t = root;
		ray->clr = current_obj->clr;
		ray->obj = current_obj;
	}
}
