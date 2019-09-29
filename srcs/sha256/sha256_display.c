/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha256_display.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarthon <lbarthon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 13:08:59 by lbarthon          #+#    #+#             */
/*   Updated: 2019/09/29 15:24:41 by lbarthon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"
#include "ft_ssl.h"

void			ft_sha256_display(char ret[65], char *str
		, char flags, char quotes)
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
		ft_putstr("SHA256 (");
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
