/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_testresolv.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgiraud <fgiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/17 18:08:28 by fgiraud           #+#    #+#             */
/*   Updated: 2015/12/22 20:38:15 by ale-naou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_affinfos(t_struct *global)
{
	ft_putstr("Global->line : ");
	ft_putnbr(global->line);
	ft_putchar('\n');
	ft_putstr("Global->col : ");
	ft_putnbr(global->col);
	ft_putchar('\n');
	ft_putstr("Global->nbrtetro : ");
	ft_putnbr(global->nbrtetro);
	ft_putchar('\n');
	ft_putstr("Global->y : ");
	ft_putnbr(global->y);
	ft_putchar('\n');
	ft_putstr("Global->mapopti : ");
	ft_putnbr(global->mapopti);
	ft_putchar('\n');
	global->y = 0;
	while (global->y < global->nbrtetro)
	{
		ft_putstr("Coordonnees : ");
		global->x = 0;
		while (global->x < 3)
		{
			ft_putnbr(global->tab[global->y][global->x]);
			global->x++;
		}
		ft_putchar('\n');
		global->y++;
	}

	return (0);
}

int		ft_place(t_struct *global)
{
	int		tmp;

	tmp = global->i;
	global->x = 0;
	while (global->x <= 3)
	{
		global->mapmax[tmp] = global->c;
		tmp = tmp + global->tab[global->y][global->x];
		global->x++;
	}
	global->y++;
	global->c++;
	global->ctetro++;
	return (0);
}

int		ft_isplacable(t_struct *global)
{	
	int		tmp;

	global->i = 0;
	global->y = 0;
	while (global->y < global->nbrtetro && global->mapmax[global->i] != '\0')
	{
		if (global->mapmax[global->i] == '.')
		{
			global->x = 0;
			tmp = global->i;
			while (global->mapmax[tmp] == '.' && global->x <= 2 &&
					tmp + global->tab[global->y][global->x] < global->mapopti)
			{
				tmp = tmp + global->tab[global->y][global->x];
				global->x++;
				ft_putnbr(tmp);
				ft_putchar('\n');
			}
			if (global->x == 3)
				ft_place(global);
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
	}
}

int		ft_mapopti(t_struct *global)
{
	int		i;

	i = 0;
	global->x = 0;
	while (global->power * global->power <= global->nbrtetro * 4)
		global->power++;
	global->mapopti = global->power * global->power + global->power;
	
	while (i < global->mapopti)
	{
		if (global->x == global->power)
		{
			global->mapmax[i] = '\n';
			i++;
			global->x = 0;
		}
		else
		{
			global->mapmax[i] = '.';
			i++;
			global->x++;
		}
	}
	global->mapmax[i] = '\0';
	return (global->mapopti);
}

int		ft_resolve(char *buf, t_struct *global)
{
	global->mapmax = ft_strnew(16 * 17);
	ft_mapopti(global);
	ft_adaptcoordo(global);
	ft_affinfos(global);
	ft_isplacable(global);
	ft_putstr(global->mapmax);
	return (0);
}
