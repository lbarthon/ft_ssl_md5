/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5_display.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarthon <lbarthon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 11:03:27 by lbarthon          #+#    #+#             */
/*   Updated: 2019/09/29 12:37:55 by lbarthon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"
#include "ft_ssl.h"

void			ft_md5_display(char ret[33], char *str, char flags, char quotes)
{
	if (ft_has_flag(flags, 'q'))
		ft_putendl(ret);
	else if (ft_has_flag(flags, 'r'))
	{
		ft_putstr(ret);
		ft_putstr(" ");
		ft_putendl(str);
	}
	else if (str)
	{
		ft_putstr("MD5(");
		if (quotes)
			ft_putstr("\"");
		ft_putstr(str);
		if (quotes)
			ft_putstr("\"");
		ft_putstr(") = ");
		ft_putendl(ret);
	}
	else
		ft_putendl(ret);
}
