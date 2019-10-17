/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usage.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarthon <lbarthon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 11:32:17 by lbarthon          #+#    #+#             */
/*   Updated: 2019/10/17 18:53:42 by lbarthon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ssl.h"
#include "printf.h"

void	ft_print_usage(void)
{
	ft_dprintf(2, "usage: ft_ssl command [-pqr] [-s string] [file ...]\n");
}

void	ft_not_found(char *algo, char *path, int fd)
{
	if (fd == -1)
		ft_dprintf(2, "ft_ssl: %s: %s: No such file or directory"
				"\n", algo, path);
	else
		ft_dprintf(2, "ft_ssl: %s: %s: Not handling directories"
				"\n", algo, path);
}

void	ft_wrong_flag(t_hash *hash, char flag)
{
	ft_dprintf(2, "ft_ssl: illegal option -- %c\n", flag);
	ft_print_usage();
	hash->error = 1;
}

void	ft_err_noarg(t_hash *hash, char flag)
{
	ft_dprintf(2, "ft_ssl: option requires an argument -- %c\n", flag);
	ft_print_usage();
	hash->error = 1;
}
