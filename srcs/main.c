/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarthon <lbarthon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 11:17:22 by lbarthon          #+#    #+#             */
/*   Updated: 2020/03/05 13:37:56 by lbarthon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "errors.h"
#include "ft_ssl.h"
#include <stdio.h>

t_command g_commands[] = {
	{"md5", DIGEST, &md5_init},
	{"sha256", DIGEST, &sha256_init},
	{NULL, -1, NULL}
};

void	ft_process(char **av)
{
	t_hash	hash;
	int		i;

	i = -1;
	while (g_commands[++i].name)
		if (strcmp(av[1], g_commands[i].name) == 0)
			break ;
	if (g_commands[i].name)
	{
		g_commands[i].init(&hash);
		hash_start(&hash, av);
	}
	else
		ft_print_wrong_command(av[1]);
}

int		main(int ac, char **av)
{
	if (ac > 1)
		ft_process(av);
	else
		ft_print_usage();
	return (0);
}
