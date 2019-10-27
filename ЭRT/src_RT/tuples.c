/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuples.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtreutel <dtreutel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 19:18:08 by dtreutel          #+#    #+#             */
/*   Updated: 2019/10/27 12:57:46 by dtreutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_tuple		new_point(float x, float y, float z)
{
	t_tuple result;

	result.x = x;
	result.y = y;
	result.z = z;
	result.w = 1.0;
	return (result);
}

t_tuple		new_vector(float x, float y, float z)
{
	t_tuple result;

	result.x = x;
	result.y = y;
	result.z = z;
	result.w = 0.0;
	return (result);

}

t_tuple		move_tuple(t_tuple a, t_tuple move)
{
	t_tuple		res;
	t_matrix	*move_mat;

	move_mat = get_move_matrix(move);
	res = multiply_matrix_with_tuple(move_mat, a);
	dell_matrix(move_mat);
	return(res);
}

t_tuple		rvrs_move_tuple(t_tuple src, t_tuple move)
{
	t_tuple		res;
	t_matrix	*move_mat;
	t_matrix	*inv_mat;

	inv_mat = new_matrix(4);
	move_mat = get_move_matrix(move);
	inverse_matrix(move_mat, inv_mat);
	res = multiply_matrix_with_tuple(inv_mat, src);
	dell_matrix(move_mat);
	dell_matrix(inv_mat);
	return(res);
}

t_tuple		scale_tuple(t_tuple src, t_tuple scale)
{
	t_tuple		res;
	t_matrix	*mat_scale;

	mat_scale = get_scale_matrix(scale);
	res = multiply_matrix_with_tuple(mat_scale, src);
	dell_matrix(mat_scale);
	return(res);
}

t_tuple		rvrs_scale_tuple(t_tuple src, t_tuple scale)
{
	t_tuple		res;
	t_matrix	*mat_scale;
	t_matrix	*inv_mat;

	inv_mat = new_matrix(4);
	mat_scale = get_scale_matrix(scale);
	inverse_matrix(mat_scale, inv_mat);
	res = multiply_matrix_with_tuple(inv_mat, src);
	dell_matrix(mat_scale);
	dell_matrix(inv_mat);
	return(res);
}
