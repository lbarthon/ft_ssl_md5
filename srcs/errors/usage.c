/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usage.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarthon <lbarthon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 11:32:17 by lbarthon          #+#    #+#             */
/*   Updated: 2019/10/03 11:24:43 by lbarthon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"
#include "ft_ssl.h"
#include <unistd.h>

void	ft_print_usage(void)
{
	ft_putendl_fd("usage: ft_ssl command [-pqr] [-s string] [file ...]", 2);
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

void	ft_wrong_flag(t_hash *hash, char flag)
{
	ft_putstr_fd("ft_ssl: illegal option -- ", 2);
	write(2, &flag, 1);
	ft_putendl_fd("", 2);
	ft_print_usage();
	hash->error = 1;
}

void	ft_err_noarg(t_hash *hash, char flag)
{
	ft_putstr_fd("ft_ssl: option requires an argument -- ", 2);
	write(2, &flag, 1);
	ft_putendl_fd("", 2);
	ft_print_usage();
	hash->error = 1;
}
