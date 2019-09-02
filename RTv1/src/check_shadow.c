/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_shadow.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtreutel <dtreutel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 19:10:54 by udraugr-          #+#    #+#             */
/*   Updated: 2019/09/02 20:57:55 by dtreutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int				check_shadow(t_rt *rt, t_ray *ray, t_light *light)
{
	t_obj		camera;
	t_ray		ray_p_light;
	t_obj		*tmp;
	float		t;

	tmp = rt->obj;
	ft_bzero((void *)&camera, sizeof(t_obj));
	ft_bzero((void *)&ray_p_light, sizeof(t_ray));
	camera.shape = (void *)ray->p;
	camera.type = ray->obj->type;
	if (light->type == 1)
	{
		subtraction_point(light->center, ray->p, ray_p_light.d);
		ray_p_light.t = len_vector(ray_p_light.d);
		multiplication_point(ray_p_light.d, 1 / ray_p_light.t, ray_p_light.d);
	}
	else
	{
		multiplication_point(light->vector, -1, ray->p);
		ray_p_light.t = 2147483647.0;
	}
	t = ray_p_light.t;
	while (tmp->next)
	{
		tmp = tmp->next;
		if (tmp->type == SPHERE)
			clr_sphere(&camera, tmp, &ray_p_light);
		else if (tmp->type == PLANE)
			clr_plane(&camera, tmp, &ray_p_light);
		else if (tmp->type == CYLINDER)
			clr_cylinder(&camera, tmp, &ray_p_light);
		else if (tmp->type == CONE)
			clr_cone(&camera, tmp, &ray_p_light);
	}
	if (ray_p_light.t < t)
		return (FAIL);
	return (SUCCESS);
}
