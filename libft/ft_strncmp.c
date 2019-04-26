/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp_dtreutel.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtreutel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 11:59:01 by dtreutel          #+#    #+#             */
/*   Updated: 2018/12/11 10:50:31 by dtreutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t i)
{
	int	j;

	j = 0;
	while ((*s1 != '\0' || *s2 != '\0') && (j == 0) && (i != 0))
	{
		j = (unsigned char)*s1++ - (unsigned char)*s2++;
		i -= 1;
	}
	return (j);
}
