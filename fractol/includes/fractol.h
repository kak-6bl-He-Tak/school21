/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtreutel <dtreutel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 11:20:01 by dtreutel          #+#    #+#             */
/*   Updated: 2019/03/21 11:03:14 by dtreutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_FRACTOL_H
# define FRACTOL_FRACTOL_H

# include "mlx.h"
# include "libft.h"
# include <stdlib.h>
# include <math.h>
# include <stdlib.h>
# include <pthread.h>

typedef struct	s_1
{
	double		re;
	double		im;
}				t_complex;

typedef struct	s_2
{
	double		coeff;
	double		factorx;
	double		factory;
	double		dx;
	double		dy;
	t_complex	z;
	t_complex	c;
	int			shift_clr;
	int			stepx;
	int			stepy;
}				t_factors;

typedef struct	s_3
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
	char		*img_data;
	int			bpp;
	int			size_line;
	int			end;
	int			x;
	int			y;
	int			maxi;
	t_factors	factors;
	int			fractol;
	int			mouse_x;
	int			mouse_y;
	int			press_iter;
	int			save_slide;
	int			press_moove;
	int			save_step_x;
	int			save_step_y;
	int			mouse_hook;
	int			clr_step;
	int			c_julia;
}				t_mlx;

typedef struct	s_4
{
	int			x0;
	int			y0;
	int			clr0;
	int			x1;
	int			y1;
	int			clr1;
}				t_line;

typedef struct	s_5
{
	int			deltax;
	int			deltay;
	int			signx;
	int			signy;
	int			error;
	int			error2;
}				t_val;

typedef struct	s_6
{
	int			starty;
	int			maxy;
	t_mlx		*mlx;
	t_complex	z;
	t_complex	c;
}				t_sct;

int				ft_exit(t_mlx *mlx);
int				mouse_move(int x, int y, t_mlx *mlx);
int				mouse_press(int key, int x, int y, t_mlx *mlx);
void			fractol(int i);
void			julia(t_sct *sct);
void			key_move(int key, t_mlx *mlx);
void			burningship(t_sct *sct);
void			burningass(t_sct *sct);
void			factors_init(t_mlx *mlx);
void			put_buttom_iter(t_mlx *mlx);
void			put_buttom_const(t_mlx *mlx);
void			put_buttom_fract(t_mlx *mlx);
void			mandelbrot(t_sct *sct);
void			put_fractol(t_mlx *mlx);
void			zoom(int key, t_mlx *mlx, int x, int y);
void			clr_step(int x, int y, t_mlx *mlx);
void			put_line(t_mlx *mlx, t_line line);
void			set_pxl(char *str, int x, int y, int clr);

#endif
