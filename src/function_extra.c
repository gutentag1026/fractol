/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_extra.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuang <yhuang@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 17:49:01 by yhuang            #+#    #+#             */
/*   Updated: 2018/07/16 23:49:38 by yhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			canter_color(int i)
{
	if (i >= 0)
		i = 255 << 16 | abs(i - 750) << 8 | 0;
	return (i);
}

void		line(float x, float y, float x1, t_magic *m)
{
	while (x < x1)
	{
		mlx_pixel_put(m->mlx, m->win, x, y, canter_color(x));
		x++;
	}
}

void		draw(t_magic *m)
{
	if (m->type == 1)
	{
		alloc_threads(m);
		julia(m);
	}
	else if (m->type == 2)
	{
		alloc_threads(m);
		mandelbrot(m);
	}
	else if (m->type == 4)
	{
		alloc_threads(m);
		tricorn(m);
	}
	else if (m->type == 5)
	{
		alloc_threads(m);
		burningship(m);
	}
}

void		type(t_magic *m)
{
	t_canter	c;

	draw(m);
	if (m->type == 3)
	{
		c.len = WIN_WIDTH - 20;
		c.x = 10;
		c.y = 10;
		c.m = m;
		canter(c);
	}
}

void		convert_m(t_thread_data *t)
{
	t->old_im = 0;
	t->old_re = t->old_im;
	t->new_im = t->old_re;
	t->new_re = t->new_im;
}
