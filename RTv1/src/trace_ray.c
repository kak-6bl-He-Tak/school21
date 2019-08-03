/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace_ray.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtreutel <dtreutel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 16:44:33 by dtreutel          #+#    #+#             */
/*   Updated: 2019/08/03 19:00:14 by dtreutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void	ft_koroche(t_ray *ray, float *t, t_obj *obj)
{
	if (t[0] > 1 && t[0] < ray->t)
	{
		ray->t = t[0];
		ray->clr = obj->clr;
		ray->obj = obj;
	}
	if (t[1] > 1 && t[1] < ray->t)
	{
		ray->t = t[1];
		ray->clr = obj->clr;
		ray->obj = obj;
	}
}

void		clr_sphere(t_obj *cam, t_obj *obj, t_ray *ray)
{
	float oc[3];
	float k[3];
	float dsct;
	float t[2];

	oc[0] = cam->xyz[0] - obj->xyz[0];
	oc[1] = cam->xyz[1] - obj->xyz[1];
	oc[2] = cam->xyz[2] - obj->xyz[2];
	k[0] = ray->d[0] * ray->d[0] + ray->d[1] * ray->d[1] +
		ray->d[2] * ray->d[2];
	k[1] = 2 * (oc[0] * ray->d[0] + oc[1] * ray->d[1] + oc[2] * ray->d[2]);
	k[2] = (oc[0] * oc[0] + oc[1] * oc[1] + oc[2] * oc[2]) - obj->r * obj->r;
	dsct = k[1] * k[1] - 4 * k[0] * k[2];
	if (dsct >= 0)
	{
		t[0] = (-k[1] + sqrt(dsct)) / (2 * k[0]);
		t[1] = (-k[1] - sqrt(dsct)) / (2 * k[0]);
		ft_koroche(ray, t, obj);
	}
}

void		object_patrol(t_rt *rt, t_ray *ray)
{
	t_obj	*cam;
	t_obj	*obj;

	cam = rt->obj;
	obj = cam;
	while (obj->next)
	{
		obj = obj->next;
		if (obj->type == 1)
			clr_sphere(cam, obj, ray);
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
	float	i;

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
				i = diffuse_reflection(rt, &ray);
				ray.clr = colr_mod(ray.clr, i);
			}
			rt->img_data[y * W + x] = ray.clr;
		}
	}
	mlx_put_image_to_window(rt->mlx_ptr, rt->win_ptr, rt->img_ptr, 0, 0);
}
