/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtreutel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 14:40:11 by dtreutel          #+#    #+#             */
/*   Updated: 2018/12/10 17:11:09 by dtreutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static size_t	ft_strlenc(const char *s, int c)
{
	size_t i;

	if (!s)
		return (0);
	i = 0;
	while (*s && !(*s++ == c))
		i++;
	return (i);
}

static int		ft_strspr(const char *str, char c)
{
	int	i;

	i = 0;
	while (*str)
		if (*str != c && ++i)
			while (*str != c && *str)
				str++;
		else
			str++;
	return (i);
}

static void		fclean(char **ar, int i)
{
	while (i >= 0)
	{
		free(ar[i]);
		i--;
	}
	ar = 0;
}

char			**ft_strsplit(char const *s, char c)
{
	int		i;
	char	**ar;

	if (!s)
		return (0);
	i = 0;
	if (!(ar = (char**)ft_memalloc(sizeof(char*) * ft_strspr(s, c) + 1)))
		return (0);
	while (*s)
		if (*s != c)
		{
			if (!(*(ar + i++) = ft_strsub(s, 0, ft_strlenc(s, c))))
			{
				fclean(ar, --i);
				return (0);
			}
			s += ft_strlenc(s, c);
		}
		else
			s++;
	ar[i] = 0;
	return (ar);
}
