/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgiraud <fgiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 13:17:52 by fgiraud           #+#    #+#             */
/*   Updated: 2015/12/29 17:48:37 by ale-naou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>

typedef	struct		s_struct
{
	int				line;
	int				col;
	int				**tab;
	int				tabhash[4];
	int				nbrtetro;
	int				counti;
	int				nbrhash;
	int				i;
	int				imap;
	int				x;
	int				y;
	char			*mapmax;
	int				power;
	int				mapopti;

}					t_struct;

void				ft_putchar(char c);
void				ft_putnbr(int n);
int					ft_putstr(char const *str);
char				*ft_strnew(size_t size);
int					ft_strlen(char *str);

void				ft_init(t_struct *global);
int					ft_error(int n);
int					ft_tetrosvalid(char *buf, t_struct *global);
int					ft_linesvalid(char *buf, t_struct *global);
int					ft_recursive(t_struct *global, int ctetro);
void				ft_resolve(t_struct *global);

#endif
