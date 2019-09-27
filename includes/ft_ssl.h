/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarthon <lbarthon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 12:14:34 by lbarthon          #+#    #+#             */
/*   Updated: 2019/09/24 11:00:50 by lbarthon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SSL_H
# define FT_SSL_H

short	ft_get_command_id(char *cmd);
char	ft_get_flags(int ac, char **av);
char	ft_get_flag_id(char flag);

void	exec_md5(char flags, int i, int ac, char **av);
void	exec_sha256(char flags, int i, int ac, char **av);

#endif
