/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarthon <lbarthon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 13:20:43 by lbarthon          #+#    #+#             */
/*   Updated: 2019/09/29 13:44:05 by lbarthon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_memrev(void *ptr, int size)
{
	char	*str;
	char	tmp;
	int		i;

	str = (char *)ptr;
	i = 0;
	while (i < size / 2)
	{
		tmp = str[i];
		str[i] = str[size - i - 1];
		str[size - i - 1] = tmp;
		i++;
	}
}
