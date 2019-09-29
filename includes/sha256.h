/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha256.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarthon <lbarthon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 13:26:55 by lbarthon          #+#    #+#             */
/*   Updated: 2019/09/29 13:28:05 by lbarthon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHA256_H
# define SHA256_H

# include "ft_ssl.h"

# define RR ROTATERIGHT

# define SHA2_HASH_CH(x, y, z) ((x & y) ^ (~x & z))
# define SHA2_HASH_MAJ(x, y, z) ((x & y) ^ (x & z) ^ (y & z))
# define SHA2_HASH_BSIG0(x) ((RR(x, 2)) ^ (RR(x, 13)) ^ (RR(x, 22)))
# define SHA2_HASH_BSIG1(x) ((RR(x, 6)) ^ (RR(x, 11)) ^ (RR(x, 25)))
# define SHA2_HASH_SSIG0(x) ((RR(x, 7)) ^ (RR(x, 18)) ^ ((x) >> 3))
# define SHA2_HASH_SSIG1(x) ((RR(x, 17)) ^ (RR(x, 19)) ^ ((x) >> 10))

#endif
