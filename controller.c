/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controller.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffrimpon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/06 23:59:47 by ffrimpon          #+#    #+#             */
/*   Updated: 2015/12/26 21:33:46 by ale-naou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

int		one_ring(char **tetra_box, char **grid, size_t current, size_t n_tetra)
{
	int	x;
	int	y;

	x = -1;
	y = -1;
	while ((grid[++y][0]) != 0)
	{
		while (grid[y][++x] != 0)
		{
			if (to_check_if_possible(grid, x, y, tetra_box[current]) == 1)
			{
				grid = to_put_some_d(grid, x, y, tetra_box[current]);
				grid = to_never_forget(grid, current);
				if (current + 1 == n_tetra)
					return (to_put_answer_in_your_face(grid));
				else if (one_ring(tetra_box, grid, current + 1, n_tetra) == 1)
					return (1);
				else
					grid = ok_forget_it(grid, current);
			}
		}
		x = -1;
	}
	return (0);
}



void	i_am_your_master(char **tetra_box, size_t n_tetra)
{
	int		i;
	char	**opti_box;

	i = 1;
	opti_box = alloc_me_pliizzz(opti_size_box(n_tetra) + 26);
	while (i > 0)
	{
		if (one_ring(tetra_box, opti_box, 0, n_tetra) == 0)
		{
			free(opti_box);
			opti_box = alloc_me_pliizzz(opti_size_box(n_tetra) + 26 + i);
			i++;
		}
		else
			i = 0;
	}
	free(opti_box);
}

size_t	palantir(char *av)
{
	int		fd;
	int		ret;
	char	tetriminos[BUF_SIZE];
	size_t	n_tetra;

	n_tetra = 0;
	fd = open(av, O_RDONLY);
	if (fd == -1)
		return (0);
	while ((ret = read(fd, tetriminos, BUF_SIZE)))
	{
		n_tetra++;
		if (n_tetra > 26)
			return (0);
	}
	if (close(fd) == -1)
		return (0);
	return (n_tetra);
}

int		main(int ac, char **av)
{
	size_t	n_tetra;
	char	**tetra_box;

	if (ac != 2)
	{
		ft_putendl("error");
		return (0);
	}
	n_tetra = palantir(av[1]);
	if (n_tetra == 0)
	{
		ft_putendl("error");
		return (0);
	}
	tetra_box = alloc_me_pliizzz(n_tetra);
	tetra_box = give_me_tetra(av[1], tetra_box);
	if (you_shall_not_pass(tetra_box, n_tetra) == 0)
	{
		ft_putendl("error");
		return (0);
	}
	i_am_your_master(tetra_box, n_tetra);
	free(tetra_box);
	return (0);
}
