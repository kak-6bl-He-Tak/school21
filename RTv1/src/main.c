/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtreutel <dtreutel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 10:20:17 by dtreutel          #+#    #+#             */
/*   Updated: 2019/08/25 17:06:18 by udraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	start_mlx(t_rt *rt)
{
	int		bpp;
	int		size_line;
	int		end;

	if (!(rt->mlx_ptr = mlx_init())
		|| !(rt->win_ptr = mlx_new_window(rt->mlx_ptr, W, H, "RTv1")) ||
		!(rt->img_ptr = mlx_new_image(rt->mlx_ptr, W, H)) ||
		!(rt->img_data = (int *)mlx_get_data_addr(rt->img_ptr, &bpp, &size_line, &end)))
	{
		perror("Ошибка инициализации MLX");
		ft_exit(rt);
	}
}

static int				press_key(int key, t_rt *rt)
{
	if (key == 53)
		ft_exit(rt);
	return (0);
}


int main(int argc, char **argv)
{
	t_rt	rt;

	ft_bzero((void *)&rt, sizeof(rt));
	if (argc == 2)
	{
		if (!(pars_scene(argv[1], &rt)))
			ft_exit(&rt);
	}
	else
	{
		ft_putendl("Use: ./RTv1 [scene file]");
		ft_exit(&rt);
	}
	start_mlx(&rt);

	trace_ray(&rt);


	mlx_hook(rt.win_ptr, 2, 0, press_key, &rt);
	mlx_hook(rt.win_ptr, 17, 0, ft_exit, (void *)&rt);
	mlx_loop(rt.mlx_ptr);
	return(0);
}
