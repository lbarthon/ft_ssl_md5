/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarthon <lbarthon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 10:24:59 by lbarthon          #+#    #+#             */
/*   Updated: 2019/09/29 11:35:14 by lbarthon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int		ft_strcmp(const char *s1, const char *s2)
{
	int i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int		ft_startswith(const char *str, const char *start)
{
	int i;

	i = -1;
	while (start[++i])
		if (!str[i] || str[i] != start[i])
			return (0);
	return (1);
}

char	*ft_strchr(const char *str, int c)
{
	int i;

	i = -1;
	while (str[++i])
		if (str[i] == c)
			return ((char*)str + i);
	if (str[i] == '\0' && c == '\0')
		return ((char*)str + i);
	return (NULL);
}
