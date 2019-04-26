/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_move.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtreutel <dtreutel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 10:50:31 by dtreutel          #+#    #+#             */
/*   Updated: 2019/03/21 10:56:33 by dtreutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	key_move(int key, t_mlx *mlx)
{
	if (key == 123)
		mlx->factors.stepx -= 20;
	if (key == 124)
		mlx->factors.stepx += 20;
	if (key == 125)
		mlx->factors.stepy += 20;
	if (key == 126)
		mlx->factors.stepy -= 20;
	mlx->save_step_x = mlx->factors.stepx;
	mlx->save_step_y = mlx->factors.stepy;
}
