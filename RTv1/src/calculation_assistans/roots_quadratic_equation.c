/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   roots_quadratic_equation.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udraugr- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 19:30:33 by udraugr-          #+#    #+#             */
/*   Updated: 2019/08/27 19:49:31 by udraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int					roots_quadratic_equation(float a, float b, float c,
												float roots[2])
{
	float			discriminant;
	float			ans_first;
	float			ans_second;

	discriminant = b * b - 4.0 * a * c;
	if (discriminant < 0.0 || a == 0.0)
		return (FAIL);
	ans_first = (-b - sqrt(discriminant)) / 2.0 * a;
	ans_first = (-b + sqrt(discriminant)) / 2.0 * a;
	roots[0] = ans_first;
	roots[1] = ans_second;
	return (SUCCESS);
}
