/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtreutel <dtreutel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 21:38:39 by dtreutel          #+#    #+#             */
/*   Updated: 2019/10/27 12:47:17 by dtreutel         ###   ########.fr       */
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

t_matrix	*multiply_identity_matrix(t_matrix *a, t_matrix *dest)
{
	static float	mat[4][4] = {{1.0, 0.0, 0.0, 0.0},
								{0.0, 1.0, 0.0, 0.0},
								{0.0, 0.0, 1.0, 0.0},
								{0.0, 0.0, 0.0, 1.0}};
	int				x;
	int				y;

	y = -1;
	while (++y < 4)
	{
		x = -1;
		while (++x < 4)
		{
			dest->matrix[y][x] =
				a->matrix[y][0] * mat[0][x] +
				a->matrix[y][1] * mat[1][x] +
				a->matrix[y][2] * mat[2][x] +
				a->matrix[y][3] * mat[3][x];
		}
	}
	return(dest);
}


t_tuple		multiply_identity_matrix_with_tuple(t_tuple b)
{
	static float	mat[4][4] = {
		{1.0, 0.0, 0.0, 0.0},
		{0.0, 1.0, 0.0, 0.0},
		{0.0, 0.0, 1.0, 0.0},
		{0.0, 0.0, 0.0, 1.0}};
	t_tuple			res;

	res.x = b.x * mat[0][0] + b.y * mat[0][1] + b.z * mat[0][2] + b.w * mat[0][3];
	res.y = b.x * mat[1][0] + b.y * mat[1][1] + b.z * mat[1][2] + b.w * mat[1][3];
	res.z = b.x * mat[2][0] + b.y * mat[2][1] + b.z * mat[2][2] + b.w * mat[2][3];
	res.w = b.x * mat[3][0] + b.y * mat[3][1] + b.z * mat[3][2] + b.w * mat[3][3];
	return (res);
}


t_matrix		*transposing_matrix(t_matrix *a)
{
	static float	mat[4][4] = {
		{1.0, 0.0, 0.0, 0.0},
		{0.0, 1.0, 0.0, 0.0},
		{0.0, 0.0, 1.0, 0.0},
		{0.0, 0.0, 0.0, 1.0}};
	int		y;
	int		x;

	y = -1;
	while (++y < a->size)
	{
		x = -1;
		while(++x < a->size)
		{
			mat[y][x] = a->matrix[x][y];
		}
	}
	y = -1;
	while (++y < a->size)
		ft_memcpy(a->matrix[y], mat[y], sizeof(float) * a->size);
	return(a);
}

float			determinant_matrix_two(float *a, float *b)
{
	return(a[0] * b[1] - b[0] * a[1]);
}

t_matrix		*spot_submatrix(t_matrix *a, t_matrix *dest, int del_y, int del_x)
{
	int	x;
	int	y;
	int	corr_x;
	int	corr_y;

	y = -1;
	while(++y < dest->size)
	{
		corr_y = y;
		if (corr_y >= del_y)
			corr_y += 1;
		x = -1;
		while(++x < dest->size)
		{
			corr_x = x;
			if (corr_x >= del_x)
				corr_x += 1;
			dest->matrix[y][x] = a->matrix[corr_y][corr_x];
		}
	}
	return(dest);
}

float			minor_matrix_three(t_matrix *a, int del_y, int del_x)
{
	t_matrix	*sub_mat;
	float		res;

	sub_mat = new_matrix(2);
	sub_mat = spot_submatrix(a, sub_mat, del_y, del_x);
	res = determinant_matrix_two(sub_mat->matrix[0], sub_mat->matrix[1]);
	dell_matrix(sub_mat);
	return(res);
}

float		cofactor_minor_matrix(t_matrix *a, int del_y, int del_x)
{
	float		res;
	t_matrix	*sub_mat;
	float		correct;

	correct = pow(-1.0, del_y + del_x);
	sub_mat = new_matrix(a->size - 1);
	sub_mat = spot_submatrix(a, sub_mat, del_y, del_x);
	res = determinant_matrix(sub_mat);
	dell_matrix(sub_mat);
	return(res * correct);
}

float		determinant_matrix_three(t_matrix *a)
{
	float	res;

	res = a->matrix[0][0] * cofactor_minor_matrix(a, 0, 0) +
		a->matrix[0][1] * cofactor_minor_matrix(a, 0, 1) +
		a->matrix[0][2] * cofactor_minor_matrix(a, 0, 2);
	return(res);
}

float		determinant_matrix_four(t_matrix *a)
{
	float		res;
	t_matrix	*mat;
	int			x;

	res = 0;
	x = -1;
	mat = new_matrix(3);
	while(++x < 4)
	{
		mat = spot_submatrix(a, mat, 0, x);
		res += a->matrix[0][x] * cofactor_minor_matrix(a, 0, x);
	}
	dell_matrix(mat);
	return(res);
}

float		determinant_matrix(t_matrix *a)
{
	if (a->size == 2)
		return(determinant_matrix_two(a->matrix[0], a->matrix[1]));
	if (a->size == 3)
		return(determinant_matrix_three(a));
	else
		return(determinant_matrix_four(a));
}

int			valid_invertion_matrix(t_matrix *a)
{
	float	det;

	det = determinant_matrix(a);
	if (equal_custom(det, 0.0) == 1)
		return (0);
	return (1);
}

t_matrix	*inverse_matrix(t_matrix *a, t_matrix *dest)
{
	int		y;
	int		x;
	float	det;

	if (!valid_invertion_matrix(a))
	{
		dell_matrix(dest);
		dest = 0;
	}
	else
	{
		det = determinant_matrix(a);
		y = -1;
		while(++y < a->size)
		{
			x = -1;
			while(++x < a->size)
				dest->matrix[x][y] = cofactor_minor_matrix(a, y, x) / det;
		}
	}
	return(dest);
}

void		identity_matrix(t_matrix *a)
{
	int	x;
	int	y;

	y = -1;
	while(++y < a->size)
	{
		x = -1;
		while(++x < a->size)
		{
			if (y == x)
				a->matrix[y][x] = 1.0;
			else
				a->matrix[y][x] = 0.0;
		}
	}
}


t_matrix	*get_move_matrix(t_tuple a)
{
	t_matrix *res;

	res = new_matrix(4);
	identity_matrix(res);
	res->matrix[0][3] = a.x;
	res->matrix[1][3] = a.y;
	res->matrix[2][3] = a.z;
	return(res);
}

t_matrix	*get_scale_matrix(t_tuple a)
{
	t_matrix *res;

	res = new_matrix(4);
	res->matrix[0][0] = a.x;
	res->matrix[1][1] = a.y;
	res->matrix[2][2] = a.z;
	res->matrix[3][3] = 1.0;
	return(res);
}
