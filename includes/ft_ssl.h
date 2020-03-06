/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarthon <lbarthon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 12:14:34 by lbarthon          #+#    #+#             */
/*   Updated: 2020/03/06 11:50:54 by lbarthon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SSL_H
# define FT_SSL_H

# include <string.h>

typedef struct	s_md5_stream {
	unsigned char	buffer[64];
	char			buff_len;
	size_t			total_len;
	unsigned int	hash[4];
}				t_md5_stream;

typedef struct	s_sha256_stream {
	unsigned char	buffer[64];
	char			buff_len;
	size_t			total_len;
	unsigned int	hash[8];
}				t_sha256_stream;

typedef struct	s_sha1_stream {
	unsigned char	buffer[64];
	char			buff_len;
	size_t			total_len;
	unsigned int	hash[5];
}				t_sha1_stream;

typedef struct	s_hash {
	char	name[10];
	char	display_name[10];
	void	(*exec_stream)(int, char *, char);
	void	(*exec_str)(unsigned char *, int, char *);
	char	used;
	char	stdin_used;
	char	error;
}				t_hash;

typedef enum	e_type {
	STANDARD,
	DIGEST,
	CIPHER
}				t_type;

typedef struct	s_command {
	char	*name;
	t_type	type;
	void	(*init)(t_hash *hash);
}				t_command;

short			get_command_id(char *cmd);
int				get_flags(char *str, char *curr);
char			get_flag_id(char flag);
char			has_flag(char flags, char flag);

unsigned int	rotateleft(unsigned int n, unsigned int s);
unsigned int	rotateright(unsigned int n, unsigned int s);

void			hash_start(t_hash *hash, char **av);
void			flag_err(t_hash *hash, char c);
void			hash_str(t_hash *hash, char *str, char flags);
void			hash_stream(t_hash *hash, char *str, char flags);
void			hash_stdin(t_hash *hash, char flags, char force);
void			hash_display_file(t_hash *hash, char *ret, char *str
		, char flags);
void			hash_display_str(t_hash *hash, char *ret, char *str
		, char flags);

/*
** All md5 functions
*/
void			md5_init(t_hash *hash);
void			md5_str(unsigned char *str, int len, char ret[33]);
void			md5_stream(int fd, char ret[33], char need_print);
void			md5_ret(unsigned int *i, char ret[33]);
int				md5_check_residual(t_md5_stream *stream, char buff[2048]
		, int r);
void			md5_stream_init(t_md5_stream *stream);
void			md5_stream_end(t_md5_stream *stream);
void			md5_words(unsigned int *h, unsigned int *w);

/*
** All sha1 functions
*/
void			sha1_init(t_hash *hash);
void			sha1_str(unsigned char *str, int len, char ret[33]);
void			sha1_stream(int fd, char ret[33], char need_print);
void			sha1_ret(unsigned int *i, char ret[33]);
int				sha1_check_residual(t_sha1_stream *stream, char buff[2048]
		, int r);
void			sha1_stream_init(t_sha1_stream *stream);
void			sha1_stream_end(t_sha1_stream *stream);
void			sha1_words(unsigned int *h, unsigned int *w);

/*
** All sha256 functions
*/
void			sha256_init(t_hash *hash);
void			sha256_str(unsigned char *str, int len, char ret[65]);
void			sha256_stream(int fd, char ret[65], char need_print);
void			sha256_ret(unsigned int *i, char ret[65]);
int				sha256_check_residual(t_sha256_stream *stream
		, char buff[2048], int r);
void			sha256_stream_init(t_sha256_stream *stream);
void			sha256_stream_end(t_sha256_stream *stream);
void			sha256_words(unsigned int *h, unsigned int *w);

#endif
