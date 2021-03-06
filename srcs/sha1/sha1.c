/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarthon <lbarthon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 17:31:46 by lbarthon          #+#    #+#             */
/*   Updated: 2020/03/06 11:52:00 by lbarthon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ssl.h"
#include "errors.h"
#include <stdlib.h>
#include <unistd.h>

void			sha1_init(t_hash *hash)
{
	ft_strcpy(hash->name, "sha1");
	ft_strcpy(hash->display_name, "SHA 1");
	hash->exec_str = &sha1_str;
	hash->exec_stream = &sha1_stream;
	hash->used = 0;
	hash->stdin_used = 0;
	hash->error = 0;
}

void			sha1_stream(int fd, char ret[33], char need_print)
{
	t_sha1_stream	stream;
	char			buff[2049];
	int				r;
	int				offset;

	sha1_stream_init(&stream);
	while ((r = read(fd, buff, 2048)) > 0)
	{
		buff[r] = 0;
		if (need_print)
			ft_putstr(buff);
		offset = sha1_check_residual(&stream, buff, r);
		while (r - offset >= 64)
		{
			sha1_words(stream.hash, (unsigned int *)(buff + offset));
			stream.total_len += 64;
			offset += 64;
		}
		if (r - offset != 0)
			ft_memcpy(stream.buffer, buff + offset
					, (stream.buff_len = r - offset));
	}
	sha1_stream_end(&stream);
	sha1_ret(stream.hash, ret);
}

void			sha1_str(unsigned char *str, int len, char ret[33])
{
	t_sha1_stream	stream;
	int				offset;

	sha1_stream_init(&stream);
	offset = 0;
	while (len - offset >= 64)
	{
		sha1_words(stream.hash, (unsigned int *)(str + offset));
		stream.total_len += 64;
		offset += 64;
	}
	if (len - offset != 0)
	{
		ft_memcpy(stream.buffer, str + offset, len - offset);
		stream.buff_len = len - offset;
	}
	sha1_stream_end(&stream);
	sha1_ret(stream.hash, ret);
}

void			sha1_stream_init(t_sha1_stream *stream)
{
	stream->hash[0] = 0x67452301;
	stream->hash[1] = 0xefcdab89;
	stream->hash[2] = 0x98badcfe;
	stream->hash[3] = 0x10325476;
	stream->hash[4] = 0xc3d2e1f0;
	stream->buff_len = 0;
	stream->total_len = 0;
	ft_bzero(stream->buffer, 64);
}

void			sha1_stream_end(t_sha1_stream *stream)
{
	size_t	bits_len;

	ft_bzero(stream->buffer + stream->buff_len, 64 - stream->buff_len);
	stream->buffer[(int)stream->buff_len] |= 1 << 7;
	bits_len = (stream->total_len + stream->buff_len) * 8;
	if (stream->buff_len >= 56)
	{
		sha1_words(stream->hash, (unsigned int*)stream->buffer);
		stream->buff_len = 0;
		ft_bzero(stream->buffer, 64);
	}
	ft_memcpy(stream->buffer + 56, &bits_len, 8);
	sha1_words(stream->hash, (unsigned int*)stream->buffer);
}
