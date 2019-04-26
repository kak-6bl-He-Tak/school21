/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrim.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtreutel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 15:48:12 by dtreutel          #+#    #+#             */
/*   Updated: 2018/12/04 02:04:13 by dtreutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strtrim(char const *s)
{
	char	*str;
	size_t	i;

	str = 0;
	if (!s)
		return (0);
	while (*s == '\n' || *s == ' ' || *s == '\t')
		s++;
	if (*s)
	{
		i = ft_strlen((char *)s);
		while (s[i] == '\n' || s[i] == ' ' || s[i] == '\t'
				|| s[i] == '\0')
			i--;
		i += 1;
		if (!(str = ft_strnew(i)))
			return (0);
		ft_strncat(str, (char *)s, i);
		return (str);
	}
	str = ft_memalloc(1);
	return (str);
}
