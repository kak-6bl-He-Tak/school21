/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clr_step.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtreutel <dtreutel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 11:14:31 by dtreutel          #+#    #+#             */
/*   Updated: 2019/03/20 13:34:10 by dtreutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	red_clr_step(t_mlx *mlx)
{
	if (mlx->clr_step < 0)
		if (mlx->factors.shift_clr / 256 / 256 >= 1)
			mlx->factors.shift_clr -= 0x010000;
	if (mlx->clr_step > 0)
		if (mlx->factors.shift_clr / 256 / 256 >= 0 &&
			mlx->factors.shift_clr / 256 / 256 < 255)
			mlx->factors.shift_clr += 0x010000;
}

static void	green_clr_step(t_mlx *mlx)
{
	if (mlx->clr_step < 0)
		if ((mlx->factors.shift_clr / 256) % 256 >= 1)
			mlx->factors.shift_clr -= 0x0100;
	if (mlx->clr_step > 0)
		if ((mlx->factors.shift_clr / 256) % 256 >= 0 &&
				(mlx->factors.shift_clr / 256) % 256 < 255)
			mlx->factors.shift_clr += 0x0100;
}

static void	blue_clr_step(t_mlx *mlx)
{
	if (mlx->clr_step < 0)
		if (mlx->factors.shift_clr % 256 >= 1)
			mlx->factors.shift_clr -= 0x01;
	if (mlx->clr_step > 0)
		if (mlx->factors.shift_clr % 256 >= 0 &&
				mlx->factors.shift_clr % 256 < 255)
			mlx->factors.shift_clr += 0x01;
}

void		clr_step(int x, int y, t_mlx *mlx)
{
	if (x >= 12 && y >= 17 && x <= 40 && y <= 30)
		red_clr_step(mlx);
	else if (x >= 51 && y >= 17 && x <= 79 && y <= 30)
		green_clr_step(mlx);
	else if (x >= 91 && y >= 17 && x <= 120 && y <= 30)
		blue_clr_step(mlx);
}
