/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iso_points.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtreutel <dtreutel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 16:05:05 by dtreutel          #+#    #+#             */
/*   Updated: 2019/02/09 16:19:07 by dtreutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	iso_points(t_point **points, t_x_and_y *maxy)
{
	int	x;
	int	y;
	int	savex;
	int	savey;

	x = -1;
	while (++x < maxy->x)
	{
		y = -1;
		while (++y < maxy->y)
		{
			savex = points[x][y].x;
			savey = points[x][y].y;
			points[x][y].x = savex - savey;
			points[x][y].y = (savex + savey) / 2;
		}
	}
}
