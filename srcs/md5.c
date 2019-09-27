/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarthon <lbarthon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 10:40:55 by lbarthon          #+#    #+#             */
/*   Updated: 2019/09/27 16:14:55 by lbarthon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"
#include <stdlib.h>
#include <stdio.h>

char	*md5(unsigned char *str, int len);
char	*ft_get_ret(int *h);

void	exec_md5(char flags, int i, int ac, char **av)
{
	char	*piped_content;

	(void)flags;
	(void)av;
	piped_content = ft_get_stdin(i == ac);
	printf("Piped content:\n%s", piped_content);
	md5((unsigned char *) piped_content, ft_strlen(piped_content));
}

char	*md5(unsigned char *str, int len)
{
	int *r;
	int *k;
	int *h;

	r = (int[]) {
		7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17, 22,
			5,  9, 14, 20, 5,  9, 14, 20, 5,  9, 14, 20, 5,  9, 14, 20,
			4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23,
			6, 10, 15, 21, 6, 10, 15, 21, 6, 10, 15, 21, 6, 10, 15, 21};
	k = (int[]) {
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

	h = (int[]) {0x67452301, 0xefcdab89, 0x98badcfe, 0x10325476};
	int new_len = ((((len + 8) / 64) + 1) * 64) - 8;

	msg = malloc(new_len + 64);
	ft_bzero(msg);
	ft_memcpy(msg, str, len);

	msg[len] = 128;
	int bits_len = len * 8;
	ft_memcpy(msg + new_len, &bits_len);

	int offset = 0;
	while (offset < new_len)
	{
		unsigned int *w = (unsigned int *) (msg + offset);

		unsigned int a = h[0];
		unsigned int b = h[1];
		unsigned int c = h[2];
		unsigned int d = h[3];

		int i = 0;
		while (i < 64)
		{
			unsigned int f, g;
			if (i < 16)
			{
				f = (b & c) | ((~b) & d);
				g = i;
			}
			else if (i < 32)
			{
				f = (d & b) | ((~d) & c);
				g = (5 * i + 1) % 16;
			}
			else if (i < 48)
			{
				f = b ^ c ^ d;
				g = (3 * i + 5) % 16;
			}
			else
			{
				f = c ^ (b | (~d));
				g = (7 * i) % 16
			}
			f += a + k[i] + w[g];
			a = d;
			d = c;
			c = b;
			b = b + (((f) << (r[i])) | ((f) >> (32 - (r[i]))));

			i++;
		}
		h[0] += a;
		h[1] += b;
		h[2] += c;
		h[3] += d;

		offset += 512 / 8;
	}

	return (NULL);
}
