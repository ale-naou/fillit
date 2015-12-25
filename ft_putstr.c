/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgiraud <fgiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 12:02:47 by fgiraud           #+#    #+#             */
/*   Updated: 2015/12/25 20:09:48 by ale-naou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_putstr(char const *s)
{
	int i;

	i = 0;
	if (s == NULL)
		ft_putstr("null");
	while (s[i] != '\0')
	{
		ft_putchar(s[i]);
		i++;
	}
	return (0);
}
