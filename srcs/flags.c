/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarthon <lbarthon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 12:22:15 by lbarthon          #+#    #+#             */
/*   Updated: 2020/03/05 17:43:18 by lbarthon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "errors.h"
#include <stdlib.h>

/*
** Flag ids:
**  -p => 0
**  -q => 1
**  -r => 2
*/

char	get_flag_id(char flag)
{
	if (flag == 'p')
		return (0);
	if (flag == 'q')
		return (1);
	if (flag == 'r')
		return (2);
	return (-1);
}

char	has_flag(char flags, char flag)
{
	int		flag_id;

	flag_id = get_flag_id(flag);
	if (flag_id == -1)
		return (0);
	return ((flags & 1 << flag_id) != 0);
}

int		get_flags(char *str, char *curr)
{
	int		f;
	int		i;
	int		len;

	len = ft_strlen(str);
	i = 0;
	(*curr) &= ~(1 << get_flag_id('p'));
	while (++i < len)
	{
		if ((f = get_flag_id(str[i])) != -1)
			(*curr) |= 1 << f;
		else
			return (i);
	}
	return (i);
}
