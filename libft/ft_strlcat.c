/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtreutel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 14:49:29 by dtreutel          #+#    #+#             */
/*   Updated: 2018/12/10 15:59:16 by dtreutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t i;

	i = ft_strlen(dst);
	if (size == 0)
		return (ft_strlen(src));
	else if (size < i)
		return (size + ft_strlen(src));
	if (i < size - 1)
		ft_strncat(dst, src, size - i - 1);
	return (i + ft_strlen(src));
}
