/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtreutel <dtreutel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 19:13:05 by dtreutel          #+#    #+#             */
/*   Updated: 2019/03/20 20:31:21 by dtreutel         ###   ########.fr       */
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

static void		complex_init(t_sct *sct, int x)
{
	sct->c.re = (sct->mlx->factors.factorx +
			(x - sct->mlx->factors.stepx) * sct->mlx->factors.dx);
	sct->c.im = (sct->mlx->factors.factory
			+ (sct->starty - sct->mlx->factors.stepy) * sct->mlx->factors.dy);
}

static void		ft_abs(t_complex *z)
{
	z->re = fabs(z->re);
	z->im = fabs(z->im);
}

void			burningship(t_sct *sct)
{
	int			x;
	int			i;
	t_complex	res;

	while (++(sct->starty) < sct->maxy)
	{
		x = -1;
		while (++x < sct->mlx->x)
		{
			complex_init(sct, x);
			sct->z.re = 0;
			sct->z.im = 0;
			i = -1;
			while (++i < sct->mlx->maxi &&
				(sct->z.re * sct->z.re + sct->z.im * sct->z.im) < 4)
			{
				ft_abs(&sct->z);
				res.re = sct->z.re * sct->z.re - sct->z.im * sct->z.im;
				res.im = sct->z.re * sct->z.im + sct->z.im * sct->z.re;
				sct->z.re = res.re + sct->c.re;
				sct->z.im = res.im + sct->c.im;
			}
			color_pxls(sct, x, sct->starty, i);
		}
	}
}
