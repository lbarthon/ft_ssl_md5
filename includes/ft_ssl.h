/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarthon <lbarthon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 12:14:34 by lbarthon          #+#    #+#             */
/*   Updated: 2019/09/29 13:37:36 by lbarthon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SSL_H
# define FT_SSL_H

# include <string.h>

# define ROTATELEFT(n, s) (((n) << s) | ((n) >> (sizeof(n) * 8 - s)))
# define ROTATERIGHT(n, s) (((n) >> s) | ((n) << (sizeof(n) * 8 - s)))

typedef struct	s_md5_stream {
	unsigned char	buffer[64];
	char			buff_len;
	size_t			total_len;
	unsigned int	hash[4];
}				t_md5_stream;

typedef struct	s_sha256_stream {
	unsigned char	buffer[256];
	char			buff_len;
	size_t			total_len;
	unsigned int	hash[8];
}				t_sha256_stream;

typedef struct	s_hash {
	char	name[10];
	void	(*exec_stream)(int, char *, char);
	void	(*exec_str)(unsigned char *, int, char *);
	void	(*display)(char *, char *, char, char);
	char	used;
	char	error;
}				t_hash;

short			ft_get_command_id(char *cmd);
int				ft_get_flags(char *str, char *curr);
char			ft_get_flag_id(char flag);
char			ft_has_flag(char flags, char flag);

void			hash_start(t_hash *hash, char **av);
void			flag_err(t_hash *hash, char c);
void			hash_str(t_hash *hash, char *str, char flags);
void			hash_stream(t_hash *hash, char *str, char flags);
void			hash_stdin(t_hash *hash, char flags, char force);

/*
** All md5 functions
*/
void			md5_init(t_hash *hash);
void			ft_md5_str(unsigned char *str, int len, char ret[33]);
void			ft_md5_stream(int fd, char ret[33], char need_print);
void			ft_md5_display(char ret[33], char *str, char flags, char q);
void			ft_md5_ret(unsigned int *i, char ret[33]);
int				ft_md5_check_residual(t_md5_stream *stream, char buff[2048]
		, int r);
void			ft_md5_stream_init(t_md5_stream *stream);
void			ft_md5_stream_end(t_md5_stream *stream);
void			ft_md5_words(unsigned int *h, unsigned int *w);

/*
** All sha256 functions
*/
void			sha256_init(t_hash *hash);
void			ft_sha256_str(unsigned char *str, int len, char ret[65]);
void			ft_sha256_stream(int fd, char ret[65], char need_print);
void			ft_sha256_display(char ret[65], char *str, char flags, char q);
void			ft_sha256_ret(unsigned int *i, char ret[65]);
int				ft_sha256_check_residual(t_sha256_stream *stream, char buff[2048]
		, int r);
void			ft_sha256_stream_init(t_sha256_stream *stream);
void			ft_sha256_stream_end(t_sha256_stream *stream);
void			ft_sha256_words(unsigned int *h, unsigned int *w);

#endif
