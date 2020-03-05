/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarthon <lbarthon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 11:43:13 by lbarthon          #+#    #+#             */
/*   Updated: 2020/03/05 16:05:20 by lbarthon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ssl.h"
#include "errors.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

void	hash_main(t_hash *hash, char **av, char *flags, int *i)
{
	int		k;

	if (av[*i][0] == '-')
	{
		k = ft_get_flags(av[*i], flags);
		if (av[*i][k] && av[*i][k] == 's')
		{
			if (av[*i][k + 1])
				hash_str(hash, av[*i] + k + 1, *flags);
			else if (av[*i + 1])
				hash_str(hash, av[++*i], *flags);
			else
				ft_err_noarg(hash, av[*i][k]);
		}
		else if (av[*i][k])
			ft_wrong_flag(hash, av[*i][k]);
	}
	else
		hash_stream(hash, av[*i], *flags);
	if (ft_has_flag(*flags, 'p'))
		hash_stdin(hash, *flags, 1);
}

void	hash_start(t_hash *hash, char **av)
{
	char	flags;
	int		i;

	i = 1;
	flags = 0;
	while (av[++i])
		hash_main(hash, av, &flags, &i);
	if (!hash->used && !hash->error)
		hash_stdin(hash, flags, 1);
}

void	hash_str(t_hash *hash, char *str, char flags)
{
	char	ret[65];

	hash->exec_str((unsigned char *)str, ft_strlen(str), ret);
	hash_display_str(hash, ret, str, flags);
	hash->used = 1;
}

void	hash_stream(t_hash *hash, char *str, char flags)
{
	char	ret[65];
	int		fd;

	if (!hash->used)
		hash_stdin(hash, flags, 0);
	fd = open(str, O_RDONLY);
	if (fd == -1 || read(fd, NULL, 0) == -1)
	{
		ft_not_found(hash->name, str, fd);
		hash->error = 1;
	}
	else
	{
		hash->exec_stream(fd, ret, 0);
		hash_display_file(hash, ret, str, flags);
		close(fd);
	}
	hash->used = 1;
}

void	hash_stdin(t_hash *hash, char flags, char force)
{
	char	ret[65];

	if (isatty(0) && !hash->stdin_used)
		hash->exec_stream(0, ret, ft_has_flag(flags, 'p'));
	else if (!force)
		return ;
	else
		hash->exec_str((unsigned char *)"", 0, ret);
	hash_display_file(hash, ret, NULL, flags);
	hash->stdin_used = 1;
	hash->used = 1;
}
