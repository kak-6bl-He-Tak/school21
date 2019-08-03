/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtreutel <dtreutel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 13:49:46 by dtreutel          #+#    #+#             */
/*   Updated: 2019/08/03 17:11:38 by dtreutel         ###   ########.fr       */
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

void			set_camera(t_obj **obj, char *gnl)
{
	char	*save;

	save = &gnl[8];
	obj[0]->xyz[0] = ft_scan_digit(&save);
	obj[0]->xyz[1] = ft_scan_digit(&save);
	obj[0]->xyz[2] = ft_scan_digit(&save);
}

void			set_sphere(t_obj **sph, char *gnl)
{
	char	*save;

	save = &gnl[8];
	sph[0]->type = 1;
	sph[0]->xyz[0] = ft_scan_digit(&save);
	sph[0]->xyz[1] = ft_scan_digit(&save);
	sph[0]->xyz[2] = ft_scan_digit(&save);
	sph[0]->r = ft_scan_digit(&save);
	sph[0]->clr = (int)ft_scan_digit(&save);
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

int			pars_scene(char *str, t_rt *rt)
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
			set_camera(&rt->obj, gnl);
		if (!ft_strncmp(gnl, "sphere", 6))
		{
			if (!(tmp = new_obj(&rt->obj)))
				return (0);
			set_sphere(&tmp, gnl);
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
