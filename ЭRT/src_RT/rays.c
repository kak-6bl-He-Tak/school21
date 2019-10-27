/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtreutel <dtreutel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 15:44:10 by dtreutel          #+#    #+#             */
/*   Updated: 2019/10/27 15:55:13 by dtreutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_ray	new_ray(t_tuple	start, t_tuple direct)
{
	t_ray	res;

	res.start = start;
	res.direct = norm_vector(direct);
	return(res);
}

t_tuple	position(t_ray ray, float t)
{
	t_tuple	res;

	res = new_point(0, 0, 0);
	res = multiply_tuple_with_scal(ray.direct, t);
	res = add_tuples(ray.start, res);
	return(res);
}
