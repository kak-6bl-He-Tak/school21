/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_buttom_fract.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtreutel <dtreutel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 14:54:09 by dtreutel          #+#    #+#             */
/*   Updated: 2019/03/20 16:31:43 by dtreutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		koroche1(t_mlx *mlx, t_line *line)
{
	while (line->y0 >= 789)
	{
		put_line(mlx, *line);
		line->x0 += 1;
		line->x1 += 1;
		line->y0 -= 1;
		line->y1 += 1;
	}
}

static void		koroche2(t_mlx *mlx, t_line *line)
{
	line->x1 = 660;
	line->y1 = line->y0;
	line->clr0 = 0xfFfF00;
	line->clr1 = 0xffff00;
	while (line->y0 < 800)
	{
		put_line(mlx, *line);
		line->y0 += 1;
		line->y1 += 1;
	}
}

static void		koroche3(t_mlx *mlx, t_line *line)
{
	line->x0 = 700;
	line->x1 = 735;
	line->y0 = 788;
	line->y1 = 788;
	line->clr0 = 0xfFfF00;
	line->clr1 = 0xfFff00;
	while (line->y0 < 800)
	{
		put_line(mlx, *line);
		line->y0 += 1;
		line->y1 += 1;
	}
}

static void		koroche4(t_mlx *mlx, t_line *line)
{
	line->x0 = line->x1;
	line->y0 = 788;
	line->y1 = 800;
	line->clr0 = 0xfFfF00;
	line->clr1 = 0xfFff00;
	while (line->y0 <= 794)
	{
		put_line(mlx, *line);
		line->x0 += 1;
		line->x1 += 1;
		line->y0 += 1;
		line->y1 -= 1;
	}
}

void			put_buttom_fract(t_mlx *mlx)
{
	t_line	line;

	line.x0 = 620;
	line.x1 = 620;
	line.y0 = 794;
	line.y1 = 794;
	line.clr0 = 0xfFfF00;
	line.clr1 = 0xfFff00;
	koroche1(mlx, &line);
	koroche2(mlx, &line);
	koroche3(mlx, &line);
	koroche4(mlx, &line);
}
