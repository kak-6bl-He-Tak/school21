/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtreutel <dtreutel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 17:01:52 by dtreutel          #+#    #+#             */
/*   Updated: 2019/03/20 13:57:49 by dtreutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	zoom(int key, t_mlx *mlx, int x, int y)
{
	if (y > -1)
	{
		if (key == 5 && (mlx->factors.coeff > 0.000001))
		{
			x -= mlx->x / 2;
			y -= mlx->x / 2;
			mlx->factors.stepx = mlx->factors.stepx * 1.25 + (x - x * 1.25);
			mlx->factors.stepy = mlx->factors.stepy * 1.25 + (y - y * 1.25);
			mlx->factors.coeff *= 0.8;
		}
		if (key == 4 && mlx->factors.coeff * 1.25 <= 6)
		{
			x -= mlx->x / 2;
			y -= mlx->x / 2;
			mlx->factors.stepx = mlx->factors.stepx * 0.8 + (x - x * 0.8);
			mlx->factors.stepy = mlx->factors.stepy * 0.8 + (y - y * 0.8);
			mlx->factors.coeff *= 1.25;
		}
		mlx->save_step_x = mlx->factors.stepx;
		mlx->save_step_y = mlx->factors.stepy;
		mlx->factors.factorx = -(mlx->factors.coeff / 2);
		mlx->factors.factory = -(mlx->factors.coeff / 2);
		mlx->factors.dx = mlx->factors.coeff / (mlx->x);
		mlx->factors.dy = mlx->factors.coeff / (mlx->y);
	}
}
