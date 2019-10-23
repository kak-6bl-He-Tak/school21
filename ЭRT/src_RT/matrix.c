/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtreutel <dtreutel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 21:38:39 by dtreutel          #+#    #+#             */
/*   Updated: 2019/10/23 22:19:41 by dtreutel         ###   ########.fr       */
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
			printf("%f - %f", a->matrix[y][x], b->matrix[y][x]);
			if (!equal_custom(a->matrix[y][x], b->matrix[y][x]))
			{
				printf("tyt");
				return(0);
			}
		}
		printf(" | ");
	}
	return (1);
}
