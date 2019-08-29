/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clr_cylinder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udraugr- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 14:14:46 by udraugr-          #+#    #+#             */
/*   Updated: 2019/08/29 18:13:10 by udraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
 
/*
 * Solution of пересечения прямой and cylinder
 * сводится к solution of quadratic equation
 * with коэффицантами
 * a = < D ; D > - < D ; V > * < D ; V >
 * b = 2 * ( < D ; O - C > - < V ; O - C > * < D ; V > )
 * c = < O - C ; O - C > - < O - C ; V > * < O - C ; V > - R * R
 * where :
 * D - vectot of view
 * V - vector of cylinder's axis (len(V) == 1)
 * O - point of view
 * R - radius of cylinder
 * C - point on axis of cylinder
*/

void				clr_cylinder(t_obj *cam, t_obj *plane, t_ray *ray)
{

}
