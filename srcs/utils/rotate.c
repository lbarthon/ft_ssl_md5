/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarthon <lbarthon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 17:02:21 by lbarthon          #+#    #+#             */
/*   Updated: 2020/03/05 17:09:34 by lbarthon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	rotateleft(unsigned int n, unsigned int s)
{
	return (((n) << s) | ((n) >> (sizeof(n) * 8 - s)));
}

unsigned int	rotateright(unsigned int n, unsigned int s)
{
	return (((n) >> s) | ((n) << (sizeof(n) * 8 - s)));
}
