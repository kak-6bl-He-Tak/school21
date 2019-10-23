/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuples.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtreutel <dtreutel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 19:18:08 by dtreutel          #+#    #+#             */
/*   Updated: 2019/10/23 19:22:00 by dtreutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_tuple		new_point(float x, float y, float z)
{
	t_tuple result;

	result.x = x;
	result.y = y;
	result.z = z;
	result.w = 1.0;
	return (result);
}

t_tuple		new_vector(float x, float y, float z)
{
	t_tuple result;

	result.x = x;
	result.y = y;
	result.z = z;
	result.w = 0.0;
	return (result);

}
