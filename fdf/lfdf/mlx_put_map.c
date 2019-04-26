/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_iso_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtreutel <dtreutel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 11:24:21 by dtreutel          #+#    #+#             */
/*   Updated: 2019/02/04 16:05:44 by dtreutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	put_xxxline(t_mlx *mlx, t_point **points, t_x_and_y *maxy)
{
	int		x;
	int		y;
	t_line	line;

	y = -1;
	while (++y < maxy->y)
	{
		x = 0;
		while (++x < maxy->x)
		{
			give_line(&line, points[x - 1][y], points[x][y]);
			mlx_put_line(mlx, line);
		}
	}
}

static void	put_yyyline(t_mlx *mlx, t_point **points, t_x_and_y *maxy)
{
	int		x;
	int		y;
	t_line	line;

	x = -1;
	while (++x < maxy->x)
	{
		y = 0;
		while (++y < maxy->y)
		{
			give_line(&line, points[x][y - 1], points[x][y]);
			mlx_put_line(mlx, line);
		}
	}
}

void		mlx_put_map(t_mlx *mlx, t_point **points, t_x_and_y *maxy)
{
	put_xxxline(mlx, points, maxy);
	put_yyyline(mlx, points, maxy);
}
