/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarthon <lbarthon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 11:19:03 by lbarthon          #+#    #+#             */
/*   Updated: 2019/09/28 11:19:23 by lbarthon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_get_f(unsigned int *t, int i)
{
	if (i < 16)
		return (t[1] & t[2]) | ((~t[1]) & t[3]);
	if (i < 32)
		return (t[3] & t[1]) | ((~t[3]) & t[2]);
	if (i < 48)
		return (t[1] ^ t[2] ^ t[3]);
	return (t[2] ^ (t[1] | (~t[3])));
}

unsigned int	ft_get_g(int i)
{
	if (i < 16)
		return (i);
	if (i < 32)
		return ((5 * i + 1) % 16);
	if (i < 48)
		return ((3 * i + 5) % 16);
	return ((7 * i) % 16);
}
