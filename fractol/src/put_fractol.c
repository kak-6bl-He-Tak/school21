/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_fractol.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtreutel <dtreutel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 11:28:25 by dtreutel          #+#    #+#             */
/*   Updated: 2019/03/20 18:45:26 by dtreutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		put_clr_str(t_mlx *mlx)
{
	char	*clr;

	clr = ft_itoa(mlx->factors.shift_clr / 256 / 256);
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 10, 10, 0xff0000, clr);
	ft_strdel(&clr);
	clr = ft_itoa(mlx->factors.shift_clr / 256 % 256);
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 50, 10, 0xff00, clr);
	ft_strdel(&clr);
	clr = ft_itoa(mlx->factors.shift_clr % 256);
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 90, 10, 0xff, clr);
	ft_strdel(&clr);
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 200, 770, 0xffffff,
			"min            iterations             max");
	if (mlx->fractol == 1)
		mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 1, 770, 0xffffff,
				"re++ re-- im++ im--");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 620, 770, 0xffffff,
			"back    next");
}

static void		*choice_fractol(t_sct *sct)
{
	if (sct->mlx->fractol == 1)
		julia(sct);
	if (sct->mlx->fractol == 2)
		mandelbrot(sct);
	if (sct->mlx->fractol == 3)
		burningship(sct);
	if (sct->mlx->fractol == 4)
		burningass(sct);
	return (0);
}

void			put_fractol(t_mlx *mlx)
{
	pthread_t	threads[8];
	t_sct		sct[8];
	static int	j = 0;
	int			i;

	if (j++ == 0)
		factors_init(mlx);
	i = -1;
	while (++i < 8)
	{
		sct[i].starty = 100 * i - 1;
		sct[i].maxy = sct[i].starty + 101;
		sct[i].mlx = mlx;
		pthread_create(&threads[i], 0, (void *)choice_fractol, (void *)&sct[i]);
	}
	i = -1;
	while (++i < 8)
		pthread_join(threads[i], 0);
	if (mlx->fractol == 1)
		put_buttom_const(mlx);
	put_buttom_iter(mlx);
	put_buttom_fract(mlx);
	mlx_clear_window(mlx->mlx_ptr, mlx->win_ptr);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img_ptr, 0, 0);
	put_clr_str(mlx);
}
