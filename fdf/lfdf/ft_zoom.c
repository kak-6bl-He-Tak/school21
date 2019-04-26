/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zoom.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtreutel <dtreutel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 18:17:11 by dtreutel          #+#    #+#             */
/*   Updated: 2019/02/11 11:02:27 by dtreutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_zoom(t_all_sct *all)
{
	int x;
	int y;

	y = -1;
	while (++y < all->maxy->y)
	{
		x = -1;
		while (++x < all->maxy->x)
		{
			all->points[x][y].x += x;
			all->points[x][y].y += y;
		}
	}
	mlx_clear_window(all->mlx->mlx_ptr, all->mlx->win_ptr);
	mlx_put_map(all->mlx, all->points, all->maxy);
}
