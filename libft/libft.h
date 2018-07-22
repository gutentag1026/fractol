/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuang <yhuang@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/01 23:31:28 by yhuang            #+#    #+#             */
/*   Updated: 2018/07/08 02:04:51 by yhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>

void				ft_strdel(char **as);
size_t				ft_strlen(const char *s);
void				ft_bzero(void *s, size_t n);
void				*ft_memset(void *b, int c, size_t len);
char				*ft_strchr(const char *s, int c);
char				*ft_strdup(const char *s1);
char				*ft_strjoin(char const *s1, char const *s2);
void				*ft_memalloc(size_t size);
int					ft_iswspace(int c);
void				ft_putstr_fd(char const *s, int fd);
char				*ft_str_tolower(char *str);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_isupper(int c);
void				ft_putstr(char const *s);
#endif
