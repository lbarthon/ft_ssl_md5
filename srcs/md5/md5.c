/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarthon <lbarthon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 10:40:55 by lbarthon          #+#    #+#             */
/*   Updated: 2019/09/28 18:02:17 by lbarthon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"
#include "ft_ssl.h"
#include <stdlib.h>
#include <unistd.h>

void			exec_md5(char flags, int i, int ac, char **av)
{
	char	*piped_content;

	(void)flags;
	(void)av;
	(void)ac;
	(void)i;
	ft_md5_stream(0);
}

void			ft_print_ret(unsigned int *h)
{
	unsigned char	*p;
	char			ret[33];
	int				i;
	int				j;

	i = -1;
	while (++i < 4)
	{
		p = (unsigned char *)&h[i];
		j = -1;
		while (++j < 4)
		{
			ret[i * 8 + j * 2] = p[j] / 16;
			ret[i * 8 + j * 2 + 1] = p[j] % 16;
		}
	}
	i = -1;
	while (++i < 32)
		ret[i] += ret[i] < 10 ? '0' : 'a' - 10;
	ret[32] = '\0';
	ft_putendl(ret);
}

void			ft_md5_stream(int fd)
{
	t_md5_stream	stream;
	char			buff[2048];
	int				r;
	int				l;
	int				offset;

	ft_md5_stream_init(&stream);
	while ((r = read(fd, buff, 2048)))
	{
		offset = ft_md5_check_residual(&stream, buff, r);
		while (r - offset >= 64)
		{
			ft_md5_words(stream.hash, (unsigned int *)(buff + offset)); 
			stream.total_len += 64;
			offset += 64;
		}
		if (r - offset != 0)
		{
			ft_memcpy(stream.buffer, buff + offset, r - offset);
			stream.buff_len = r - offset;
		}
	}
	ft_md5_stream_end(&stream);
	ft_print_ret(stream.hash);
}

int		ft_md5_check_residual(t_md5_stream *stream, char buff[2048], int r)
{
	char	l;

	if (stream->buff_len == 0)
		return (0);
	l = stream->buff_len + r >= 64 ? 64 - stream->buff_len : r;
	ft_memcpy(stream->buffer + stream->buff_len, buff, l);
	stream->buff_len += l;
	if (stream->buff_len == 64)
	{
		ft_md5_words(stream->hash, (unsigned int*)stream->buffer);
		stream->total_len += 64;
		stream->buff_len = 0;
	}
	return (l);
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
	stream->buffer[stream->buff_len] |= 1 << 7;
	bits_len = (stream->total_len + stream->buff_len) * 8;
	if (stream->buff_len > 56)
	{
		ft_md5_words(stream->hash, (unsigned int*)stream->buffer);
		stream->buff_len = 0;
		ft_bzero(stream->buffer, 64);
	}
	ft_memcpy(stream->buffer + 56, &bits_len, 8);
	ft_md5_words(stream->hash, (unsigned int*)stream->buffer);
}

void			ft_md5_str(unsigned char *str, int len, char ret[33])
{
	unsigned char	*msg;
	unsigned int	*h;
	int				*r;
	int				offset;

	h = (unsigned int[]) {0x67452301, 0xefcdab89, 0x98badcfe, 0x10325476};
	msg = ft_prepare_msg(str, len);
	len = ((((len + 8) / 64) + 1) * 64) - 8;
	offset = 0;
	while (offset < len)
	{
		ft_md5_words(h, (unsigned int *)(msg + offset));
		offset += 64;
	}
	ft_print_ret(h);
}
