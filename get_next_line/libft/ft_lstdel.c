/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtreutel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 11:50:27 by dtreutel          #+#    #+#             */
/*   Updated: 2018/12/10 17:17:19 by dtreutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *save;

	if (alst && *alst && del)
	{
		while (*alst)
		{
			save = (*alst)->next;
			del((*alst)->content, (*alst)->content_size);
			free(*alst);
			(*alst) = save;
		}
		alst = 0;
	}
}
