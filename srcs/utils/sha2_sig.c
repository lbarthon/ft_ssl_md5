/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha2_sig.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarthon <lbarthon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 17:13:40 by lbarthon          #+#    #+#             */
/*   Updated: 2020/03/05 17:28:54 by lbarthon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

unsigned int	sha2_hash_bsig0(unsigned int x)
{
	return (rotateright(x, 2) ^ rotateright(x, 13) ^ rotateright(x, 22));
}

unsigned int	sha2_hash_bsig1(unsigned int x)
{
	return (rotateright(x, 6) ^ rotateright(x, 11) ^ rotateright(x, 25));
}

unsigned int	sha2_hash_ssig0(unsigned int x)
{
	return (rotateright(x, 7) ^ rotateright(x, 18) ^ (x >> 3));
}

unsigned int	sha2_hash_ssig1(unsigned int x)
{
	return (rotateright(x, 17) ^ rotateright(x, 19) ^ (x >> 10));
}
