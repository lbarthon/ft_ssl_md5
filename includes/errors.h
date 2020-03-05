/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarthon <lbarthon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 11:33:22 by lbarthon          #+#    #+#             */
/*   Updated: 2020/03/05 17:45:27 by lbarthon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H

# include "ft_ssl.h"

void	print_usage();
void	print_wrong_command(const char *cmd);
void	not_found(char *algo, char *path, int fd);
void	wrong_flag(t_hash *hash, char flag);
void	err_noarg(t_hash *hash, char flag);

#endif
