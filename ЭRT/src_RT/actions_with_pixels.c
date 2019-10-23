/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_with_pixels.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtreutel <dtreutel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 18:39:20 by dtreutel          #+#    #+#             */
/*   Updated: 2019/10/23 21:30:12 by dtreutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void			set_pixel_sdl(SDL_Surface *surface, int x, int y, Uint32 pixel)
{
	int			*target_pixel;

	if (x >= 0 && x < W && y >= 0 && y < W)
	{
		target_pixel = (int *)surface->pixels;
		target_pixel[surface->w * y + x] = pixel;
	}
	// *target_pixel = pixel;
}

void			clear_surface(SDL_Surface *surface, int x, int y)
{
	ft_bzero(surface->pixels, sizeof(int) * (x * y));
}
