/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtreutel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 10:05:52 by dtreutel          #+#    #+#             */
/*   Updated: 2018/12/10 16:03:55 by dtreutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	int		i;
	int		x;
	char	*null;

	null = 0;
	if (!(i = ft_strlen(s2)))
		return ((char *)s1);
	while (*s1)
	{
		x = ft_strncmp(s1, s2, i);
		if (x == 0)
			return ((char *)s1);
		s1++;
	}
	return (null);
}
