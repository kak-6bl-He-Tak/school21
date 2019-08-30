/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clr_plane.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtreutel <dtreutel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 20:13:55 by udraugr-          #+#    #+#             */
/*   Updated: 2019/08/30 14:43:00 by udraugr-         ###   ########.fr       */
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
	float		o_c[3];
	t_plane		*plane;

	plane = (t_plane *)current_obj->shape;
	delitel = dot_product(ray->d, plane->plane_normal);
	if (delitel == 0)
		return ;
	subtraction_point((float *)cam->shape, plane->plane_dot, o_c);
	root = -1.0 * dot_product(o_c, plane->plane_normal);
	root /= delitel;
	nearest_object(ray, root, current_obj);
}
