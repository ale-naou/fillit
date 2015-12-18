/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_testresolv.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgiraud <fgiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/17 18:08:28 by fgiraud           #+#    #+#             */
/*   Updated: 2015/12/18 18:51:27 by ale-naou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_adaptcoordo(t_struct *global)
{
	global->y = 0;
	while (global->y < global->nbrtetro)
	{
		global->x = 0;
		while (global->x <= 2)
		{
			if (global->tab[global->y][global->x] == 1)
				global->x++;
			else
			{
				global->tab[global->y][global->x] =
				global->tab[global->y][global->x] - (5 - (global->power + 1));
				global->x++;
			}
		}
		global->y++;
		ft_putstr("Sortie adaptcoordo\n");
	}
}

int		ft_mapopti(t_struct *global, char *mapmax)
{
	int		mapopti;
	int		i;
	int		x;

	i = 0;
	x = 0;
	while (global->power * global->power <= global->nbrtetro * 4)
		global->power++;
	mapopti = global->power * global->power + global->power;
	while (i < mapopti)
	{
		if (x == global->power)
		{
			mapmax[i] = '\n';
			i++;
			x = 0;
		}
		else
		{
			mapmax[i] = '.';
			i++;
			x++;
		}
	}
	mapmax[i] = '\0';
	ft_putstr("Sortie mapopti\n");
	return (mapopti);
}

int		ft_resolve(char *buf, t_struct *global)
{
	char	*mapmax;
	int		mapopti;

	if ((mapmax = (char *)malloc(sizeof(*mapmax) * 16 * 17)) == NULL)
		return (1);
	mapopti = ft_mapopti(global, mapmax);
	ft_adaptcoordo(global);
	ft_putnbr(global->line);
	ft_putchar('\n');
	ft_putnbr(global->col);
	ft_putchar('\n');
	ft_putnbr(global->nbrtetro);
	ft_putchar('\n');
	ft_putnbr(global->y);
	ft_putchar('\n');
	global->y = 0;
	while (global->y < global->nbrtetro)
	{
		global->x = 0;
		while (global->x < 3)
		{
			ft_putnbr(global->tab[global->y][global->x]);
			global->x++;
		}
		ft_putchar('\n');
		global->y++;
	}
	ft_putstr(mapmax);
	return (0);
}
