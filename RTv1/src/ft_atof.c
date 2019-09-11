/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtreutel <dtreutel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 09:44:11 by dtreutel          #+#    #+#             */
/*   Updated: 2019/09/11 20:48:00 by dtreutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

float	ft_atof(const char *str)
{
	float	res;
	int		hvost;
	float	float_hvost;

	float_hvost = 0;
	res = (float)ft_atoi(str);
	while (*str == '\t' || *str == ' ' || *str == '-')
		str++;
	while (ft_isdigit(*str))
		str++;
	if (*str++ == '.')
	{
		hvost = ft_atoi(str);
		while (hvost)
		{
			float_hvost = float_hvost / 10 + hvost % 10;
			hvost /= 10;
		}
	}
	if (res < 0)
		return (res - float_hvost / 10);
	return (res + float_hvost / 10);
}
