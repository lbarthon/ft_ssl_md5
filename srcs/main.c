/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarthon <lbarthon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 11:17:22 by lbarthon          #+#    #+#             */
/*   Updated: 2020/03/06 11:49:52 by lbarthon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "errors.h"
#include "ft_ssl.h"
#include <stdio.h>

t_command g_commands[] = {
	{"md5", DIGEST, &md5_init},
	{"sha1", DIGEST, &sha1_init},
	{"sha256", DIGEST, &sha256_init},
	{NULL, -1, NULL}
};

void	process(char **av)
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
		print_wrong_command(av[1]);
}

int		main(int ac, char **av)
{
	if (ac > 1)
		process(av);
	else
		print_usage();
	return (0);
}
