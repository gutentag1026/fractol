/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norm_extra.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuang <yhuang@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 23:58:11 by yhuang            #+#    #+#             */
/*   Updated: 2018/07/17 00:24:48 by yhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	alloc_threads(t_magic *m)
{
	int		i;

	m->t = (t_thread_data *)malloc(sizeof(t_thread_data) * WIN_HEIGHT);
	if (!m->t)
	{
		ft_putstr("error: failed to malloc threads\n");
		exit(0);
	}
	i = -1;
	while (++i < WIN_HEIGHT)
	{
		m->t[i].m = m;
		m->t[i].y = i;
	}
}

void	free_memory(t_magic *m)
{
	int i;

	i = -1;
	free(m->t);
	while (++i < WIN_HEIGHT)
		free(m->pixel[i]);
	free(m->pixel);
}

int		get_color(int i)
{
	if (i >= 250)
		i = (i - 250) << 16 | (i - 250) << 8 | (i - 250);
	else if (i >= 20 && i < 250)
		i = 255 << 16 | (int)((i - 20) * (255.0 / 230.0)) << 8 | i;
	else if (i >= 0 && i < 20)
		i = 0 << 16 | (int)(i * (255.0 / 20.0)) | 255;
	return (i);
}

int		fetch_color(int i)
{
	if (i >= 230)
		i = 255 << 16 | (int)((i - 230) * (255.0 / 25.0)) << 8 | 0;
	else if (i >= 200 && i < 230)
		i = (int)(i % 200 * (255.0 / 30.0)) << 16 | 255 << 8 | 0;
	else if (i >= 175 && i < 200)
		i = 0 << 16 | 255 << 8 | (int)(i % 175 * (255.0 / 25.0));
	else if (i >= 150 && i < 175)
		i = 0 << 16 | (int)(i % 150 * (255.0 / 25.0)) << 8 | 255;
	else if (i >= 125 && i < 150)
		i = (int)(i % 125 * (255.0 / 25.0)) << 16 | 0 << 8 | 255;
	else if (i >= 0 && i < 125)
		i = i << 0 | (i + 125) << 8 | (int)((i + 125) * 1.2);
	return (i);
}
