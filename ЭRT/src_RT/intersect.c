/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtreutel <dtreutel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 18:03:59 by dtreutel          #+#    #+#             */
/*   Updated: 2019/10/27 18:28:20 by dtreutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_intersect	*new_intersect()
{
	t_intersect	*new;

	new = ft_memalloc(sizeof(t_intersect));
	return(new);
}

void	add_intersect(t_intersect *i, t_intersect **list)
{
	t_intersect	*save;

	if (*list == 0)
		*list = new;
	else
	{
		save = *list;
		while(save->next != 0 && save->xs[0] > )
	}
}



int		intersect_sphere(t_shape *sphere, t_ray ray, float	xs[2])
{
	float	disc;
	t_tuple	sphere_to_ray;
	float	a;
	float	b;

	sphere_to_ray = subtract_tuples(ray.start, sphere->location);
	disc = discriminant(ray.direct, sphere_to_ray);
	if (equal_custom(disc, 0.0))
		return(FAIL);
	a = dot_product(ray.direct, ray.direct);
	b = 2.0 * dot_product(ray.direct, sphere_to_ray);

	xs[0] = (-1.0 * b - sqrt(disc)) / (2 * a);
	xs[1] = (-1.0 * b + sqrt(disc)) / (2 * a);
	return(SUCCESS);
}


t_intersect	intersect(t_shape *shape, t_ray ray)
{
	t_intersect	i;

	i.shape = 0;
	ft_bzero((void *)i.xs, sizeof(float) * 2);
	if (shape->id_shape == SPHERE)
	{
		if (intersect_sphere(shape, ray, i.xs) == SUCCESS)
			i.shape = shape;
	}
	return (i);
}

