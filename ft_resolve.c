/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_testresolv.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgiraud <fgiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/17 18:08:28 by fgiraud           #+#    #+#             */
/*   Updated: 2015/12/29 18:28:14 by ale-naou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_affinfos(t_struct *global)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
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
	while (y < global->nbrtetro)
	{
		ft_putstr("Coordonnees : ");
		x = 0;
		while (x < 3)
		{
			ft_putnbr(global->tab[y][x]);
			x++;
		}
		ft_putchar('\n');
		y++;
	}
	return (0);
}

int		ft_remove(t_struct *global, int ctetro)
{
	int		tmp;

	tmp = 0;
	while (global->mapmax[tmp] != '\0')
	{
		if (global->mapmax[tmp] == 'A' + ctetro)
			global->mapmax[tmp] = '.';
		tmp++;
	}
	return (0);
}

int		ft_place(t_struct *global, int ctetro, int i)
{
	int		tmp;
	int		x;

	x = 0;
	tmp = i;
	while (x <= 3)
	{
		global->mapmax[tmp] = 'A' + ctetro;
		tmp = tmp + global->tab[ctetro][x];
		x++;
	}
	return (0);
}

int		ft_isplacable(t_struct *global, int ctetro, int i)
{	
	int		x;
	int		tmp;

	x = 0;
	if (global->mapmax[i] == '.')
	{
		x = 0;
		tmp = global->i;
		while (global->mapmax[tmp] == '.' && x <= 2 &&
				tmp + global->tab[ctetro][x] < global->mapopti)
		{
			tmp = tmp + global->tab[ctetro][x];
			x++;
		}
		if (x == 3)
			return (0);
	}
	return (1);
}

void	ft_adaptcoordo(t_struct *global)
{
	int		x;
	int		y;

	y = 0;
	while (y < global->nbrtetro)
	{
		x = 0;
		while (x <= 2)
		{
			if (global->tab[y][x] == 1)
				x++;
			else
			{
				global->tab[y][x] = 
				global->tab[y][x] - (global->col - global->power);
				x++;
			}
		}
		y++;
	}
	global->col = global->power;
}

void	ft_mapopti_filling(t_struct *global)
{
	int		x;

	x = 0;
	global->imap = 0;
	while (global->imap < global->mapopti)
	{
		if (x == global->power)
		{
			global->mapmax[global->imap] = '\n';
			global->imap++;
			x = 0;
		}
		else
		{
			global->mapmax[global->imap] = '.';
			global->imap++;
			x++;
		}
		global->mapmax[global->imap] = '\0';
	}
}

int		ft_recursive(t_struct *global, int ctetro)
{
	int		i;

	i = -1;
	while (global->mapmax[++i] != '\0')
	{	
		if (ft_isplacable(global, ctetro, i) == 0)
		{
			ft_place(global, ctetro, i);				
			if (ctetro + 1 == global->nbrtetro)
				return (ft_putstr(global->mapmax));
			else if (ft_recursive(global, ctetro + 1) == 0)
				return (0);
			else
				ft_remove(global, ctetro);
		}
		i = -1;
	}
	return (1);
}

void	ft_resolve(t_struct *global)
{
	global->i = 0;
	global->col = 4;
	if (global->power == 0)
		while (global->power * global->power < global->nbrtetro * 4)
			global->power++;
	global->mapopti = global->power * global->power + global->power;
	ft_mapopti_filling(global);
	ft_adaptcoordo(global);
	while (global->power > 0)
	{	
		global->i = 0;
		global->mapopti = global-> power * global->power + global->power;
		ft_mapopti_filling(global);
		ft_adaptcoordo(global);
		ft_affinfos(global);
		if (ft_recursive(global, 0) == 1)
			global->power++;
		else
			global->power = 0;
	}
	//ft_putstr(global->mapmax);
}
