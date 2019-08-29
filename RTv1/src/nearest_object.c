/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nearest_object.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtreutel <dtreutel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 20:58:21 by dtreutel          #+#    #+#             */
/*   Updated: 2019/08/29 20:59:30 by dtreutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void		nearest_object(t_ray *ray, float roots[2], t_obj *obj)
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
