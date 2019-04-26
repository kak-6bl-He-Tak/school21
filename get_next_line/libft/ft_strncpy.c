/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy_dtreutel.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtreutel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 13:00:41 by dtreutel          #+#    #+#             */
/*   Updated: 2018/12/11 10:42:33 by dtreutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strncpy(char *dsr, const char *src, size_t i)
{
	unsigned int j;

	j = 0;
	while (src[j] != '\0' && i != 0)
	{
		dsr[j] = src[j];
		j++;
		i--;
	}
	while (i-- != 0)
	{
		dsr[j] = '\0';
		j++;
	}
	return (dsr);
}
