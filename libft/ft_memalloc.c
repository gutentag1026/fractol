/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuang <yhuang@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/02 20:39:32 by yhuang            #+#    #+#             */
/*   Updated: 2018/04/02 20:40:34 by yhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	unsigned char		*p;

	p = (unsigned char*)malloc(sizeof(p) * size);
	if (p == NULL)
		return (NULL);
	while (size--)
	{
		p[size] = 0;
	}
	return (p);
}
