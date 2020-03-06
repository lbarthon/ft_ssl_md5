/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha1_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarthon <lbarthon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 11:09:53 by lbarthon          #+#    #+#             */
/*   Updated: 2020/03/06 13:49:48 by lbarthon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"
#include "libft.h"
#include <stdlib.h>

static const unsigned int	g_k[80] = {
	0x5a827999, 0x5a827999, 0x5a827999, 0x5a827999,
	0x5a827999, 0x5a827999, 0x5a827999, 0x5a827999,
	0x5a827999, 0x5a827999, 0x5a827999, 0x5a827999,
	0x5a827999, 0x5a827999, 0x5a827999, 0x5a827999,
	0x5a827999, 0x5a827999, 0x5a827999, 0x5a827999,
	0x6ed9eba1, 0x6ed9eba1, 0x6ed9eba1, 0x6ed9eba1,
	0x6ed9eba1, 0x6ed9eba1, 0x6ed9eba1, 0x6ed9eba1,
	0x6ed9eba1, 0x6ed9eba1, 0x6ed9eba1, 0x6ed9eba1,
	0x6ed9eba1, 0x6ed9eba1, 0x6ed9eba1, 0x6ed9eba1,
	0x6ed9eba1, 0x6ed9eba1, 0x6ed9eba1, 0x6ed9eba1,
	0x8f1bbcdc, 0x8f1bbcdc, 0x8f1bbcdc, 0x8f1bbcdc,
	0x8f1bbcdc, 0x8f1bbcdc, 0x8f1bbcdc, 0x8f1bbcdc,
	0x8f1bbcdc, 0x8f1bbcdc, 0x8f1bbcdc, 0x8f1bbcdc,
	0x8f1bbcdc, 0x8f1bbcdc, 0x8f1bbcdc, 0x8f1bbcdc,
	0x8f1bbcdc, 0x8f1bbcdc, 0x8f1bbcdc, 0x8f1bbcdc,
	0xca62c1d6, 0xca62c1d6, 0xca62c1d6, 0xca62c1d6,
	0xca62c1d6, 0xca62c1d6, 0xca62c1d6, 0xca62c1d6,
	0xca62c1d6, 0xca62c1d6, 0xca62c1d6, 0xca62c1d6,
	0xca62c1d6, 0xca62c1d6, 0xca62c1d6, 0xca62c1d6,
	0xca62c1d6, 0xca62c1d6, 0xca62c1d6, 0xca62c1d6
};

static void			sha1_prep(unsigned int w[64], unsigned int *buff)
{
	int	i;

	i = 0;
	while (i < 16)
	{
		w[i] = buff[i];
		ft_memrev(&w[i], 4);
		i++;
	}
	while (i < 80)
	{
		w[i] = rotateleft(w[i - 3] ^ w[i - 8] ^ w[i - 14] ^ w[i - 16], 1);
		i++;
	}
}

static unsigned int		get_f(unsigned int *t, int i)
{
	if (i < 20)
		return (t[1] & t[2]) | ((~t[1]) & t[3]);
	if (i < 40)
		return t[1] ^ t[2] ^ t[3];
	if (i < 60)
		return (t[1] & t[2]) | (t[1] & t[3]) | (t[2] & t[3]);
	return t[1] ^ t[2] ^ t[3];
}

void					sha1_words(unsigned int *h, unsigned int *buff)
{
	unsigned int	w[80];
	unsigned int	t[5];
	unsigned int	f;
	unsigned int	temp;
	int				i;

	sha1_prep(w, buff);
	i = -1;
	while (++i < 5)
		t[i] = h[i];
	i = -1;
	while (++i < 80)
	{
		f = get_f(t, i);
		temp = rotateleft(t[0], 5) + f + t[4] + g_k[i] + w[i];
		t[4] = t[3];
		t[3] = t[2];
		t[2] = rotateleft(t[1], 30);
		t[1] = t[0];
		t[0] = temp;
	}
	i = -1;
	while (++i < 5)
		h[i] += t[i];
}

void					sha1_ret(unsigned int *h, char ret[41])
{
	unsigned char	*p;
	int				j;
	int				i;

	i = -1;
	while (++i < 5)
	{
		p = (unsigned char *)&h[i];
		ft_memrev(p, 4);
		j = -1;
		while (++j < 4)
		{
			ret[i * 8 + j * 2] = p[j] / 16;
			ret[i * 8 + j * 2 + 1] = p[j] % 16;
		}
	}
	i = -1;
	while (++i < 40)
		ret[i] += ret[i] < 10 ? '0' : 'a' - 10;
	ret[i] = 0;
}

int						sha1_check_residual(t_sha1_stream *stream, char *buff
		, int r)
{
	char	l;

	if (stream->buff_len == 0)
		return (0);
	l = stream->buff_len + r >= 64 ? 64 - stream->buff_len : r;
	ft_memcpy(stream->buffer + stream->buff_len, buff, l);
	stream->buff_len += l;
	if (stream->buff_len == 64)
	{
		sha1_words(stream->hash, (unsigned int *)stream->buffer);
		stream->total_len += 64;
		stream->buff_len = 0;
	}
	return (l);
}
