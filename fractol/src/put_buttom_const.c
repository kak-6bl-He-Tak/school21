/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_buttom_const.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtreutel <dtreutel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 20:26:11 by dtreutel          #+#    #+#             */
/*   Updated: 2019/03/20 13:50:44 by dtreutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	buttom1(t_mlx *mlx)
{
	t_line	line;

	line.x0 = 1;
	line.x1 = 41;
	line.y0 = 791;
	line.y1 = 791;
	line.clr0 = 0xFFFF;
	line.clr1 = 0xFFff;
	while (line.y0 < 800)
	{
		put_line(mlx, line);
		line.y0++;
		line.y1++;
	}
}

static void	buttom2(t_mlx *mlx)
{
	t_line	line;

	line.x0 = 51;
	line.x1 = 91;
	line.y0 = 791;
	line.y1 = 791;
	line.clr0 = 0xFFFF;
	line.clr1 = 0xFFff;
	while (line.y0 < 800)
	{
		put_line(mlx, line);
		line.y0++;
		line.y1++;
	}
}

static void	buttom3(t_mlx *mlx)
{
	t_line	line;

	line.x0 = 101;
	line.x1 = 141;
	line.y0 = 791;
	line.y1 = 791;
	line.clr0 = 0xFF00FF;
	line.clr1 = 0xFF00ff;
	while (line.y0 < 800)
	{
		put_line(mlx, line);
		line.y0++;
		line.y1++;
	}
}

static void	buttom4(t_mlx *mlx)
{
	t_line	line;

	line.x0 = 151;
	line.x1 = 191;
	line.y0 = 791;
	line.y1 = 791;
	line.clr0 = 0xFF00FF;
	line.clr1 = 0xFF00ff;
	while (line.y0 < 800)
	{
		put_line(mlx, line);
		line.y0++;
		line.y1++;
	}
}

void		put_buttom_const(t_mlx *mlx)
{
	buttom1(mlx);
	buttom2(mlx);
	buttom3(mlx);
	buttom4(mlx);
}
