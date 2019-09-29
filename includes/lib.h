/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarthon <lbarthon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 11:24:28 by lbarthon          #+#    #+#             */
/*   Updated: 2019/09/29 13:21:47 by lbarthon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_H
# define LIB_H

/*
** Includes for file ft_putstr.c
*/
int		ft_strlen(char const *str);
void	ft_putstr(char const *str);
void	ft_putstr_fd(char const *str, int fd);
void	ft_putendl(char const *str);
void	ft_putendl_fd(char const *str, int fd);

/*
** Includes for file ft_strcmp.c
*/
int		ft_strcmp(const char *s1, const char *s2);
int		ft_startswith(const char *str, const char *start);
char	*ft_strchr(const char *str, int c);

/*
** Includes for file ft_strnew.c
*/
char	*ft_strnew(int size);
void	*ft_memcpy(void *dest, const void *src, int n);
void	ft_bzero(void *s, int n);

/*
** Includes for file files.c
*/
char	*ft_get_stdin(char force);
char	*ft_read(const int fd);
void	*ft_realloc(void *ptr, int size, int newsize);
char	*ft_strcat(char *dest, const char *src);

/*
** Includes for file ft_memrev.c
*/
void	ft_memrev(void *ptr, int size);
#endif
