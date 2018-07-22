/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norm.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuang <yhuang@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 23:57:38 by yhuang            #+#    #+#             */
/*   Updated: 2018/07/17 00:18:13 by yhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		convert_m1(t_thread_data *t)
{
	t->old_re = t->new_re;
	t->old_im = t->new_im;
	t->new_re = t->old_re * t->old_re - t->old_im * t->old_im + t->pr;
	t->new_im = 2 * t->old_re * t->old_im + t->pi;
}

void		convert_m3(t_thread_data *t)
{
	t->old_re = t->new_re;
	t->old_im = t->new_im;
	t->new_re = t->old_re * t->old_re - t->old_im * t->old_im + t->pr;
	t->new_im = fabs(2 * t->old_re * t->old_im) + t->pi;
}

void		convert_m2(t_thread_data *t)
{
	t->old_re = t->new_re;
	t->old_im = t->new_im;
	t->new_re = t->old_re * t->old_re - t->old_im * t->old_im + t->pr;
	t->new_im = 2 * -(t->old_re * t->old_im) + t->pi;
}

void		burningship(t_magic *m)
{
	int		i;
	int		x;
	int		y;

	i = -1;
	y = 0;
	while (++i < WIN_HEIGHT)
		pthread_create(&(m->t[i].tid), NULL, \
				burningship_row, (void *)(m->t + i));
	while (--i >= 0)
		pthread_join(m->t[i].tid, NULL);
	while (y < WIN_WIDTH)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			mlx_pixel_put(m->mlx, m->win, x, y, m->pixel[y][x]);
			x++;
		}
		y++;
	}
}
