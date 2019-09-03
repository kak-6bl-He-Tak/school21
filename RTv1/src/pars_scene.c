/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtreutel <dtreutel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 13:49:46 by dtreutel          #+#    #+#             */
/*   Updated: 2019/09/03 18:53:38 by udraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static int		open_file(char *str)
{
	int			fd;
	char		a[1];

	fd = open(str, O_RDONLY);
	if (read(fd, a, 0) == -1)
	{
		fd = 0;
		perror("Open file");
	}
	return (fd);
}

int			set_camera(t_obj **obj, char *gnl)
{
	char	*save;
	float	*camera;

	save = &gnl[11];
	obj[0]->type = CAMERA;
	if (!(obj[0]->shape = ft_memalloc(sizeof(float) * 3)))
		return (0);

	camera = (float *)obj[0]->shape;
	camera[0] = ft_scan_digit(&save);
	camera[1] = ft_scan_digit(&save);
	camera[2] = ft_scan_digit(&save);
	return (1);
}

int			set_sphere(t_obj **obj, char *gnl)
{
	char		*save;
	t_sphere	*sphere;

	obj[0]->type = SPHERE;
	if (!(obj[0]->shape = ft_memalloc(sizeof(t_sphere))))
		return (0);
	sphere = (t_sphere *)obj[0]->shape;
	save = &gnl[11];
	sphere->center[0] = ft_scan_digit(&save);
	sphere->center[1] = ft_scan_digit(&save);
	sphere->center[2] = ft_scan_digit(&save);
	sphere->radius = ft_scan_digit(&save);
	obj[0]->clr = (int)ft_scan_digit(&save);
	return (1);
}

int			set_plane(t_obj **obj, char *gnl)
{
	char	*save;
	t_plane	*plane;
	float	len_normal;
	float	normal[3];

	obj[0]->type = PLANE;
	if (!(obj[0]->shape = (t_plane *)ft_memalloc(sizeof(t_plane))))
		return (0);
	save = &gnl[11];
	plane = (t_plane *)obj[0]->shape;
	plane->dot[0] = ft_scan_digit(&save);
	plane->dot[1] = ft_scan_digit(&save);
	plane->dot[2] = ft_scan_digit(&save);
	normal[0] = ft_scan_digit(&save);
	normal[1] = ft_scan_digit(&save);
	normal[2] = ft_scan_digit(&save);
	len_normal = len_vector(normal);
	plane->normal[0] = normal[0] / len_normal;
	plane->normal[1] = normal[1] / len_normal;
	plane->normal[2] = normal[2] / len_normal;
	printf("\n\n%f, %f, %f, %f\n", len_normal, plane->normal[0],
			 plane->normal[1], plane->normal[2]);
	obj[0]->clr = (int)ft_scan_digit(&save);
	return (1);
}

int				set_cylinder(t_obj **obj, char *gnl)
{
	char		*save;
	t_cylinder	*cylinder;
	float		len_vect;
	float		axis[3];

	obj[0]->type = CYLINDER;
	if (!(obj[0]->shape = ft_memalloc(sizeof(t_cylinder))))
		return (0);
	cylinder = (t_cylinder *)obj[0]->shape;
	save = &gnl[11];
	cylinder->start[0] = ft_scan_digit(&save);
	cylinder->start[1] = ft_scan_digit(&save);
	cylinder->start[2] = ft_scan_digit(&save);
	axis[0] = ft_scan_digit(&save);
	axis[1] = ft_scan_digit(&save);
	axis[2] = ft_scan_digit(&save);
	len_vect = len_vector(axis);
	cylinder->axis[0] = axis[0] / len_vect;
	cylinder->axis[1] = axis[1] / len_vect;
	cylinder->axis[2] = axis[2] / len_vect;
	cylinder->radius = ft_scan_digit(&save);
	obj[0]->clr = (int)ft_scan_digit(&save);
	return (1);
}

int				set_cone(t_obj **obj, char *gnl)
{
	char	*save;
	t_cone	*cone;
	float	len_vect;
	float	axis[3];

	obj[0]->type = CONE;
	if (!(obj[0]->shape = ft_memalloc(sizeof(t_cone))))
		return (0);
	cone = (t_cone *)obj[0]->shape;
	save = &gnl[11];
	cone->vertex[0] = ft_scan_digit(&save);
	cone->vertex[1] = ft_scan_digit(&save);
	cone->vertex[2] = ft_scan_digit(&save);
	axis[0] = ft_scan_digit(&save);
	axis[1] = ft_scan_digit(&save);
	axis[2] = ft_scan_digit(&save);
	len_vect = len_vector(axis);
	cone->axis[0] = axis[0] / len_vect;
	cone->axis[1] = axis[1] / len_vect;
	cone->axis[2] = axis[2] / len_vect;
	cone->angle = ft_scan_digit(&save);
	cone->angle = tan((cone->angle / 2) * M_PI / 180);
	obj[0]->clr = ft_scan_digit(&save);
	return (1);
}

int			set_light(t_obj **obj, char *gnl)
{
	char	*save;
	t_light	*light;

	obj[0]->type = LIGHT;
	save = &gnl[11];
	if (!(obj[0]->shape = ft_memalloc(sizeof(t_light))))
		return (0);
	light = (t_light *)obj[0]->shape;
	light->type = ft_scan_digit(&save);
	light->intensive = ft_scan_digit(&save);
	if (!light->type)
		return (1);
	else if (light->type == 1)
	{
		light->center[0] = ft_scan_digit(&save);
		light->center[1] = ft_scan_digit(&save);
		light->center[2] = ft_scan_digit(&save);
	}
	else
	{
		light->vector[0] = ft_scan_digit(&save);
		light->vector[1] = ft_scan_digit(&save);
		light->vector[2] = ft_scan_digit(&save);
		multiplication_point(light->vector, -1.0 / len_vector(light->vector),
					light->vector);
	}
	return (1);
}

int				pars_scene(char *str, t_rt *rt)
{
	int		fd;
	char	*gnl;
	t_obj	*tmp;

	if (!(fd = open_file(str)))
		return (fd);
	if (!new_obj(&rt->obj))
		return (0);
	while (get_next_line(fd, &gnl))
	{
		if (gnl[0] == '#')
		{
			ft_strdel(&gnl);
			continue;
		}
		if (!ft_strncmp(gnl, "camera    ", 10))
			if (!set_camera(&rt->obj, gnl))
				return (0);
		if (!ft_strncmp(gnl, "sphere    ", 10))
		{
			if (!(tmp = new_obj(&rt->obj)))
				return (0);
			if (!(set_sphere(&tmp, gnl)))
				return (0);
		}
		if (!ft_strncmp(gnl, "plane     ", 10))
		{
			if (!(tmp = new_obj(&rt->obj)))
				return (0);
			if (!(set_plane(&tmp, gnl)))
				return (0);
		}
		if (!ft_strncmp(gnl, "cylinder   ", 10))
		{
			if (!(tmp = new_obj(&rt->obj)))
				return (0);
			if (!(set_cylinder(&tmp, gnl)))
				return (0);
		}
		if (!ft_strncmp(gnl, "cone      ", 10))
		{
			if (!(tmp = new_obj(&rt->obj)))
				return (0);
			if (!(set_cone(&tmp, gnl)))
				return (0);
		}
		if (!ft_strncmp(gnl, "light     ", 10))
		{
			if (!(tmp = new_obj(&rt->light)))
				return (0);
			if (!(set_light(&tmp, gnl)))
				return (0);
		}
		ft_putendl(gnl);
		ft_strdel(&gnl);
	}
	return (1);
}
