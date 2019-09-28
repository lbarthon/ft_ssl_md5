/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usage.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarthon <lbarthon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 11:32:17 by lbarthon          #+#    #+#             */
/*   Updated: 2019/09/15 11:52:27 by lbarthon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

void	ft_print_usage()
{
	ft_putendl_fd("usage: ft_ssl command [command opts] [command args]", 2);
}

void	ft_not_found(char *algo, char *path, int fd)
{
	if (fd == -1)
	{
		ft_putstr_fd("ft_ssl: ", 2);
		ft_putstr_fd(algo, 2);
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(path, 2);
		ft_putendl_fd(": No such file or directory", 2);
	}
	else
	{
		ft_putstr_fd("ft_ssl: ", 2);
		ft_putstr_fd(algo, 2);
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(path, 2);
		ft_putendl_fd(": Not handling directories", 2);
	}
}
