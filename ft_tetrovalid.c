/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tetrovalid.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-naou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/16 17:27:51 by ale-naou          #+#    #+#             */
/*   Updated: 2015/12/18 18:51:25 by ale-naou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_testlength(t_struct *global)
{
	int x;
	int x1;

	x = 0;
	x1 = 0;
	if (global->counti == 20 && global->nbrhash != 4)
		return (1);
	else if (global->counti == 20)
	{
		global->counti = 0;
		global->nbrhash = 0;
		global->col = 0;
		if (global->y < global->nbrtetro)
		{
			while (x1 < 3)
			{
				global->tab[global->y][x1] =
					global->tabhash[x + 1] - global->tabhash[x];
				x++;
				x1++;
			}
			global->y++;
		}
	}
	return (0);
}

static int		ft_testcoordo(char *buf, t_struct *global)
{
	if (global->i != global->tabhash[0] && global->i != global->tabhash[1] &&
			global->i != global->tabhash[2] && global->i != global->tabhash[3])
	{
		global->tabhash[global->col] = global->i;
		if ((buf[global->tabhash[global->col] - 5] != '#' &&
					buf[global->tabhash[global->col] - 1] != '#' &&
					buf[global->tabhash[global->col] + 5] != '#' &&
					buf[global->tabhash[global->col] + 1] != '#') ||
				(global->col == 2 && buf[global->tabhash[2] - 1] != '#' &&
				 buf[global->tabhash[2] - 5] != '#'))
			return (1);
		global->col++;
	}
	return (0);
}

int				ft_formsvalid(char *buf, t_struct *global)
{
	ft_init(global);
	while (buf[global->i] != '\0')
	{
		global->counti++;
		if (buf[global->i] == '#')
		{
			global->nbrhash++;
			if (ft_testcoordo(buf, global) != 0)
				return (1);
			if (buf[global->i + 1] == '\0' && buf[global->i - 1] == '\n')
				return (1);
		}
		if (global->counti == 20)
		{
			if (ft_testlength(global) != 0)
				return (1);
			global->counti = 0;
		}
		if (buf[global->i + 1] == '\n' && buf[global->i] == '\n')
			global->i++;
		global->i++;
	}
	return (0);
}

int				ft_linesvalid(char *buf, t_struct *global)
{
	global->i = 0;
	while (buf[global->i] != '\0')
	{
		global->col = 0;
		while ((buf[global->i] == '.' || buf[global->i] == '#') &&
				global->col != 4)
		{
			global->i++;
			global->col++;
		}
		if (buf[global->i] == '\n' && global->col == 4)
		{
			if (buf[global->i + 1] == '\n')
			{
				global->i++;
				global->line++;
			}
			global->line++;
		}
		else
			return (1);
		global->i++;
	}
	return (0);
}

int				ft_tetrosvalid(char *buf, t_struct *global)
{
	global->line = 0;
	global->col = 0;
	global->y = 0;
	if (buf[0] == '\0')
		return (1);
	if (ft_linesvalid(buf, global) != 0)
		return (1);
	global->nbrtetro = (global->line + 1) / 5;
	if ((global->i + 1) % 21 != 0)
		return (1);
	if ((global->tab = (int**)malloc(sizeof(int*) * global->nbrtetro)) == NULL)
		return (1);
	while (global->y < global->nbrtetro)
	{
		global->tab[global->y] = (int *)malloc(sizeof(int) * 3);
		global->y++;
	}
	if (ft_formsvalid(buf, global) != 0)
		return (1);
	global->line += 1;
	return (0);
}
