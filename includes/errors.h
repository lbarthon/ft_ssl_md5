/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarthon <lbarthon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 11:33:22 by lbarthon          #+#    #+#             */
/*   Updated: 2019/09/29 12:37:03 by lbarthon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H

# include "ft_ssl.h"

void	ft_print_usage();
void	ft_print_wrong_command(const char *cmd);
void	ft_not_found(char *algo, char *path, int fd);
void	ft_wrong_flag(t_hash *hash, char flag);
void	ft_err_noarg(t_hash *hash, char flag);

#endif
