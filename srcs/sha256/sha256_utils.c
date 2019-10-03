/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha256_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarthon <lbarthon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 12:58:49 by lbarthon          #+#    #+#             */
/*   Updated: 2019/09/29 16:40:10 by lbarthon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"
#include "ft_ssl.h"
#include "sha256.h"
#include <stdlib.h>
#include <stdio.h>

static int			*g_k = (int[]) {
	0x428a2f98, 0x71374491, 0xb5c0fbcf, 0xe9b5dba5,
	0x3956c25b, 0x59f111f1, 0x923f82a4, 0xab1c5ed5,
	0xd807aa98, 0x12835b01, 0x243185be, 0x550c7dc3,
	0x72be5d74, 0x80deb1fe, 0x9bdc06a7, 0xc19bf174,
	0xe49b69c1, 0xefbe4786, 0x0fc19dc6, 0x240ca1cc,
	0x2de92c6f, 0x4a7484aa, 0x5cb0a9dc, 0x76f988da,
	0x983e5152, 0xa831c66d, 0xb00327c8, 0xbf597fc7,
	0xc6e00bf3, 0xd5a79147, 0x06ca6351, 0x14292967,
	0x27b70a85, 0x2e1b2138, 0x4d2c6dfc, 0x53380d13,
	0x650a7354, 0x766a0abb, 0x81c2c92e, 0x92722c85,
	0xa2bfe8a1, 0xa81a664b, 0xc24b8b70, 0xc76c51a3,
	0xd192e819, 0xd6990624, 0xf40e3585, 0x106aa070,
	0x19a4c116, 0x1e376c08, 0x2748774c, 0x34b0bcb5,
	0x391c0cb3, 0x4ed8aa4a, 0x5b9cca4f, 0x682e6ff3,
	0x748f82ee, 0x78a5636f, 0x84c87814, 0x8cc70208,
	0x90befffa, 0xa4506ceb, 0xbef9a3f7, 0xc67178f2};

static void			ft_sha256_rev(unsigned int w[64], unsigned int *buff)
{
	int	i;

	i = 0;
	while (i < 16)
	{
		w[i] = buff[i];
		ft_memrev(&w[i++], 4);
	}
	while (i < 64)
	{
		w[i] = SHA2_HASH_SSIG1(w[i - 2]) + w[i - 7]
			+ SHA2_HASH_SSIG0(w[i - 15]) + w[i - 16];
		i++;
	}
}

void				ft_sha256_words(unsigned int *h, unsigned int *buff)
{
	unsigned int	w[64];
	unsigned int	t[8];
	unsigned int	x;
	unsigned int	y;
	int				i;

	ft_sha256_rev(w, buff);
	i = -1;
	while (++i < 8)
		t[i] = h[i];
	i = -1;
	while (++i < 64)
	{
		x = t[7] + SHA2_HASH_BSIG1(t[4]) + SHA2_HASH_CH(t[4], t[5], t[6])
			+ g_k[i] + w[i];
		y = SHA2_HASH_BSIG0(t[0]) + SHA2_HASH_MAJ(t[0], t[1], t[2]);
		t[7] = t[6];
		t[6] = t[5];
		t[5] = t[4];
		t[4] = t[3] + x;
		t[3] = t[2];
		t[2] = t[1];
		t[1] = t[0];
		t[0] = x + y;
	}
	i = -1;
	while (++i < 8)
		h[i] += t[i];
}

void				ft_sha256_ret(unsigned int *h, char ret[65])
{
	unsigned char	*p;
	int				i;
	int				j;

	i = -1;
	while (++i < 8)
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
	while (++i < 64)
		ret[i] += ret[i] < 10 ? '0' : 'a' - 10;
	ret[i] = '\0';
}

int					ft_sha256_check_residual(t_sha256_stream *stream
		, char buff[2049], int r)
{
	char	l;

	if (stream->buff_len == 0)
		return (0);
	l = stream->buff_len + r >= 64 ? 64 - stream->buff_len : r;
	ft_memcpy(stream->buffer + stream->buff_len, buff, l);
	stream->buff_len += l;
	if (stream->buff_len == 64)
	{
		ft_sha256_words(stream->hash, (unsigned int *)stream->buffer);
		stream->total_len += 64;
		stream->buff_len = 0;
	}
	return (l);
}
