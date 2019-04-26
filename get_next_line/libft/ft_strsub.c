/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtreutel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 14:38:52 by dtreutel          #+#    #+#             */
/*   Updated: 2018/12/03 16:50:52 by dtreutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*str;

	if (!s)
		return (0);
	str = ft_memalloc(len + 1);
	if (str)
	{
		ft_bzero(str, len + 1);
		str = ft_strncat(str, (char *)s + start, len);
		return (str);
	}
	return (0);
}
