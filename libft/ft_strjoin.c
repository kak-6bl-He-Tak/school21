/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtreutel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 15:31:43 by dtreutel          #+#    #+#             */
/*   Updated: 2018/12/03 13:54:24 by dtreutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	unsigned int	i;
	char			*str;

	if (!s1 || !s2)
		return (0);
	i = ft_strlen((char *)s1) + ft_strlen((char *)s2) + 1;
	str = ft_memalloc((size_t)i);
	if (str)
	{
		ft_strcpy(str, (char *)s1);
		ft_strcat(str, (char *)s2);
	}
	return (str);
}
