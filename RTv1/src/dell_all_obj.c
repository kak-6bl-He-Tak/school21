/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dell_all_obj.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtreutel <dtreutel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 14:59:33 by dtreutel          #+#    #+#             */
/*   Updated: 2019/07/31 11:46:51 by dtreutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	dell_all_obj(t_obj **obj)
{
	t_obj	*save;

	if (obj && *obj)
	{
		while ((*obj)->next)
		{
			save = (*obj)->next;
			ft_memdel(((void **)&obj[0]));
			obj[0] = save;
		}
		ft_memdel(((void **)&obj[0]));
	}
}
