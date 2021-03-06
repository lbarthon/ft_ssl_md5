/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha256.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarthon <lbarthon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 13:26:55 by lbarthon          #+#    #+#             */
/*   Updated: 2020/03/05 17:18:40 by lbarthon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHA256_H
# define SHA256_H

# include "ft_ssl.h"

unsigned int	sha2_hash_ch(unsigned int x, unsigned int y, unsigned int z);
unsigned int	sha2_hash_maj(unsigned int x, unsigned int y, unsigned int z);
unsigned int	sha2_hash_bsig0(unsigned int x);
unsigned int	sha2_hash_bsig1(unsigned int x);
unsigned int	sha2_hash_ssig0(unsigned int x);
unsigned int	sha2_hash_ssig1(unsigned int x);

#endif
