/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtreutel <dtreutel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 13:49:46 by dtreutel          #+#    #+#             */
/*   Updated: 2019/08/27 20:49:47 by dtreutel         ###   ########.fr       */
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

	save = &gnl[8];
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
	if (!(obj[0]->shape = (t_sphere *)ft_memalloc(sizeof(t_sphere))))
		return (0);
	sphere = obj[0]->shape;
	save = &gnl[8];
	sphere->sphere_center[0] = ft_scan_digit(&save);
	sphere->sphere_center[1] = ft_scan_digit(&save);
	sphere->sphere_center[2] = ft_scan_digit(&save);
	sphere->sphere_radius = ft_scan_digit(&save);
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
	plane = obj[0]->shape;
	plane->plane_dot[0] = ft_scan_digit(&save);
	plane->plane_dot[1] = ft_scan_digit(&save);
	plane->plane_dot[2] = ft_scan_digit(&save);
	normal[0] = ft_scan_digit(&save);
	normal[1] = ft_scan_digit(&save);
	normal[2] = ft_scan_digit(&save);
	len_normal = len_vector(normal);
	plane->plane_normal[0] = normal[0] / len_normal;
	plane->plane_normal[1] = normal[1] / len_normal;
	plane->plane_normal[2] = normal[2] / len_normal;
	obj[0]->clr = (int)ft_scan_digit(&save);
	return (1);
}

int				set_cylinder(t_obj **obj, char *gnl)
{
	char		*save;
	t_cylinder	*cylinder;

	obj[0]->type = CYLINDER;
	if (!(obj[0]->shape = ft_memalloc(sizeof(t_cylinder))))
		return (0);

	return (1);
}


void			set_light(t_obj **light, char *gnl)
{
	char	*save;

	save = &gnl[7];
	light[0]->type = ft_scan_digit(&save);
	light[0]->r = ft_scan_digit(&save);
	if (light[0]->type)
	{
		light[0]->xyz[0] = ft_scan_digit(&save);
		light[0]->xyz[1] = ft_scan_digit(&save);
		light[0]->xyz[2] = ft_scan_digit(&save);
	}
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
		if (!ft_strncmp(gnl, "camera", 6))
			if (!set_camera(&rt->obj, gnl))
				return (0);
		if (!ft_strncmp(gnl, "sphere", 6))
		{
			if (!(tmp = new_obj(&rt->obj)))
				return (0);
			if (!(set_sphere(&tmp, gnl)))
				return (0);
		}
		if (!ft_strncmp(gnl, "plane", 5))
		{
			if (!(tmp = new_obj(&rt->obj)))
				return (0);
			if (!(set_plane(&tmp, gnl)))
				return (0);
		}
		if (!ft_strncmp(gnl, "cylinder", 8))
		{
			if (!(tmp = new_obj(&rt->obj)))
				return (0);
			if (!(set_cylinder(&tmp, gnl)))
				return (0);
		}






		if (!ft_strncmp(gnl, "light", 5))
		{
			if (!(tmp = new_obj(&rt->light)))
				return (0);
			set_light(&tmp, gnl);
		}
		ft_putendl(gnl);
		ft_strdel(&gnl);
	}
	return (1);
}
