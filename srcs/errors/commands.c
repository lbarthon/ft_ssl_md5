/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarthon <lbarthon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 11:40:55 by lbarthon          #+#    #+#             */
/*   Updated: 2020/03/05 13:52:03 by lbarthon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "printf.h"
#include "ft_ssl.h"

extern t_command	g_commands[];

static void		print_type(t_type type)
{
	int i;

	i = -1;
	while (g_commands[++i].name)
		if (g_commands[i].type == type)
			ft_dprintf(2, "%s\n", g_commands[i].name);
	ft_dprintf(2, "\n");
}

void			ft_print_wrong_command(const char *cmd)
{
	ft_dprintf(2, "ft_ssl: Error: '%s' is an invalid command.\n\n", cmd);
	ft_dprintf(2, "Standard commands:\n");
	print_type(STANDARD);
	ft_dprintf(2, "Message Digest commands:\n");
	print_type(DIGEST);
	ft_dprintf(2, "Cipher commands\n");
	print_type(CIPHER);
}
