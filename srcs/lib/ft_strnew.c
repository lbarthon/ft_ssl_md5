/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarthon <lbarthon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 15:33:56 by lbarthon          #+#    #+#             */
/*   Updated: 2019/09/26 13:43:36 by lbarthon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

char	*ft_strnew(int size)
{
	char	*str;
	int		i;

	if (!(str = (char*)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	i = 0;
	while (i < (size + 1))
		*(str + i++) = '\0';
	*(str + i) = '\0';
	return (str);
}

void	*ft_memcpy(void *dest, const void *src, int n)
{
	const char	*ptr_src;
	char		*ptr_dest;

	ptr_src = (const char*)src;
	ptr_dest = (char*)dest;
	while (n-- > 0)
		*(ptr_dest + n) = *(ptr_src + n);
	return (ptr_dest);
}

void	ft_bzero(void *s, int n)
{
	char	*ptr;
	int		i;

	ptr = (char*)s;
	i = 0;
	while (i < n)
		*(ptr + i++) = '\0';
}
