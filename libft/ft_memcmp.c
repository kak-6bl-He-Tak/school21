/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtreutel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 12:51:01 by dtreutel          #+#    #+#             */
/*   Updated: 2018/12/10 16:52:12 by dtreutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	while (n != 0)
	{
		if (*(unsigned char*)s1 - *(unsigned char*)s2 != 0)
			return (*(unsigned char*)s1 - *(unsigned char*)s2);
		n--;
		s1++;
		s2++;
	}
	return (0);
}
