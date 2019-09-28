/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarthon <lbarthon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 11:17:22 by lbarthon          #+#    #+#             */
/*   Updated: 2019/09/28 14:31:36 by lbarthon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"
#include "errors.h"
#include "ft_ssl.h"
#include <stdio.h>

void	ft_process(short id, int ac, char **av)
{
	char	flags;
	int		i;
	
	i = 2;
	flags = ft_get_flags(ac, av);
	while (i < ac && av[i][0] == '-')
		i++;
	if (id == 1)
		exec_md5(flags, i, ac, av);
	else if (id == 2)
		exec_sha256(flags, i, ac, av);
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
			ft_process(id, ac, av);
	}
	else
		ft_print_usage();
	return (0);
}
