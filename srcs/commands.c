/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarthon <lbarthon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 12:13:01 by lbarthon          #+#    #+#             */
/*   Updated: 2019/09/15 12:20:34 by lbarthon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

short	ft_get_command_id(char *cmd)
{
	if (!ft_strcmp(cmd, "md5"))
		return (1);
	if (!ft_strcmp(cmd, "sha256"))
		return (2);
	return (-1);
}
