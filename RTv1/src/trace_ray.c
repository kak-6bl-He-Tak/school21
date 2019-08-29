/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace_ray.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtreutel <dtreutel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 16:44:33 by dtreutel          #+#    #+#             */
/*   Updated: 2019/08/29 21:19:54 by dtreutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void		object_patrol(t_rt *rt, t_ray *ray)
{
	t_obj	*cam;
	t_obj	*obj;

	cam = rt->obj;
	obj = cam;
	while (obj->next)
	{
		obj = obj->next;
		if (obj->type == SPHERE)
			clr_sphere(cam, obj, ray);
		else if (obj->type == PLANE)
			clr_plane(cam, obj, ray);
		else if (obj->type == CYLINDER)
			clr_cylinder(cam, obj, ray);
		else if (obj->type == CONE)
			clr_cone(cam, obj, ray);

	}
}

int			colr_mod(int clr, float i)
{
	int	rgb[3];

	if (i > 1.0)
		i = 1.0;

	rgb[0] = (clr / 256) / 256 * i;
	rgb[1] = (clr / 256) % 256 * i;
	rgb[2] = clr % 256 * i;
	return (((rgb[0] * 256) + rgb[1]) * 256 + rgb[2]);
}

void		trace_ray(t_rt *rt)
{
	int		x;
	int		y;
	t_ray	ray;
//	float	i;

	y = -1;
	while (++y < H)
	{
		x = -1;
		while (++x < W)
		{
			ray.clr = BG_CLR;
			ray.d[0] = (float)(x - W / 2) * 1 / W;
			ray.d[1] = (float)(H / 2 - y) * 1 / H;
			ray.d[2] = 1;
			ray.t = 2147483647;
			ray.obj = 0;
			object_patrol(rt, &ray);
			if (ray.obj)
			{
				//i = diffuse_reflection(rt, &ray);
				//ray.clr = colr_mod(ray.clr, i);
			}
			rt->img_data[y * W + x] = ray.clr;
		}
	}
	mlx_put_image_to_window(rt->mlx_ptr, rt->win_ptr, rt->img_ptr, 0, 0);
}
