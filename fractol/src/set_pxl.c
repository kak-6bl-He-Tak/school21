/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_pxl1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtreutel <dtreutel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 14:37:49 by dtreutel          #+#    #+#             */
/*   Updated: 2019/03/18 07:14:31 by dtreutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	set_pxl(char *str, int x, int y, int clr)
{
	int i;

	i = x + y;
	str += i;
	str[0] = (char)clr % 256;
	clr /= 256;
	str[1] = (char)clr % 256;
	clr /= 256;
	str[2] = (char)clr % 256;
}
