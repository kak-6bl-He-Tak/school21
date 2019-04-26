/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   factors_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtreutel <dtreutel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 16:14:31 by dtreutel          #+#    #+#             */
/*   Updated: 2019/03/21 11:03:14 by dtreutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		factors_init(t_mlx *mlx)
{
	mlx->factors.coeff = 6;
	mlx->factors.factorx = -(mlx->factors.coeff / 2);
	mlx->factors.factory = -(mlx->factors.coeff / 2);
	mlx->factors.dx = mlx->factors.coeff / (mlx->x);
	mlx->factors.dy = mlx->factors.coeff / (mlx->y);
	mlx->factors.shift_clr = 0x030303;
	mlx->factors.stepx = 0;
	mlx->factors.stepy = 0;
	mlx->maxi = 150;
	mlx->press_iter = 0;
	mlx->save_slide = 150;
	mlx->press_moove = 0;
	mlx->save_step_x = 0;
	mlx->save_step_y = 0;
	mlx->mouse_hook = 0;
	mlx->c_julia = 0;
}
