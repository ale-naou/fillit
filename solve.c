/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffrimpon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 18:46:32 by ffrimpon          #+#    #+#             */
/*   Updated: 2015/12/26 21:33:48 by ale-naou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

int		to_check_if_possible(char **grid, int x, int y, char *tetri)
{
	int				i;

	i = 0;
	while (tetri[i] != '#')
		i++;
	while (tetri[i] != '\0')
	{
		if (tetri[i] == '\n')
		{
			i++;
			y++;
			x = x - 4;
		}
		else if ((tetri[i] == '.') || (grid[y][x] == '.' && tetri[i] == '#'))
		{
			i++;
			x++;
		}
		else if ((x < 0 && tetri[i] == '#') ||
			(grid[y][x] != '.' && tetri[i] == '#'))
			return (0);
	}
	return (1);
}

char	**to_put_some_d(char **grid, int x, int y, char *tetri)
{
	int	i;

	i = 0;
	while (tetri[i] != '#')
		i++;
	while (tetri[i] != '\0')
	{
		if (tetri[i] == '\n')
		{
			i++;
			y++;
			x = x - 4;
		}
		else if (tetri[i] == '.' || (grid[y][x] == '.' && tetri[i] == '#'))
		{
			if (tetri[i] != '.' && grid[y][x] == '.' && tetri[i] == '#')
				grid[y][x] = '#';
			i++;
			x++;
		}
		else if ((x < 0 && tetri[i] == '#')
			|| (grid[y][x] != '.' && tetri[i] == '#'))
			return (0);
	}
	return (grid);
}

char	**to_never_forget(char **grid, int current)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (grid[y][0])
	{
		while (grid[y][x])
		{
			if (grid[y][x] == '#')
				grid[y][x] = 'A' + current;
			x++;
		}
		x = 0;
		y++;
	}
	return (grid);
}

int		to_put_answer_in_your_face(char **grid)
{
	size_t i;

	i = 0;
	while (grid[i][0] != '\0')
	{
		ft_putendl(grid[i]);
		i++;
	}
	return (1);
}

char	**ok_forget_it(char **grid, int current)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (grid[y][0])
	{
		while (grid[y][x])
		{
			if (grid[y][x] == 'A' + current)
				grid[y][x] = '.';
			x++;
		}
		x = 0;
		y++;
	}
	return (grid);
}
