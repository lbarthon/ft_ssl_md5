/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarthon <lbarthon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 11:40:55 by lbarthon          #+#    #+#             */
/*   Updated: 2019/09/24 10:25:24 by lbarthon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

void	ft_print_wrong_command(const char *cmd)
{
	ft_putstr_fd("ft_ssl: Error: '", 2);
	ft_putstr_fd(cmd, 2);
	ft_putstr_fd("' is an invalid command.\n\n", 2);
	ft_putendl_fd("Standard commands:", 2);
	ft_putendl_fd("", 2);
	ft_putendl_fd("Message Digest commands:", 2);
	ft_putendl_fd("md5", 2);
	ft_putendl_fd("sha256", 2);
	ft_putendl_fd("", 2);
	ft_putendl_fd("Cipher commands", 2);
	ft_putendl_fd("", 2);
}
