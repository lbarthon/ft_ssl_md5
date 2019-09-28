/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarthon <lbarthon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 11:19:03 by lbarthon          #+#    #+#             */
/*   Updated: 2019/09/28 17:41:12 by lbarthon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"
#include "lib.h"
#include <stdlib.h>

static int			*g_k = (int[]) {
	0xd76aa478, 0xe8c7b756, 0x242070db, 0xc1bdceee,
	0xf57c0faf, 0x4787c62a, 0xa8304613, 0xfd469501,
	0x698098d8, 0x8b44f7af, 0xffff5bb1, 0x895cd7be,
	0x6b901122, 0xfd987193, 0xa679438e, 0x49b40821,
	0xf61e2562, 0xc040b340, 0x265e5a51, 0xe9b6c7aa,
	0xd62f105d, 0x02441453, 0xd8a1e681, 0xe7d3fbc8,
	0x21e1cde6, 0xc33707d6, 0xf4d50d87, 0x455a14ed,
	0xa9e3e905, 0xfcefa3f8, 0x676f02d9, 0x8d2a4c8a,
	0xfffa3942, 0x8771f681, 0x6d9d6122, 0xfde5380c,
	0xa4beea44, 0x4bdecfa9, 0xf6bb4b60, 0xbebfbc70,
	0x289b7ec6, 0xeaa127fa, 0xd4ef3085, 0x04881d05,
	0xd9d4d039, 0xe6db99e5, 0x1fa27cf8, 0xc4ac5665,
	0xf4292244, 0x432aff97, 0xab9423a7, 0xfc93a039,
	0x655b59c3, 0x8f0ccc92, 0xffeff47d, 0x85845dd1,
	0x6fa87e4f, 0xfe2ce6e0, 0xa3014314, 0x4e0811a1,
	0xf7537e82, 0xbd3af235, 0x2ad7d2bb, 0xeb86d391};
static int			*g_r = (int[]) {
	7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17, 22,
	5, 9, 14, 20, 5, 9, 14, 20, 5, 9, 14, 20, 5, 9, 14, 20,
	4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23,
	6, 10, 15, 21, 6, 10, 15, 21, 6, 10, 15, 21, 6, 10, 15, 21};

static unsigned int	ft_get_f(unsigned int *t, int i)
{
	if (i < 16)
		return (t[1] & t[2]) | ((~t[1]) & t[3]);
	if (i < 32)
		return (t[3] & t[1]) | ((~t[3]) & t[2]);
	if (i < 48)
		return (t[1] ^ t[2] ^ t[3]);
	return (t[2] ^ (t[1] | (~t[3])));
}

static unsigned int	ft_get_g(int i)
{
	if (i < 16)
		return (i);
	if (i < 32)
		return ((5 * i + 1) % 16);
	if (i < 48)
		return ((3 * i + 5) % 16);
	return ((7 * i) % 16);
}

void				ft_md5_words(unsigned int *h, unsigned int *w)
{
	unsigned int	t[4];
	unsigned int	f;
	unsigned int	g;
	int				i;

	t[0] = h[0];
	t[1] = h[1];
	t[2] = h[2];
	t[3] = h[3];
	i = -1;
	while (++i < 64)
	{
		f = ft_get_f(t, i);
		g = ft_get_g(i);
		f += t[0] + g_k[i] + w[g];
		t[0] = t[3];
		t[3] = t[2];
		t[2] = t[1];
		t[1] += ROTATELEFT(f, g_r[i]);
	}
	h[0] += t[0];
	h[1] += t[1];
	h[2] += t[2];
	h[3] += t[3];
}

void			ft_get_ret(unsigned int *h, char ret[33])
{
	unsigned char	*p;
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
