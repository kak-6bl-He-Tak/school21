/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_put_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtreutel <dtreutel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/03 13:51:46 by dtreutel          #+#    #+#             */
/*   Updated: 2019/02/03 17:38:04 by dtreutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		ft_abs(int a, int b)
{
	int	res;

	res = a - b;
	if (res < 0)
		res *= -1;
	return (res);
}

void			mlx_put_line(t_mlx *mlx, t_line line)
{
	t_val	values;

	values.deltax = ft_abs(line.x1, line.x0);
	values.deltay = ft_abs(line.y1, line.y0);
	values.signx = line.x0 < line.x1 ? 1 : -1;
	values.signy = line.y0 < line.y1 ? 1 : -1;
	values.error = values.deltax - values.deltay;
	mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr, line.x1, line.y1, 0x00FFFF);
	while (line.x0 != line.x1 || line.y0 != line.y1)
	{
		mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr, line.x0,
				line.y0, 0x00FFFF);
		values.error2 = values.error * 2;
		if (values.error2 > values.deltay * -1)
		{
			values.error -= values.deltay;
			line.x0 += values.signx;
		}
		if (values.error2 < values.deltax)
		{
			values.error += values.deltax;
			line.y0 += values.signy;
		}
	}
}
