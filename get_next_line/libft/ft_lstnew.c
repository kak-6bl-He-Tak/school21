/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtreutel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 16:18:43 by dtreutel          #+#    #+#             */
/*   Updated: 2018/12/10 17:20:43 by dtreutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new;

	if (!(new = ft_memalloc(sizeof(t_list))))
		return (0);
	if (!content || !content_size)
	{
		new->content = 0;
		new->content_size = 0;
		new->next = 0;
		return (new);
	}
	if (!(new->content = ft_memalloc(content_size)))
	{
		free(new);
		return (0);
	}
	ft_memcpy((*new).content, (void *)content, content_size);
	new->content_size = content_size;
	new->next = 0;
	return (new);
}
