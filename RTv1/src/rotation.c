/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udraugr- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 11:19:51 by udraugr-          #+#    #+#             */
/*   Updated: 2019/09/09 12:10:21 by udraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void			rotation_on_z(float vector[3], float angle,
										float destination[3])
{
	int			x;
	int			y;
	int			z;

	x = 0;
	y = 1;
	z = 2;
	destination[x] = cos(angle) * vector[x] - sin(angle) * vector[y];
	destination[y] = sin(angle) * vector[x] + cos(angle) * vector[y];
	destination[z] = vector[z];
}

void			rotation_on_x(float vector[3], float angle,
										float destination[3])
{
	int			x;
	int			y;
	int			z;

	x = 0;
	y = 1;
	z = 2;
	destination[x] = vector[x];
	destination[y] = cos(angle) * vector[y] - sin(angle) * vector[z];
	destination[z] = sin(angle) * vector[y] + cos(angle) * vector[z];
}

void			rotation_on_y(float vector[3], float angle,
										float destination[3])
{
	int			x;
	int			y;
	int			z;

	x = 0;
	y = 1;
	z = 2;
	destination[x] = cos(angle) * vector[x] + sin(angle) * vector[z];
	destination[y] = vector[y];
	destination[z] = -sin(angle) * vector[x] + cos(angle) * vector[z];
}
