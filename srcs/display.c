/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarthon <lbarthon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 14:18:38 by lbarthon          #+#    #+#             */
/*   Updated: 2020/03/05 16:04:16 by lbarthon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "printf.h"
#include "ft_ssl.h"

void	hash_display_str(t_hash *hash, char *ret, char *str, char flags)
{
	if (ft_has_flag(flags, 'q'))
		ft_printf("%s\n", ret);
	else if (ft_has_flag(flags, 'r'))
		ft_printf("%s %s\n", ret, str);
	else if (str)
		ft_printf("%s (\"%s\") = %s\n", hash->display_name, str, ret);
	else
		ft_printf("%s\n", ret);
}

void	hash_display_file(t_hash *hash, char *ret, char *str, char flags)
{
	if (ft_has_flag(flags, 'q'))
		ft_printf("%s\n", ret);
	else if (ft_has_flag(flags, 'r'))
		ft_printf("%s %s\n", ret, str);
	else if (str)
		ft_printf("%s (%s) = %s\n", hash->display_name, str, ret);
	else
		ft_printf("%s\n", ret);
}
