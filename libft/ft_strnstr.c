/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtreutel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 10:33:16 by dtreutel          #+#    #+#             */
/*   Updated: 2018/12/10 16:01:24 by dtreutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strnstr(const char *s1, const char *s2, size_t i)
{
	if (*s1)
		while (i != 0 && ft_strlen(s2) <= i)
		{
			if ((ft_strncmp(s1, s2, ft_strlen(s2)) == 0))
				return (ft_strstr(s1, s2));
			s1++;
			i--;
			if (!*s1)
				return (0);
		}
	return (0);
}
