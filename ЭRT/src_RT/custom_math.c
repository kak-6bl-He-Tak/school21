/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   custom_math.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtreutel <dtreutel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 19:24:53 by dtreutel          #+#    #+#             */
/*   Updated: 2019/10/23 22:22:16 by dtreutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int		equal_custom(float a, float b)
{
	float	c;

	c = a - b;
	if (c < 0)
		c *= -1.0;
	if (c < EPSILON)
		return (1);
	else
		return (0);
}

int		equal_tuples(t_tuple a, t_tuple b)
{
	if (!equal_custom(a.x, b.x))
		return(0);
	if (!equal_custom(a.y, b.y))
		return(0);
	if (!equal_custom(a.z, b.z))
		return(0);
	if (!equal_custom(a.w, b.w))
		return(0);
	return (1);
}

t_tuple	add_tuples(t_tuple a, t_tuple b)
{
	t_tuple result;

	result.x = a.x + b.x;
	result.y = a.y + b.y;
	result.z = a.z + b.z;
	result.w = a.w + b.w;
	return (result);
}

t_tuple	subtract_tuples(t_tuple a, t_tuple b)
{
	t_tuple result;

	result.x = a.x - b.x;
	result.y = a.y - b.y;
	result.z = a.z - b.z;
	result.w = a.w - b.w;
	return (result);
}

t_tuple	multiply_tuple_with_scal(t_tuple a, float b)
{
	a.x *= b;
	a.y *= b;
	a.z *= b;
	return(a);
}

float	len_vector(t_tuple a)
{
	return (sqrt(a.x * a.x + a.y * a.y + a.z * a.z + a.w * a.w));
}

t_tuple	norm_vector(t_tuple a)
{
	float len;

	len = len_vector(a);
	a.x /= len;
	a.y /= len;
	a.z /= len;
	return(a);
}

float	dot_product(t_tuple a, t_tuple b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w);
}

t_tuple	cross_product(t_tuple a, t_tuple b)
{
	t_tuple res;

	res.x = a.y * b.z - a.z * b.y;
	res.y = a.z * b.x - a.x * b.z;
	res.z = a.x * b.y - a.y * b.x;
	res.w = 0.0;
	return (res);
}

t_color	add_colors(t_color a, t_color b)
{
	a.r += b.r;
	a.g += b.g;
	a.b += b.b;
	return(a);
}

t_color	subtract_colors(t_color a, t_color b)
{
	a.r -= b.r;
	a.g -= b.g;
	a.b -= b.b;
	return(a);
}

t_color	multiply_colors(t_color a, t_color b)
{
	a.r *= b.r;
	a.g *= b.g;
	a.b *= b.b;
	return(a);
}

t_color	multiply_color_with_scal(t_color a, float b)
{
	a.r *= b;
	a.g *= b;
	a.b *= b;
	return(a);
}

unsigned int	rgb_to_ui(int red, int green, int blue)
{
	if (red < 256 && green < 256 && blue < 256)
		return ((red & 0xff) << 16) + ((green & 0xff) << 8) + (blue & 0xff);
	return (0);
}
