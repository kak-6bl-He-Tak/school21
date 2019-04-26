/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtreutel <dtreutel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 19:13:05 by dtreutel          #+#    #+#             */
/*   Updated: 2019/03/19 11:44:19 by dtreutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		color_pxls(t_sct *sct, int x, int y, int i)
{
	if (i < sct->mlx->maxi)
		set_pxl(sct->mlx->img_data, x * 4,
				sct->starty * sct->mlx->size_line,
					i * sct->mlx->factors.shift_clr);
	else
		set_pxl(sct->mlx->img_data, x * 4,
				y * sct->mlx->size_line, 0);
}

void			julia(t_sct *sct)
{
	int			x;
	int			i;
	t_complex	res;

	while (++(sct->starty) < sct->maxy)
	{
		x = -1;
		while (++x < sct->mlx->x)
		{
			sct->z.re = (sct->mlx->factors.factorx +
					(x - sct->mlx->factors.stepx) * sct->mlx->factors.dx);
			sct->z.im = (sct->mlx->factors.factory +
			(sct->starty - sct->mlx->factors.stepy) * sct->mlx->factors.dy);
			i = -1;
			while (++i < sct->mlx->maxi && (sct->z.re *
				sct->z.re + sct->z.im * sct->z.im) < 4)
			{
				res.re = sct->z.re * sct->z.re - sct->z.im * sct->z.im;
				res.im = sct->z.re * sct->z.im + sct->z.im * sct->z.re;
				sct->z.re = res.re + sct->mlx->factors.c.re;
				sct->z.im = res.im + sct->mlx->factors.c.im;
			}
			color_pxls(sct, x, sct->starty, i);
		}
	}
}
