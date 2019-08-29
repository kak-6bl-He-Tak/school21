/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_with_point.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udraugr- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 19:29:41 by udraugr-          #+#    #+#             */
/*   Updated: 2019/08/29 19:36:45 by udraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

float			*multiplication_point(float	first_point, float k)
{
	first_point[0] *= k;
	first_point[1] *= k;
	first_point[2] *= k;
}

float			*addition_point(float first_point[3], float second_point[3],
									float destination[3])
{
	destination[0] = first_point[0] + second_point[0];
	destination[1] = first_point[1] + second_point[1];
	destination[2] = first_point[2] + second_point[2];
}

float			*subtraction_point(float first_point[3], float second_point[3],
									float destination[3])
{
	destination[0] = first_point[0] - second_point[0];
	destination[1] = first_point[1] - second_point[1];
	destination[2] = first_point[2] - second_point[2];
}
