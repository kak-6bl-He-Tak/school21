/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_points_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtreutel <dtreutel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 11:51:52 by dtreutel          #+#    #+#             */
/*   Updated: 2019/02/11 11:52:25 by dtreutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	del_points_map(t_all_sct *all)
{
	int i;

	i = -1;
	while (++i < all->maxy->x)
		free(all->points[i]);
	free(all->points);
	all->points = 0;
}
