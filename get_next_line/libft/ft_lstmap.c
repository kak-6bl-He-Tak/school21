/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtreutel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 15:51:07 by dtreutel          #+#    #+#             */
/*   Updated: 2018/12/11 10:59:38 by dtreutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static void	fclean(t_list *lst)
{
	t_list *save;

	save = 0;
	while (lst)
	{
		save = lst->next;
		free(lst->content);
		free(lst);
		lst = save;
	}
}

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*save;

	save = 0;
	if (f)
		while (lst)
		{
			if (!(new = f(lst)))
				return (0);
			save = new;
			while (lst->next)
			{
				lst = lst->next;
				if (!(new->next = f(lst)))
				{
					fclean(save);
					return (0);
				}
				new = new->next;
			}
			lst = lst->next;
		}
	return (save);
}
