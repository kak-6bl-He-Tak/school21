/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtreutel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 13:37:40 by dtreutel          #+#    #+#             */
/*   Updated: 2018/12/10 16:53:18 by dtreutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strcmp(const char *s1, const char *s2)
{
	int i;

	i = 0;
	while ((*s1 != '\0' || *s2 != '\0') && i == 0)
		i = (unsigned char)*s1++ - (unsigned char)*s2++;
	return (i);
}
