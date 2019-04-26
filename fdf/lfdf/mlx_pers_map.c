/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_pers_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtreutel <dtreutel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 13:30:02 by dtreutel          #+#    #+#             */
/*   Updated: 2019/02/11 11:44:16 by dtreutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	koroche(t_all_sct *all, int x, int j)
{
	int c;

	if (x < all->maxy->x / 2)
		c = j * (x - all->maxy->x / 2);
	else if (x > all->maxy->x / 2)
		c = j * (x - all->maxy->x / 2);
	else
		c = 0;
	return (c);
}

void		mlx_pers_map(t_all_sct *all)
{
	int x;
	int y;
	int i;
	int	j;
	int c;

	i = 1;
	decart_points(all->points, all->maxy);
	while (++y < all->maxy->y)
	{
		j = CSTEP * i++;
		x = -1;
		while (++x < all->maxy->x)
		{
			all->points[x][y].x += koroche(all, x, j);
			if (all->points[x][y].z != 0)
			{
				if (all->points[x][y].z < 0)
					all->points[x][y].z -= j;
				else
					all->points[x][y].z += j;
			}
		}
	}
}
