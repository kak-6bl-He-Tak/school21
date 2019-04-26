/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtreutel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 13:03:38 by dtreutel          #+#    #+#             */
/*   Updated: 2019/03/21 15:27:49 by dtreutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	usage(void)
{
	ft_putstr("usage : fractol [fractals]\n");
	ft_putstr("fractals :\n");
	ft_putstr("--> Julia\n");
	ft_putstr("--> Mandelbrot\n");
	ft_putstr("--> Burningship\n");
	ft_putstr("--> Burningass\n");
}

int		main(int argc, char **argv)
{
	if (argc == 2)
	{
		if (!ft_strcmp(argv[1], "Julia"))
			fractol(1);
		else if (!ft_strcmp(argv[1], "Mandelbrot"))
			fractol(2);
		else if (!ft_strcmp(argv[1], "Burningship"))
			fractol(3);
		else if (!ft_strcmp(argv[1], "Burningass"))
			fractol(4);
		else
			usage();
	}
	else
		usage();
	return (0);
}
