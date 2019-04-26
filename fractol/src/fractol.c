/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtreutel <dtreutel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 19:59:57 by dtreutel          #+#    #+#             */
/*   Updated: 2019/03/21 15:21:46 by dtreutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int				press_key(int key, t_mlx *mlx)
{
	if (key == 53)
		ft_exit(mlx);
	if (key == 36)
	{
		factors_init(mlx);
		put_fractol(mlx);
	}
	if (key >= 123 && key <= 126)
	{
		key_move(key, mlx);
		put_fractol(mlx);
	}
	if (key == 49)
		mlx->c_julia += 1;
	return (0);
}

static int				mouse_release(int key, int x, int y, t_mlx *mlx)
{
	if (key == 1)
	{
		mlx->press_iter = 0;
		mlx->save_slide = mlx->maxi;
		mlx->press_moove = 0;
		mlx->save_step_x = mlx->factors.stepx;
		mlx->save_step_y = mlx->factors.stepy;
		mlx->mouse_hook = 0;
	}
	x = y;
	return (0);
}

static int				loop_hook(t_mlx *mlx)
{
	if (mlx->mouse_hook)
	{
		if (mlx->mouse_x >= 1 && mlx->mouse_x <= 41 && mlx->fractol == 1)
			mlx->factors.c.re += 0.0001;
		if (mlx->mouse_x >= 51 && mlx->mouse_x <= 91 && mlx->fractol == 1)
			mlx->factors.c.re -= 0.0001;
		if (mlx->mouse_x >= 101 && mlx->mouse_x <= 141 && mlx->fractol == 1)
			mlx->factors.c.im += 0.0001;
		if (mlx->mouse_x >= 151 && mlx->mouse_x <= 191 && mlx->fractol == 1)
			mlx->factors.c.im -= 0.0001;
		put_fractol(mlx);
	}
	return (0);
}

void					fractol(int i)
{
	t_mlx	mlx;

	mlx.mlx_ptr = mlx_init();
	mlx.x = 800;
	mlx.y = 800;
	mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, mlx.x, mlx.y, "#0420");
	mlx.img_ptr = mlx_new_image(mlx.mlx_ptr, mlx.x, mlx.y);
	mlx.img_data = mlx_get_data_addr(mlx.img_ptr, &mlx.bpp,
			&mlx.size_line, &mlx.end);
	mlx.fractol = i;
	put_fractol(&mlx);
	mlx_hook(mlx.win_ptr, 17, 0, ft_exit, &mlx);
	mlx_hook(mlx.win_ptr, 2, 0, press_key, &mlx);
	mlx_hook(mlx.win_ptr, 4, 0, mouse_press, &mlx);
	mlx_hook(mlx.win_ptr, 5, 0, mouse_release, &mlx);
	mlx_hook(mlx.win_ptr, 6, 0, mouse_move, &mlx);
	mlx_loop_hook(mlx.mlx_ptr, loop_hook, &mlx);
	mlx_loop(mlx.mlx_ptr);
}
