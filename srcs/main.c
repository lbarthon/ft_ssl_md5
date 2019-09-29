/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarthon <lbarthon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 11:17:22 by lbarthon          #+#    #+#             */
/*   Updated: 2019/09/29 13:10:20 by lbarthon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"
#include "errors.h"
#include "ft_ssl.h"
#include <stdio.h>

void	ft_process(short id, char **av)
{
	t_hash	hash;
	char	flags;
	int		i;

	i = 2;
	flags = 0;
	if (flags == -1)
		return ;
	if (id == 1)
		md5_init(&hash);
	else if (id == 2)
		sha256_init(&hash);
	hash_start(&hash, av);
}

int		main(int ac, char **av)
{
	short id;

	if (ac > 1)
	{
		id = ft_get_command_id(av[1]);
		if (id == -1)
			ft_print_wrong_command(av[1]);
		else
			ft_process(id, av);
	}
	else
		ft_print_usage();
	return (0);
}
