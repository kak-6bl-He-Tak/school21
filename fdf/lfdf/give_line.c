/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   give_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtreutel <dtreutel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/03 13:30:03 by dtreutel          #+#    #+#             */
/*   Updated: 2019/02/03 15:59:02 by dtreutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	give_line(t_line *line, t_point point0, t_point point1)
{
	line->x0 = X0 + point0.x;
	line->y0 = Y0 + point0.y - (point0.z * 10);
	line->x1 = X0 + point1.x;
	line->y1 = Y0 + point1.y - (point1.z * 10);
	line->clr0 = point0.clr;
	line->clr1 = point1.clr;
}
