/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shapes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtreutel <dtreutel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 16:06:54 by dtreutel          #+#    #+#             */
/*   Updated: 2019/10/27 18:04:53 by dtreutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_shape	*new_shape()
{
	t_shape *new;

	new = ft_memalloc(sizeof(t_shape));
	return(new);
}

void		get_new_sphere(t_shape *sphere)
{
	sphere->id_shape = SPHERE;
	sphere->radius = 1.0;
	sphere->location = new_point(0.0 ,0.0, 0.0);
}



//  	t1 ← (-b - √(discriminant)) / (2 * a)
// ​ 	t2 ← (-b + √(discriminant)) / (2 * a)
// ​
// ​ 	​return​ (t1, t2)
