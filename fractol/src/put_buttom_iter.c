/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_buttom.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtreutel <dtreutel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 14:38:07 by dtreutel          #+#    #+#             */
/*   Updated: 2019/03/20 14:09:41 by dtreutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	buttom_koroche(t_mlx *mlx, t_line line)
{
	line.x0 = line.x0 + mlx->maxi + 1;
	line.x1 = line.x0 + 6;
	line.y0 = 791;
	line.y1 = 791;
	line.clr0 = 0;
	line.clr1 = 0;
	while (line.y1 < 799)
	{
		put_line(mlx, line);
		line.y0++;
		line.y1++;
	}
}

void		put_buttom_iter(t_mlx *mlx)
{
	t_line	line;

	line.x0 = 199;
	line.x1 = 607;
	line.y0 = 790;
	line.y1 = 790;
	line.clr0 = 0xFFFFFF;
	line.clr1 = 0xFF0000;
	while (line.y0 <= 800)
	{
		put_line(mlx, line);
		line.y0++;
		line.y1++;
	}
	buttom_koroche(mlx, line);
}
