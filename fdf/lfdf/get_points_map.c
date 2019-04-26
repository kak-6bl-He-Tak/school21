/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_points_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtreutel <dtreutel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/03 07:55:53 by dtreutel          #+#    #+#             */
/*   Updated: 2019/02/04 08:46:56 by dtreutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void			max_xy(char *str, t_x_and_y *maxy)
{
	maxy->y = ft_countwordc(str, '\n');
	while (*str)
		str++;
	if (*(str - 1) == '\n')
		*(str - 1) = '\0';
	while (*str != '\n')
		str--;
	str++;
	maxy->x = ft_countwordc(str++, ' ');
}

static t_point		**clear_points_map(t_x_and_y *maxy)
{
	t_point	**points;
	int		i;

	i = -1;
	if (!(points = ft_memalloc(sizeof(t_point *) * maxy->x)))
		return (0);
	while (++i < maxy->x)
	{
		if (!(points[i] = ft_memalloc(sizeof(t_point) * maxy->y)))
		{
			while (--i > -1)
				free(points[i]);
			free(points);
			return (0);
		}
	}
	return (points);
}

static void			set_zclr(t_point *point, char *str)
{
	char	c;
	int		n;

	n = 1;
	point->clr = CLR;
	point->z = 0;
	if (*str == '-' && str++)
		n = -1;
	while (*str >= '0' && *str <= '9')
		point->z = point->z * 10 + *str++ - '0';
	point->z = point->z * n;
	if (*str == ',')
	{
		point->clr = 0;
		str += 3;
		while (*str >= '0' && *str <= 'f')
		{
			c = *str++;
			if (c >= 'A' && c <= 'F')
				c -= 7;
			else if (c >= 'a' && c <= 'f')
				c -= 39;
			point->clr = point->clr * 16 + c - '0';
		}
	}
}

static void			set_points_map(t_point **points, char *str)
{
	int		x;
	int		y;

	y = 0;
	while (*str != '\0')
	{
		x = 0;
		while (*str != '\n' && *str != '\0')
		{
			while (*str == ' ')
				str++;
			points[x][y].x = x * STEP;
			points[x][y].y = y * STEP;
			set_zclr(&points[x][y], str);
			while (*str >= ',')
				str++;
			while (*str == ' ')
				str++;
			x++;
		}
		if (*str != '\0')
			str++;
		y++;
	}
}

t_point				**get_points_map(int fd, t_x_and_y *maxy)
{
	char	*str;
	t_point	**points;

	if (!read_file(fd, &str))
		return (0);
	if (!valid_file(str))
	{
		free(str);
		return (0);
	}
	max_xy(str, maxy);
	if (!(points = clear_points_map(maxy)))
	{
		free(str);
		return (0);
	}
	set_points_map(points, str);
	free(str);
	return (points);
}
