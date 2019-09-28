/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarthon <lbarthon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 12:14:34 by lbarthon          #+#    #+#             */
/*   Updated: 2019/09/28 14:26:42 by lbarthon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SSL_H
# define FT_SSL_H

# define ROTATELEFT(n, s) (((n) << s) | ((n) >> (sizeof(n) * 8 - s)))
# define ROTATERIGHT(n, s) (((n) >> s) | ((n) << (sizeof(n) * 8 - s)))

short	ft_get_command_id(char *cmd);
char	ft_get_flags(int ac, char **av);
char	ft_get_flag_id(char flag);
char	ft_has_flag(char flags, char flag);

void	exec_md5(char flags, int i, int ac, char **av);
void	exec_sha256(char flags, int i, int ac, char **av);

void			ft_md5(unsigned char *str, int len, char ret[33]);
void			ft_get_ret(int *h, char ret[33]);
void			*ft_prepare_msg(unsigned char *str, int len);
void			ft_main_loop(int *h, unsigned int *w);
unsigned int	ft_get_f(unsigned int *t, int i);
unsigned int	ft_get_g(int i);

#endif
