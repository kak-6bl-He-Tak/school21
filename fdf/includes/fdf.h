/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtreutel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 11:13:46 by dtreutel          #+#    #+#             */
/*   Updated: 2019/02/10 18:43:36 by dtreutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H

# define FDF_H
# include "mlx.h"
# include "libft.h"
# include "fcntl.h"
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# define CLR 0xFF0000
# define STEP 10
# define X0 500
# define Y0 500
# define CSTEP 4

typedef struct	s_1
{
	int			x0;
	int			x1;
	int			y0;
	int			y1;
	int			clr0;
	int			clr1;
}				t_line;

typedef struct	s_2
{
	int			deltax;
	int			deltay;
	int			signx;
	int			signy;
	int			error;
	int			error2;
}				t_val;

typedef struct	s_3
{
	void		*mlx_ptr;
	void		*win_ptr;
}				t_mlx;

typedef struct	s_4
{
	int			x;
	int			y;
	int			z;
	int			clr;
}				t_point;

typedef struct	s_5
{
	int			x;
	int			y;
}				t_x_and_y;

typedef struct	s_6
{
	t_mlx		*mlx;
	t_point		**points;
	t_x_and_y	*maxy;
}				t_all_sct;

int				fdf(int fd);
int				read_file(int fd, char **str);
int				valid_file(char *str);
int				ex(t_all_sct *all);
void			ft_refactor(t_all_sct *all, int key);
void			ft_moove(t_all_sct *all, int key);
void			ft_zoom(t_all_sct *all);
void			ft_unzoom(t_all_sct *all);
void			mlx_pers_map(t_all_sct *all);
void			decart_points(t_point **points, t_x_and_y *maxy);
void			del_points_map(t_all_sct *all);
void			iso_points(t_point **points, t_x_and_y *maxy);
void			mlx_put_map(t_mlx *mlx, t_point **points, t_x_and_y *maxy);
void			give_line(t_line *line, t_point point0, t_point point1);
void			mlx_put_line(t_mlx *mlx, t_line line);
t_point			**get_points_map(int fd, t_x_and_y *maxy);

#endif
