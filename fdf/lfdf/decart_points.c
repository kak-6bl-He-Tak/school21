/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decart_points1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtreutel <dtreutel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 11:55:05 by dtreutel          #+#    #+#             */
/*   Updated: 2019/02/11 11:55:05 by dtreutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	decart_points(t_point **points, t_x_and_y *maxy)
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
			points[x][y].x = (2 * savey + savex) / 2;
			points[x][y].y = (2 * savey - savex) / 2;
		}
	}
}
