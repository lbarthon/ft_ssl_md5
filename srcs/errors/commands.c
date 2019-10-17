/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarthon <lbarthon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 11:40:55 by lbarthon          #+#    #+#             */
/*   Updated: 2019/10/17 18:36:54 by lbarthon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "printf.h"

void	ft_print_wrong_command(const char *cmd)
{
	ft_dprintf(2, "ft_ssl: Error: '%s' is an invalid command.\n\n", cmd);
	ft_dprintf(2, "Standard commands:\n\n");
	ft_dprintf(2, "Message Digest commands:\nmd5\nsha256\n\n");
	ft_dprintf(2, "Cipher commands\n\n");
}
