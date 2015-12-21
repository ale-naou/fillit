/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgiraud <fgiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 11:15:48 by fgiraud           #+#    #+#             */
/*   Updated: 2015/12/21 21:01:41 by ale-naou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define BUFF_SIZE ((21 * 27) + 1)

void	ft_init(t_struct *global)
{
	global->i = 0;
	global->nbrhash = 0;
	global->counti = 0;
	global->y = 0;
	global->col = 0;
	global->power = 0;
	global->mapopti = 0;
	global->c = 'A';
	global->ctetro = 0;
}

int		main(int ac, char *av[])
{
	int			fd;
	int			ret;
	char		buf[BUFF_SIZE];
	t_struct	*global;

	if (ac != 2)
		return (ft_error(1));
	else
	{
		fd = open(av[1], O_RDONLY);
		if (fd == -1)
			return (ft_error(1));
		if ((ret = read(fd, buf, BUFF_SIZE)) > 545)
			return (ft_error(1));
		buf[ret] = '\0';
		if ((global = (t_struct *)malloc(sizeof(t_struct))) == NULL)
			return (ft_error(1));
		if (ft_tetrosvalid(buf, global) != 0)
			return (ft_error(1));
		if (ft_resolve(buf, global) != 0)
			return (ft_error(1));
		ft_putstr("\nici le futur resultat\n");
		if (close(fd) == -1)
			return (ft_error(1));
	}
	return (0);
}
