/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtreutel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 10:47:50 by dtreutel          #+#    #+#             */
/*   Updated: 2018/12/10 16:41:06 by dtreutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t i;

	i = -1;
	if (dest == src)
		return (dest);
	while (++i < n)
		if (src < dest)
			*(unsigned char*)(dest + (n - 1 - i)) =
				*(unsigned char*)(src + (n - 1 - i));
		else
			*(unsigned char*)(dest + i) = *(unsigned char*)(src + i);
	return (dest);
}
