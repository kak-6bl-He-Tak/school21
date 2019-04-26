/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moove.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtreutel <dtreutel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 18:39:53 by dtreutel          #+#    #+#             */
/*   Updated: 2019/02/11 11:45:45 by dtreutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_right(t_all_sct *all)
{
	int x;
	int y;

	y = -1;
	mlx_clear_window(all->mlx->mlx_ptr, all->mlx->win_ptr);
	while (++y < all->maxy->y)
	{
		x = -1;
		while (++x < all->maxy->x)
			all->points[x][y].x += 5;
	}
	mlx_put_map(all->mlx, all->points, all->maxy);
}

static void	ft_left(t_all_sct *all)
{
	int x;
	int y;

	y = -1;
	mlx_clear_window(all->mlx->mlx_ptr, all->mlx->win_ptr);
	while (++y < all->maxy->y)
	{
		x = -1;
		while (++x < all->maxy->x)
			all->points[x][y].x -= 5;
	}
	mlx_put_map(all->mlx, all->points, all->maxy);
}

static void	ft_up(t_all_sct *all)
{
	int x;
	int y;

	y = -1;
	mlx_clear_window(all->mlx->mlx_ptr, all->mlx->win_ptr);
	while (++y < all->maxy->y)
	{
		x = -1;
		while (++x < all->maxy->x)
			all->points[x][y].y -= 5;
	}
	mlx_put_map(all->mlx, all->points, all->maxy);
}

static void	ft_down(t_all_sct *all)
{
	int x;
	int y;

	y = -1;
	mlx_clear_window(all->mlx->mlx_ptr, all->mlx->win_ptr);
	while (++y < all->maxy->y)
	{
		x = -1;
		while (++x < all->maxy->x)
			all->points[x][y].y += 5;
	}
	mlx_put_map(all->mlx, all->points, all->maxy);
}

void		ft_moove(t_all_sct *all, int key)
{
	if (key == 124)
		ft_right(all);
	if (key == 123)
		ft_left(all);
	if (key == 126)
		ft_up(all);
	if (key == 125)
		ft_down(all);
}
