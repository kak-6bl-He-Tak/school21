/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtreutel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 16:22:45 by dtreutel          #+#    #+#             */
/*   Updated: 2018/12/05 12:46:50 by dtreutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int n;
	int res;

	n = 1;
	res = 0;
	while (*str == ' ' || (*str >= '\a' && *str <= '\r'))
		str++;
	if (*str == '-')
	{
		n *= -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (ft_isdigit(*str) != 0)
		res = res * 10 + *str++ - '0';
	return (res * n);
}
