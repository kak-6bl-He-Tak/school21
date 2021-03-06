/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtreutel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 16:07:28 by dtreutel          #+#    #+#             */
/*   Updated: 2018/12/03 22:58:13 by dtreutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isalnum(int c)
{
	int i;

	i = 0;
	if (ft_isalpha(c) != 0 || ft_isdigit(c) != 0)
		i = 1;
	return (i);
}
