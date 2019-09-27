/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarthon <lbarthon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 12:22:15 by lbarthon          #+#    #+#             */
/*   Updated: 2019/09/24 10:32:23 by lbarthon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"
#include <stdlib.h>

/*
** Flag ids:
**  -p => 0
**  -q => 1
**  -r => 2
**  -s => 3
*/

char	ft_get_flag_id(char flag)
{
	if (flag == 'p')
		return (0);
	if (flag == 'q')
		return (1);
	if (flag == 'r')
		return (2);
	if (flag == 's')
		return (3);
	return (-1);
}

char	ft_get_flags(int ac, char **av)
{
	char	ret;
	int		i;
	int		f;
	int		j;
	int		len;

	ret = 0;
	i = 2;
	if (ac < i)
		return (ret);
	while (i < ac)
	{
		if (av[i][0] != '-')
			return (ret);
		len = ft_strlen(av[i]);
		j = 0;
		while (++j < len)
		{
			f = ft_get_flag_id(av[i][j]);
			if (f != -1)
				ret |= 1 << f;
		}
		i++;
	}
	return (ret);
}
