/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarthon <lbarthon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 11:50:00 by lbarthon          #+#    #+#             */
/*   Updated: 2019/09/28 12:13:32 by lbarthon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

/*
** This function call is needed in order to return null if it's not waiting
** for an input in stdin.
*/

char	*ft_get_stdin(char force)
{
	if (!isatty(0) || force)
		return (ft_read(0));
	return (NULL);
}

char	*ft_read(const int fd)
{
	char	*ret;
	char	buff[1025];
	int		ret_len;
	int		r;

	if (fd < 0 || read(fd, buff, 0) < 0)
		return (NULL);
	ret = NULL;
	ret_len = 0;
	while ((r = read(fd, buff, 1024)))
	{
		buff[r] = '\0';
		if (!(ret = ft_realloc(ret, ret_len, ret_len + r)))
			return (NULL);
		ret = ft_strcat(ret, buff);
		ret_len += r;
		if (r < 1024 && buff[r - 1] == EOF)
			break ;
	}
	return (ret);
}

void	*ft_realloc(void *ptr, int size, int newsize)
{
	char	*str;
	char	*new;
	int		i;

	str = (char*)ptr;
	if (!(new = (char*)malloc(sizeof(char) * newsize + 1)))
	{
		if (ptr && size != 0)
			free(ptr);
		return (NULL);
	}
	i = -1;
	while (++i < size)
		*(new + i) = *(str + i);
	while (i < newsize)
		*(new + i++) = '\0';
	if (ptr && size != 0)
		free(ptr);
	return (new);
}

char	*ft_strcat(char *dest, const char *src)
{
	int i;
	int j;

	i = ft_strlen(dest);
	j = 0;
	while (src[j])
		dest[i++] = src[j++];
	dest[i] = '\0';
	return (dest);
}
