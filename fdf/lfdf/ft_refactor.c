/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_refactor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtreutel <dtreutel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 18:45:22 by dtreutel          #+#    #+#             */
/*   Updated: 2019/02/10 18:48:06 by dtreutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_hight(t_all_sct *all)
{
	int x;
	int y;

	y = -1;
	while (++y < all->maxy->y)
	{
		x = -1;
		while (++x < all->maxy->x)
		{
			if (all->points[x][y].z)
			{
				if (all->points[x][y].z > 0)
					all->points[x][y].z += 1;
				else
					all->points[x][y].z -= 1;
			}
		}
	}
	mlx_clear_window(all->mlx->mlx_ptr, all->mlx->win_ptr);
	mlx_put_map(all->mlx, all->points, all->maxy);
}

static void	ft_low(t_all_sct *all)
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
			if (all->points[x][y].z)
			{
				if (all->points[x][y].z > 0)
					all->points[x][y].z -= 1;
				else
					all->points[x][y].z += 1;
			}
		}
	}
	mlx_put_map(all->mlx, all->points, all->maxy);
}

void		ft_refactor(t_all_sct *all, int key)
{
	if (key == 116)
		ft_zoom(all);
	if (key == 121)
		ft_unzoom(all);
	if (key == 115)
		ft_hight(all);
	if (key == 119)
		ft_low(all);
}
