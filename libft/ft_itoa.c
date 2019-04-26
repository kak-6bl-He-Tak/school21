/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtreutel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 14:25:46 by dtreutel          #+#    #+#             */
/*   Updated: 2018/12/03 22:20:16 by dtreutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	int				i;
	char			*itoa;
	int				save;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	save = n;
	i = n < 0 ? 2 : 1;
	while (n / 10 != 0)
	{
		n /= 10;
		i++;
	}
	if (!(itoa = ft_strnew(i)))
		return (0);
	i -= 1;
	save = save >= 0 ? save : save * -1;
	while (i >= 0)
	{
		itoa[i--] = '0' + save % 10;
		save /= 10;
	}
	if (n < 0)
		itoa[0] = '-';
	return (itoa);
}
