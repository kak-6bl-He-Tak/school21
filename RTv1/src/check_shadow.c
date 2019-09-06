/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_shadow.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtreutel <dtreutel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 19:10:54 by udraugr-          #+#    #+#             */
/*   Updated: 2019/09/06 16:54:08 by udraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void		fill_new_cam_and_new_ray(t_obj *camera, t_ray *ray_p_light,
									t_ray *ray, t_light *light)
{
	camera->shape = (void *)ray->p;
	camera->type = ray->obj->type;//!CAMERA;
	if (light->type == 1)
	{
		//subtraction_point(ray->p, light->center, ray_p_light->d);
		subtraction_point(light->center, ray->p, ray_p_light->d);
		ray_p_light->t = len_vector(ray_p_light->d);
		multiplication_point(ray_p_light->d, 1.0 / ray_p_light->t, ray_p_light->d);
	}
	else if (light->type == 2)
	{
		multiplication_point(light->vector, -1.0, ray_p_light->d);
		multiplication_point(ray_p_light->d, 1.0 / len_vector(ray_p_light->d), ray_p_light->d);
		ray_p_light->t = 0.0;//2147483647.0;
	}
}

int				check_shadow(t_rt *rt, t_ray *ray, t_light *light)
{
	t_obj		camera;
	t_ray		ray_p_light;
	t_obj		*current_obj;
	float		t;
	float		result;
	float		roots[2];

	current_obj = rt->obj;
	ft_bzero((void *)&camera, sizeof(t_obj));
	ft_bzero((void *)&ray_p_light, sizeof(t_ray));
	fill_new_cam_and_new_ray(&camera, &ray_p_light, ray, light);
	t = ray_p_light.t;
	while (current_obj->next)
	{
		current_obj = current_obj->next;
		if (current_obj != ray->obj)
		{
			if (current_obj->type == SPHERE)
				result = clr_sphere(&camera, current_obj, &ray_p_light, roots);
			else if (current_obj->type == PLANE)
				result = clr_plane(&camera, current_obj, &ray_p_light, roots);
			else if (current_obj->type == CYLINDER)
				result = clr_cylinder(&camera, current_obj, &ray_p_light, roots);
			else if (current_obj->type == CONE)
				result = clr_cone(&camera, current_obj, &ray_p_light, roots);
			if (result == SUCCESS)
			{
				if (roots[0] > 0.00001 &&
						((light->type == 1 && roots[0] < ray_p_light.t) ||
						 (light->type == 2)))
					return (FAIL);
				if (roots[1] > 0.00001 &&
						((light->type == 1 && roots[1] < ray_p_light.t) ||
						 (light->type == 2)))
					return (FAIL);
			}
		}
	}
	return (SUCCESS);
}
