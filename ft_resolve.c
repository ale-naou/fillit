/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_testresolv.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgiraud <fgiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/17 18:08:28 by fgiraud           #+#    #+#             */
/*   Updated: 2015/12/20 16:48:09 by ale-naou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isplacable(t_struct *global)
{	
	int		tmp;

	tmp = 0;
	global->i = 0;
	global->x = 0;
	global->y = 0;
	while (global->y < global->nbrtetro && global->mapmax[global->i] != '\0')
	{
		if (global->mapmax[global->i] != '#')
		{
			global->x = 0;
			tmp = global->i;
			while (global->mapmax[tmp] != '#' &&
				global->mapmax[tmp] != '\n' &&
				global->mapmax[tmp] != '0' && global->x <= 2 &&
			   	tmp + global->tab[global->y][global->y] < global->mapopti)
			{
				tmp = tmp + global->tab[global->y][global->x];
				global->x++;
			}
			if (global->x == 3)
			{
				tmp = global->i;
				global->x = 0;
				while (global->x <= 3)
				{
					global->mapmax[tmp] = '#';
					tmp = tmp + global->tab[global->y][global->x];
					global->x++;
				}
				global->y++;
			}
		}
		global->i++;
	}
	return (0);
}

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
	int		i;
	int		x;

	i = 0;
	x = 0;
	while (global->power * global->power <= global->nbrtetro * 4)
		global->power++;
	global->mapopti = global->power * global->power + global->power;
	
	while (i < global->mapopti)
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
	return (global->mapopti);
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
	ft_putnbr(global->mapopti);
	ft_putchar('\n');
	ft_putnbr(mapopti);
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
	ft_isplacable(global);
	ft_putstr(mapmax);
	return (0);
}
