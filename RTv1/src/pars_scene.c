/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtreutel <dtreutel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 13:49:46 by dtreutel          #+#    #+#             */
/*   Updated: 2019/09/13 20:33:41 by dtreutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static int			open_file(char *str)
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

int					set_camera(t_obj **obj, char *gnl)
{
	char	*save;
	float	*camera;

	save = &gnl[11];
	obj[0]->type = CAMERA;
	if (!(obj[0]->shape = ft_memalloc(sizeof(float) * 6)))
		return (0);
	camera = (float *)obj[0]->shape;
	camera[0] = ft_scan_digit(&save);
	camera[1] = ft_scan_digit(&save);
	camera[2] = ft_scan_digit(&save);
	camera[3] = ft_scan_digit(&save);
	camera[4] = ft_scan_digit(&save);
	camera[5] = ft_scan_digit(&save);
	return (1);
}

static int			set_shapes(char *gnl, t_rt *rt, t_obj *tmp)
{
	if (!ft_strncmp(gnl, "camera    :", 11))
		if (!set_camera(&rt->obj, gnl))
			return (0);
	if (!ft_strncmp(gnl, "sphere    :", 11) ||
		!ft_strncmp(gnl, "plane     :", 11) ||
			!ft_strncmp(gnl, "cylinder  :", 11) ||
				!ft_strncmp(gnl, "cone      :", 11))
		if (!(tmp = new_obj(&rt->obj)))
			return (0);
	if (!ft_strncmp(gnl, "sphere    :", 11))
		if (!(set_sphere(&tmp, gnl)))
			return (0);
	if (!ft_strncmp(gnl, "plane     :", 11))
		if (!(set_plane(&tmp, gnl)))
			return (0);
	if (!ft_strncmp(gnl, "cylinder  :", 11))
		if (!(set_cylinder(&tmp, gnl)))
			return (0);
	if (!ft_strncmp(gnl, "cone      :", 11))
		if (!(set_cone(&tmp, gnl)))
			return (0);
	return (1);
}

static int			ft_koroche(char *gnl, t_rt *rt, t_obj *tmp)
{
	if (ft_strncmp(gnl, "camera    :", 11) &&
		ft_strncmp(gnl, "sphere    :", 11) &&
			ft_strncmp(gnl, "plane     :", 11) &&
				ft_strncmp(gnl, "cylinder  :", 11) &&
					ft_strncmp(gnl, "cone      :", 11) &&
						ft_strncmp(gnl, "light     :", 11))
		return (0);
	if (!ft_strncmp(gnl, "light     :", 11))
	{
		if (!(tmp = new_obj(&rt->light)))
			return (0);
		if (!(set_light(&tmp, gnl)))
			return (0);
	}
	return (1);
}

int					pars_scene(char *str, t_rt *rt)
{
	int		fd;
	char	*gnl;
	t_obj	*tmp;

	tmp = 0;
	if (!(fd = open_file(str)))
		return (fd);
	if (!new_obj(&rt->obj))
		return (0);
	while (get_next_line(fd, &gnl))
	{
		if (gnl[0] == '#')
			ft_strdel(&gnl);
		else if (!ft_koroche(gnl, rt, tmp))
		{
			ft_strdel(&gnl);
			return (0);
		}
		else if (!set_shapes(gnl, rt, tmp))
		{
			ft_strdel(&gnl);
			return (0);
		}
	}
	return (1);
}
