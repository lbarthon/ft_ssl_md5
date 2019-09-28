/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarthon <lbarthon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 12:14:34 by lbarthon          #+#    #+#             */
/*   Updated: 2019/09/28 18:02:18 by lbarthon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SSL_H
# define FT_SSL_H

#include <string.h>

# define ROTATELEFT(n, s) (((n) << s) | ((n) >> (sizeof(n) * 8 - s)))
# define ROTATERIGHT(n, s) (((n) >> s) | ((n) << (sizeof(n) * 8 - s)))

typedef struct	s_hash_stream {
	unsigned char	buffer[64];
	char			buff_len;
	size_t			total_len;
	unsigned int	hash[0];
}				t_hash_stream;

typedef struct	s_md5_stream {
	unsigned char	buffer[64];
	char			buff_len;
	size_t			total_len;
	unsigned int	hash[4];
}				t_md5_stream;

short			ft_get_command_id(char *cmd);
char			ft_get_flags(int ac, char **av);
char			ft_get_flag_id(char flag);
char			ft_has_flag(char flags, char flag);

void			exec_md5(char flags, int i, int ac, char **av);
void			exec_sha256(char flags, int i, int ac, char **av);

void			ft_md5_str(unsigned char *str, int len, char ret[33]);
void			ft_md5_stream(int fd, char ret[33], char need_print);
void			ft_md5_display(char ret[33], char flags, char *str);
void			ft_get_ret(unsigned int *, char ret[33]);
int				ft_md5_check_residual(t_md5_stream *stream, char buff[2048]
		, int r);
void			ft_md5_stream_init(t_md5_stream *stream);
void			ft_md5_stream_end(t_md5_stream *stream);
void			*ft_prepare_msg(unsigned char *str, int len);
void			ft_md5_words(unsigned int *h, unsigned int *w);

#endif
