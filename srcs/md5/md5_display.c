// INSERT HEADER

#include "lib.h"
#include "ft_ssl.h"

void			ft_md5_display(char ret[33], char flags, char *str)
{
	if (ft_has_flag(flags, 'q'))
		ft_putendl(ret);
	else if (ft_has_flag(flags, 'r'))
	{
		ft_putstr(ret);
		ft_putstr(" ");
		ft_putendl(str);
	}
	else if (str)
	{
		ft_putstr("MD5(");
		ft_putstr(str);
		ft_putstr(") = ");
		ft_putendl(ret);
	}
	else
		ft_putendl(ret);
}
