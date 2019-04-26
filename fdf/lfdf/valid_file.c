/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtreutel <dtreutel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 07:48:18 by dtreutel          #+#    #+#             */
/*   Updated: 2019/02/11 11:27:19 by dtreutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	dell(char **split)
{
	ft_arraydel((void **)split);
	ft_memdel((void *)split);
	return (0);
}

static int	chekpoints(char *str)
{
	while (*str)
	{
		while (*str == ' ')
			str++;
		if ((*str < '0' || *str > '9') && *str != '-' && *str)
			return (0);
		while ((*str >= '0' && *str <= '9') || *str == '-')
			str++;
		if (*str != ',' && *str != ' ' && *str != '\0')
			return (0);
		else if (*str == ',')
		{
			str++;
			if (*str++ != '0' || *str++ != 'x')
				return (0);
			while (*str != ' ' && *str != '\0')
			{
				if ((*str < '0' || *str > '9') && (*str < 'a' || *str > 'f')
							&& (*str < 'A' || *str > 'F'))
					return (0);
				str++;
			}
		}
	}
	return (1);
}

static int	valid_square(char *str)
{
	char	**split;
	int		i;

	i = 0;
	if (!(split = ft_strsplit(str, '\n')))
		return (0);
	if (split[i] == 0)
		return (0);
	while (split[i + 1] != 0)
	{
		if (ft_countwordc(split[i], ' ') != ft_countwordc(split[i + 1], ' '))
			return (dell(split));
		i++;
	}
	i = -1;
	while (split[++i] != 0)
		if (!chekpoints(split[i]))
			return (dell(split));
	dell(split);
	return (1);
}

int			valid_file(char *str)
{
	int	i;

	i = -1;
	while (str[++i] != '\0')
	{
		if (str[i] != ' ' && str[i] != '\n' && str[i] != ',' &&
			(str[i] < '0' || str[i] > '9') && (str[i] < 'A' || str[i] > 'F')
				&& (str[i] < 'a' || str[i] > 'f')
				&& str[i] != 'x' && str[i] != '-')
			return (0);
	}
	if (!valid_square(str))
		return (0);
	return (1);
}
