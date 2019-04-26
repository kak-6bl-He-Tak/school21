/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtreutel <dtreutel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 20:34:14 by dtreutel          #+#    #+#             */
/*   Updated: 2019/03/21 11:17:05 by dtreutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	mnogo_if(int *x, int *y)
{
	if (*x < 0)
		*x = 0;
	if (*x > 800)
		*x = 800;
	if (*y < 0)
		*y = 0;
	if (*y > 790)
		*y = 790;
}

static void	c_julia(int x, int y, t_mlx *mlx)
{
	mlx->factors.c.re = (mlx->factors.factorx +
				(x - mlx->factors.stepx) * mlx->factors.dx);
	mlx->factors.c.im = (mlx->factors.factory +
				(y - mlx->factors.stepy) * mlx->factors.dy);
	put_fractol(mlx);
}

int			mouse_move(int x, int y, t_mlx *mlx)
{
	if (mlx->press_iter == 1)
	{
		mlx->maxi -= mlx->maxi - (x - mlx->mouse_x) - mlx->save_slide;
		if (mlx->maxi > 400)
			mlx->maxi = 400;
		if (mlx->maxi < 0)
			mlx->maxi = 0;
		put_fractol(mlx);
	}
	if (mlx->press_moove == 1)
	{
		mnogo_if(&x, &y);
		mlx->factors.stepx -= mlx->factors.stepx -
				(x - mlx->mouse_x) - mlx->save_step_x;
		mlx->factors.stepy -= mlx->factors.stepy -
				(y - mlx->mouse_y) - mlx->save_step_y;
		put_fractol(mlx);
	}
	if (mlx->c_julia % 2 == 0)
		c_julia(x, y, mlx);
	return (0);
}
