/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtreutel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 17:08:53 by dtreutel          #+#    #+#             */
/*   Updated: 2019/02/11 14:06:00 by dtreutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		deal_key(int key, t_all_sct *all)
{
	if (key == 36 || key == 76)
	{
		mlx_clear_window(all->mlx->mlx_ptr, all->mlx->win_ptr);
		iso_points(all->points, all->maxy);
		mlx_put_map(all->mlx, all->points, all->maxy);
	}
	if (key == 35)
	{
		mlx_pers_map(all);
		mlx_clear_window(all->mlx->mlx_ptr, all->mlx->win_ptr);
		mlx_put_map(all->mlx, all->points, all->maxy);
	}
	if (key == 53)
	{
		del_points_map(all);
		exit(0);
	}
	return (0);
}

int		press_key(int key, t_all_sct *all)
{
	if (key == 116 || key == 121 || key == 115 || key == 119)
		ft_refactor(all, key);
	if (key == 124 || key == 123 || key == 125 || key == 126)
		ft_moove(all, key);
	return (0);
}

int		fdf(int fd)
{
	t_mlx		mlx;
	t_x_and_y	maxy;
	t_point		**points;
	t_all_sct	all;

	if (!(points = get_points_map(fd, &maxy)))
		return (0);
	mlx.mlx_ptr = mlx_init();
	mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, 1000, 1000, "#0420");
	mlx_string_put(mlx.mlx_ptr, mlx.win_ptr, 450, 500, 0xFF0000, "PRESS ENTER");
	all.mlx = &mlx;
	all.points = points;
	all.maxy = &maxy;
	mlx_key_hook(mlx.win_ptr, deal_key, &all);
	mlx_hook(mlx.win_ptr, 17, 0, ex, &all);
	mlx_hook(mlx.win_ptr, 2, 0, press_key, &all);
	mlx_loop(mlx.mlx_ptr);
	return (1);
}
