/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtreutel <dtreutel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/03 08:09:29 by dtreutel          #+#    #+#             */
/*   Updated: 2019/02/03 08:10:22 by dtreutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	read_file(int fd, char **str)
{
	char *save;
	char *buff[11];

	if (read(fd, buff, 0) < 0)
		return (0);
	ft_bzero(buff, 11);
	save = ft_strnew(1);
	while (read(fd, buff, 10))
	{
		if (!(*str = ft_strjoin(save, (char const *)buff)))
		{
			free(save);
			return (0);
		}
		free(save);
		save = *str;
		ft_bzero(buff, 11);
	}
	return (1);
}
