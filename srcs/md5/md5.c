/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarthon <lbarthon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 10:40:55 by lbarthon          #+#    #+#             */
/*   Updated: 2019/09/28 14:37:29 by lbarthon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"
#include "ft_ssl.h"
#include <stdlib.h>
#include <stdio.h>

static int		*g_k = (int[]) {
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
static int		*g_r = (int[]) {
	7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17, 22,
	5, 9, 14, 20, 5, 9, 14, 20, 5, 9, 14, 20, 5, 9, 14, 20,
	4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23,
	6, 10, 15, 21, 6, 10, 15, 21, 6, 10, 15, 21, 6, 10, 15, 21};

void			exec_md5(char flags, int i, int ac, char **av)
{
	char	*piped_content;
	char	ret[33];

	(void)flags;
	(void)av;
	piped_content = ft_get_stdin(i == ac || ft_has_flag(flags, 'p'));
	if (piped_content != NULL)
	{
		ft_md5((unsigned char *)piped_content, ft_strlen(piped_content), ret);
		ft_display_md5(flags, ret);
	}
	while (i < ac)
	{
		ft_md5((unsigned char *)av[i], ft_strlen(av[i]), ret);
		ft_display_md5(flags, ret);
		i++;
	}
}

void			ft_md5(unsigned char *str, int len, char ret[33])
{
	unsigned char	*msg;
	int				*r;
	int				*h;
	int				offset;

	h = (int[]) {0x67452301, 0xefcdab89, 0x98badcfe, 0x10325476};
	msg = ft_prepare_msg(str, len);
	len = ((((len + 8) / 64) + 1) * 64) - 8;
	offset = 0;
	while (offset < len)
	{
		ft_main_loop(h, (unsigned int *)(msg + offset));
		offset += 512 / 8;
	}
	ft_get_ret(h, ret);
}

void			ft_get_ret(int *h, char ret[33])
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

void			*ft_prepare_msg(unsigned char *str, int len)
{
	unsigned char	*msg;
	int				new_len;
	size_t			bits_len;

	new_len = ((((len + 8) / 64) + 1) * 64) - 8;
	msg = malloc(new_len + 64);
	ft_bzero(msg, new_len + 64);
	ft_memcpy(msg, str, len);
	msg[len] = 128;
	bits_len = len * 8;
	ft_memcpy(msg + new_len, &bits_len, 4);
	ft_memcpy(msg + new_len - 4, (unsigned char *)&bits_len + 4, 4);
	return (msg);
}

void			ft_main_loop(int *h, unsigned int *w)
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
