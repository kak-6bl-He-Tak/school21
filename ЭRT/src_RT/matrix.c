/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtreutel <dtreutel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 21:38:39 by dtreutel          #+#    #+#             */
/*   Updated: 2019/10/24 21:31:46 by dtreutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		dell_matrix(t_matrix *mat)
{
	int	i;

	i = -1;
	if(mat != 0)
	{
		if(mat->matrix != 0)
		{
			while (++i < mat->size)
			{
				if (mat->matrix[i] != 0)
					ft_memdel((void **)&mat->matrix[i]);
			}
			ft_memdel((void **)mat->matrix);
		}
		ft_memdel((void **)&mat);
	}
}

t_matrix	*new_matrix(int size)
{
	t_matrix	*res;
	int			i;

	i = -1;
	if (!(res = ft_memalloc(sizeof(t_matrix))))
		return (0);
	if (!(res->matrix = ft_memalloc(sizeof(float *) * size)))
	{
		dell_matrix(res);
		return(0);
	}
	while (++i < size)
	{
		if (!(res->matrix[i] = ft_memalloc(sizeof(float) * size)))
		{
			dell_matrix(res);
			return (0);
		}
	}
	res->size = size;
	return(res);
}

int			equal_matrix(t_matrix *a, t_matrix *b)
{
	int		y;
	int		x;

	if (a == 0 || b == 0)
		ft_putendl("equal_matrix: one mateix == null!");
	if (a->size != b->size)
		return (0);
	y = -1;
	while (++y < a->size)
	{
		x = -1;
		while (++x < a->size)
		{
			if (!equal_custom(a->matrix[y][x], b->matrix[y][x]))
				return(0);
		}
	}
	return (1);
}

t_matrix	*multiply_matrix(t_matrix *a, t_matrix *b, t_matrix *dest)
{
	int	x;
	int	y;

	y = -1;
	while (++y < 4)
	{
		x = -1;
		while (++x < 4)
		{
			dest->matrix[y][x] =
				a->matrix[y][0] * b->matrix[0][x] +
				a->matrix[y][1] * b->matrix[1][x] +
				a->matrix[y][2] * b->matrix[2][x] +
				a->matrix[y][3] * b->matrix[3][x];
		}
	}
	return (dest);
}

t_tuple		multiply_matrix_with_tuple(t_matrix *a, t_tuple b)
{
	t_tuple	res;
	float	**mat;

	mat = a->matrix;
	res.x = b.x * mat[0][0] + b.y * mat[0][1] + b.z * mat[0][2] + b.w * mat[0][3];
	res.y = b.x * mat[1][0] + b.y * mat[1][1] + b.z * mat[1][2] + b.w * mat[1][3];
	res.z = b.x * mat[2][0] + b.y * mat[2][1] + b.z * mat[2][2] + b.w * mat[2][3];
	res.w = b.x * mat[3][0] + b.y * mat[3][1] + b.z * mat[3][2] + b.w * mat[3][3];
	return (res);
}

void		make_identity_matrix(float **mat, int size)
{
	int	y;
	int	x;

	y = -1;
	while (++y < size)
	{
		x = -1;
		while (++x < size)
		{
			if (y == x)
				mat[y][x] = 1.0;
			else
				mat[y][x] = 0.0;
		}
	}
}


void		aza(float **a)
{
	printf("%f", a[0][3]);
}

t_matrix	*multiply_identity_matrix(t_matrix *a, t_matrix *dest)
{
	float		id_mat[4][4] = {
		{1.0, 2.0, 3.0, 1.0},
		{2.0, 3.0, 4.0, 1.0},
		{3.0, 4.0, 5.0, 1.0},
		{4.0, 5.0, 6.0, 1.0}};
	// t_matrix	identity;
	float **azaz;
	float *b;

	b = id_mat[0];
	azaz = &b;
	a = 0;
	aza(azaz);
	// make_identity_matrix((float **)id_mat, 4);
	// identity.matrix = (float **)id_mat;
	// printf("%f", identity.matrix[0][0]);
	// dest = multiply_matrix(a, &identity, dest);
	return(dest);
}

