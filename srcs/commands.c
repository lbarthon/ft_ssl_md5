/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarthon <lbarthon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 12:13:01 by lbarthon          #+#    #+#             */
/*   Updated: 2019/10/17 17:46:11 by lbarthon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

short	ft_get_command_id(char *cmd)
{
	if (!ft_strcmp(cmd, "md5"))
		return (1);
	if (!ft_strcmp(cmd, "sha256"))
		return (2);
	return (-1);
}
