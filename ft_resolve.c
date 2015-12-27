/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_testresolv.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgiraud <fgiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/17 18:08:28 by fgiraud           #+#    #+#             */
/*   Updated: 2015/12/27 18:54:24 by ale-naou         ###   ########.fr       */
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

int		ft_remove(t_struct *global, int ctetro)
{
	int		tmp;

	tmp = global->i;
	while (global->mapmax[tmp] != '\0')
	{
		if (global->mapmax[tmp] == 'A' + ctetro)
			global->mapmax[tmp] = '.';
		tmp++;
	}
	return (0);
}

int		ft_place(t_struct *global, int ctetro)
{
	int		tmp;

	tmp = global->i;
	global->x = 0;
	while (global->x <= 3)
	{
		global->mapmax[tmp] = 'A' + ctetro;
		tmp = tmp + global->tab[global->y][global->x];
		global->x++;
	}
	return (0);
}

int		ft_isplacable(t_struct *global)
{	
	int		tmp;

	global->i = 0;
	while (global->mapmax[global->i] != '\0')
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
			}
			if (global->x == 3)
				return (0);
		}
		global->i++;
	}
	return (1);
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

void	ft_mapopti_filling(t_struct *global)
{
	global->x = 0;
	global->imap = 0;
	while (global->imap < global->mapopti)
	{
		if (global->x == global->power)
		{
			global->mapmax[global->imap] = '\n';
			global->imap++;
			global->x = 0;
		}
		else
		{
			global->mapmax[global->imap] = '.';
			global->imap++;
			global->x++;
		}
		global->mapmax[global->imap] = '\0';
	}
}

int		ft_recursive(t_struct *global, int ctetro)
{
	ft_affinfos(global);
	global->x = 0;
	global->y = 0;
	while (global->y < global->nbrtetro)
	{
		while (global->x < 3)
		{
			if (ft_isplacable(global) == 0)
			{
				ft_place(global, ctetro);
				if (ctetro + 1 == global->nbrtetro)
					return (ft_putstr(global->mapmax));
				else if (ft_recursive(global, ctetro + 1) == 1)
					return (1);
				else
					ft_remove(global, ctetro);
			}
			global->x++;
		}
		global->y++;
		global->x = 0;
	}
	return (0);
}

void	ft_resolve(t_struct *global)
{
	if (global->power == 0)
		while (global->power * global->power < global->nbrtetro * 4)
			global->power++;
		global->mapopti = global->power * global->power + global->power;
		ft_mapopti_filling(global);
		ft_adaptcoordo(global);
	while (global->power > 0)
	{		
		global->mapopti = global-> power * global->power + global->power;
		ft_mapopti_filling(global);
		ft_adaptcoordo(global);
		if (ft_recursive(global, 0) == 0)
			global->power++;
		else
			global->power = 0;
	}
}
