/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_press.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtreutel <dtreutel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 16:39:08 by dtreutel          #+#    #+#             */
/*   Updated: 2019/03/20 16:46:59 by dtreutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		next_back(int x, t_mlx *mlx)
{
	if (x >= 620 && x <= 660)
	{
		mlx->fractol -= 1;
		if (mlx->fractol < 1)
			mlx->fractol = 4;
		factors_init(mlx);
		put_fractol(mlx);
	}
	if (x >= 700 && x <= 741)
	{
		mlx->fractol += 1;
		if (mlx->fractol > 4)
			mlx->fractol = 1;
		factors_init(mlx);
		put_fractol(mlx);
	}
}

static void		mnogo_if(int x, int y, t_mlx *mlx)
{
	if (x >= 12 && x <= 120 && y >= 17 && y <= 30)
	{
		mlx->clr_step = 1;
		clr_step(x, y, mlx);
		put_fractol(mlx);
	}
	else if (x >= 620 && x <= 741 && y >= 791 && y <= 799)
		next_back(x, mlx);
	else if (x >= 200 + mlx->maxi && x <= 200 + mlx->maxi + 6
			&& y >= 791 && y <= 799)
		mlx->press_iter = 1;
	else if (x > 0 && x < 800 && y > 0 && y < 790)
		mlx->press_moove = 1;
	else if (x >= 1 && x <= 191 && y > 791 && y < 799)
		mlx->mouse_hook = 1;
}

int				mouse_press(int key, int x, int y, t_mlx *mlx)
{
	if (key == 5 || key == 4)
	{
		zoom(key, mlx, x, y);
		put_fractol(mlx);
	}
	if (key == 1)
	{
		mlx->mouse_x = x;
		mlx->mouse_y = y;
		mnogo_if(x, y, mlx);
	}
	if (key == 2)
		if (x >= 12 && x <= 120 && y >= 17 && y <= 30)
		{
			mlx->clr_step = -1;
			clr_step(x, y, mlx);
			put_fractol(mlx);
		}
	return (0);
}
