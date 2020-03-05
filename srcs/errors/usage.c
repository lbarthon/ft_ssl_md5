/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usage.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarthon <lbarthon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 11:32:17 by lbarthon          #+#    #+#             */
/*   Updated: 2020/03/05 17:44:52 by lbarthon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ssl.h"
#include "printf.h"

void	print_usage(void)
{
	ft_dprintf(2, "usage: ft_ssl command [-pqr] [-s string] [file ...]\n");
}

void	not_found(char *algo, char *path, int fd)
{
	if (fd == -1)
		ft_dprintf(2, "ft_ssl: %s: %s: No such file or directory"
				"\n", algo, path);
	else
		ft_dprintf(2, "ft_ssl: %s: %s: Not handling directories"
				"\n", algo, path);
}

void	wrong_flag(t_hash *hash, char flag)
{
	ft_dprintf(2, "ft_ssl: illegal option -- %c\n", flag);
	print_usage();
	hash->error = 1;
}

void	err_noarg(t_hash *hash, char flag)
{
	ft_dprintf(2, "ft_ssl: option requires an argument -- %c\n", flag);
	print_usage();
	hash->error = 1;
}
