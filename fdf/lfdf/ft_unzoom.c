/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unzoom.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtreutel <dtreutel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 18:18:10 by dtreutel          #+#    #+#             */
/*   Updated: 2019/02/11 11:03:13 by dtreutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_unzoom(t_all_sct *all)
{
	int x;
	int y;

	y = -1;
	mlx_clear_window(all->mlx->mlx_ptr, all->mlx->win_ptr);
	while (++y < all->maxy->y)
	{
		x = -1;
		while (++x < all->maxy->x)
		{
			all->points[x][y].x -= x;
			all->points[x][y].y -= y;
		}
	}
	mlx_put_map(all->mlx, all->points, all->maxy);
}
