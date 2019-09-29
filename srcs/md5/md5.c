/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarthon <lbarthon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 10:40:55 by lbarthon          #+#    #+#             */
/*   Updated: 2019/09/29 16:28:25 by lbarthon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"
#include "ft_ssl.h"
#include "errors.h"
#include <stdlib.h>
#include <unistd.h>

void			md5_init(t_hash *hash)
{
	ft_bzero(hash->name, 10);
	ft_memcpy(hash->name, "md5", 3);
	hash->exec_str = &ft_md5_str;
	hash->exec_stream = &ft_md5_stream;
	hash->display = &ft_md5_display;
	hash->used = 0;
	hash->error = 0;
}

void			ft_md5_stream(int fd, char ret[33], char need_print)
{
	t_md5_stream	stream;
	char			buff[2049];
	int				r;
	int				offset;

	ft_md5_stream_init(&stream);
	while ((r = read(fd, buff, 2048)) > 0)
	{
		buff[r] = '\0';
		if (need_print)
			ft_putstr(buff);
		offset = ft_md5_check_residual(&stream, buff, r);
		while (r - offset >= 64)
		{
			ft_md5_words(stream.hash, (unsigned int *)(buff + offset));
			stream.total_len += 64;
			offset += 64;
		}
		if (r - offset != 0)
			ft_memcpy(stream.buffer, buff + offset
					, (stream.buff_len = r - offset));
	}
	ft_md5_stream_end(&stream);
	ft_md5_ret(stream.hash, ret);
}

void			ft_md5_str(unsigned char *str, int len, char ret[33])
{
	t_md5_stream	stream;
	int				offset;

	ft_md5_stream_init(&stream);
	offset = 0;
	while (len - offset >= 64)
	{
		ft_md5_words(stream.hash, (unsigned int *)(str + offset));
		stream.total_len += 64;
		offset += 64;
	}
	if (len - offset != 0)
	{
		ft_memcpy(stream.buffer, str + offset, len - offset);
		stream.buff_len = len - offset;
	}
	ft_md5_stream_end(&stream);
	ft_md5_ret(stream.hash, ret);
}

void			ft_md5_stream_init(t_md5_stream *stream)
{
	stream->hash[0] = 0x67452301;
	stream->hash[1] = 0xefcdab89;
	stream->hash[2] = 0x98badcfe;
	stream->hash[3] = 0x10325476;
	stream->buff_len = 0;
	stream->total_len = 0;
	ft_bzero(stream->buffer, 64);
}

void			ft_md5_stream_end(t_md5_stream *stream)
{
	size_t	bits_len;

	ft_bzero(stream->buffer + stream->buff_len, 64 - stream->buff_len);
	stream->buffer[(int)stream->buff_len] |= 1 << 7;
	bits_len = (stream->total_len + stream->buff_len) * 8;
	if (stream->buff_len >= 56)
	{
		ft_md5_words(stream->hash, (unsigned int*)stream->buffer);
		stream->buff_len = 0;
		ft_bzero(stream->buffer, 64);
	}
	ft_memcpy(stream->buffer + 56, &bits_len, 8);
	ft_md5_words(stream->hash, (unsigned int*)stream->buffer);
}
