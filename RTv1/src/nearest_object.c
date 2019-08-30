/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nearest_object.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtreutel <dtreutel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 20:58:21 by dtreutel          #+#    #+#             */
/*   Updated: 2019/08/30 14:44:00 by udraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void		nearest_object(t_ray *ray, float root, t_obj *obj)
{
	if (root > 1 && root < ray->t)
	{
		ray->t = root;
		ray->clr = obj->clr;
		ray->obj = obj;
	}
}

void		nearest_objects(t_ray *ray, float roots[2], t_obj *obj)
{
	nearest_object(ray, roots[0], obj);
	nearest_object(ray, roots[1], obj);
}
