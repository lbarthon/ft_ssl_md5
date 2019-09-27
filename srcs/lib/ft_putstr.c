/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarthon <lbarthon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 11:18:47 by lbarthon          #+#    #+#             */
/*   Updated: 2019/09/15 11:38:21 by lbarthon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_strlen(char const *str)
{
	int i;

	i = 0;
	if (str)
		while (str[i])
			i++;
	return (i);
}

void	ft_putstr_fd(char const *str, int fd)
{
	write(fd, str, ft_strlen(str));
}

void	ft_putstr(char const *str)
{
	ft_putstr_fd(str, 1);
}

void	ft_putendl_fd(char const *str, int fd)
{
	ft_putstr_fd(str, fd);
	write(fd, "\n", 1);
}

void	ft_putendl(char const *str)
{
	ft_putendl_fd(str, 1);
}
