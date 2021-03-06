/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha256.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarthon <lbarthon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 10:42:07 by lbarthon          #+#    #+#             */
/*   Updated: 2020/03/05 17:40:45 by lbarthon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ssl.h"
#include "errors.h"
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

void			sha256_init(t_hash *hash)
{
	ft_strcpy(hash->name, "sha256");
	ft_strcpy(hash->display_name, "SHA 256");
	hash->exec_str = &sha256_str;
	hash->exec_stream = &sha256_stream;
	hash->used = 0;
	hash->stdin_used = 0;
	hash->error = 0;
}

void			sha256_stream(int fd, char ret[65], char need_print)
{
	t_sha256_stream	stream;
	char			buff[2049];
	int				r;
	int				offset;

	sha256_stream_init(&stream);
	while ((r = read(fd, buff, 2048)) > 0)
	{
		buff[r] = '\0';
		if (need_print)
			ft_putstr(buff);
		offset = sha256_check_residual(&stream, buff, r);
		while (r - offset >= 64)
		{
			sha256_words(stream.hash, (unsigned int *)(buff + offset));
			stream.total_len += 64;
			offset += 64;
		}
		if (r - offset != 0)
			ft_memcpy(stream.buffer, buff + offset
					, (stream.buff_len = r - offset));
	}
	sha256_stream_end(&stream);
	sha256_ret(stream.hash, ret);
}

void			sha256_str(unsigned char *str, int len, char ret[65])
{
	t_sha256_stream	stream;
	int				offset;

	sha256_stream_init(&stream);
	offset = 0;
	while (len - offset >= 64)
	{
		sha256_words(stream.hash, (unsigned int *)(str + offset));
		stream.total_len += 64;
		offset += 64;
	}
	if (len - offset != 0)
	{
		ft_memcpy(stream.buffer, str + offset, len - offset);
		stream.buff_len = len - offset;
	}
	sha256_stream_end(&stream);
	sha256_ret(stream.hash, ret);
}

void			sha256_stream_init(t_sha256_stream *stream)
{
	stream->hash[0] = 0x6a09e667;
	stream->hash[1] = 0xbb67ae85;
	stream->hash[2] = 0x3c6ef372;
	stream->hash[3] = 0xa54ff53a;
	stream->hash[4] = 0x510e527f;
	stream->hash[5] = 0x9b05688c;
	stream->hash[6] = 0x1f83d9ab;
	stream->hash[7] = 0x5be0cd19;
	stream->buff_len = 0;
	stream->total_len = 0;
	ft_bzero(stream->buffer, 64);
}

void			sha256_stream_end(t_sha256_stream *stream)
{
	size_t	bits_len;

	ft_bzero(stream->buffer + stream->buff_len, 64 - stream->buff_len);
	stream->buffer[(int)stream->buff_len] = 1 << 7;
	bits_len = (stream->total_len + stream->buff_len) * 8;
	if (stream->buff_len >= 56)
	{
		sha256_words(stream->hash, (unsigned int*)stream->buffer);
		stream->buff_len = 0;
		ft_bzero(stream->buffer, 64);
	}
	ft_memrev(&bits_len, 8);
	ft_memcpy(stream->buffer + 56, &bits_len, 8);
	sha256_words(stream->hash, (unsigned int*)stream->buffer);
}
