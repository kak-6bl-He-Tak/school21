/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtreutel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 13:03:38 by dtreutel          #+#    #+#             */
/*   Updated: 2019/02/02 19:49:22 by dtreutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	int	fd;

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (!fdf(fd))
			ft_putstr("error\n");
		return (1);
	}
	else
		ft_putstr("usage: fdf sourse_file\n");
	return (0);
}
