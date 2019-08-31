/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shapes.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtreutel <dtreutel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 14:55:21 by udraugr-          #+#    #+#             */
/*   Updated: 2019/08/31 10:56:38 by dtreutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHAPES_H
# define SHAPES_H

# define PLANE 11
# define SPHERE 12
# define CYLINDER 13
# define CONE 14
# define LIGHT 69
# define CAMERA 100

typedef struct			s_plane
{
	float				dot[3];
	float				normal[3];
}						t_plane;

typedef struct			s_sphere
{
	float				center[3];
	float				radius;
}						t_sphere;

typedef struct			s_cylinder
{
	float				start[3];
	float				axis[3];
	float				radius;
}						t_cylinder;

typedef struct			s_cone
{
	float				vertex[3];
	float				axis[3];
	float				angle;
}						t_cone;

typedef struct			s_light
{
	char				type;
	float				intensive;
	float				center[3];
	float				vector[3];
}						t_light;

#endif
