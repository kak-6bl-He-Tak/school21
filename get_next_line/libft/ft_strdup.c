/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtreutel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 20:21:10 by dtreutel          #+#    #+#             */
/*   Updated: 2018/12/10 16:54:09 by dtreutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(const char *src)
{
	int		i;
	int		j;
	char	*cp;

	i = 0;
	j = 0;
	while (src[i] != '\0')
		i++;
	if (!(cp = malloc(sizeof(char) * i + 1)))
		return (0);
	while (src[j] != '\0')
	{
		cp[j] = src[j];
		j++;
	}
	cp[j] = '\0';
	return (cp);
}
