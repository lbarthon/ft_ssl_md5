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
#include "errors.h"
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

void			exec_md5(char flags, int i, int ac, char **av)
{
	char	ret[33];
	int		fd;
	int		j;

	j = i;
	if (!isatty(0) || ac == i)
	{
		ft_md5_stream(0, ret);
		ft_md5_display(ret, flags, NULL);
	}
	while (i < ac)
	{
		if (i == j && ft_has_flag(flags, 's'))
		{
			ft_md5_str((unsigned char *)av[i], ft_strlen(av[i]), ret);
			ft_md5_display(ret, flags, av[i]);
		}
		else if ((fd = open(av[i], O_RDONLY)) != -1)
		{
			ft_md5_stream(fd, ret);
			ft_md5_display(ret, flags, NULL);
		}
		else
			ft_not_found("md5", av[i]);
		i++;
	}
}

void			ft_md5_stream(int fd, char ret[33])
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
	ft_get_ret(stream.hash, ret);
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
	ft_get_ret(stream.hash, ret);
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
