/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuang <yhuang@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/15 01:09:37 by yhuang            #+#    #+#             */
/*   Updated: 2018/07/17 00:35:29 by yhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		mouse_move_hook(int x, int y, t_magic *m)
{
	if (m->type == 1)
	{
		m->c_re = (x / (WIN_WIDTH / 2.0)) - 1.0;
		m->c_im = (y / (WIN_HEIGHT / 2.0)) - 1.0;
		julia(m);
	}
	return (0);
}

int		effect(int key, t_magic *m)
{
	if (key == 53)
	{
		free_memory(m);
		exit(0);
	}
	if (key == 124)
		m->move_x -= 0.05;
	if (key == 123)
		m->move_x += 0.05;
	if (key == 126)
		m->move_y += 0.05;
	if (key == 125)
		m->move_y -= 0.05;
	if (key == 15)
		m->zoom *= 1.05;
	if (key == 11)
		m->zoom *= 0.99;
	return (0);
}

int		hook_keydown(int key, t_magic *m)
{
	t_canter	c;

	c.len = WIN_WIDTH - 20;
	c.x = 10;
	c.y = 10;
	c.m = m;
	effect(key, m);
	if (m->type == 1)
		julia(m);
	if (m->type == 2)
		mandelbrot(m);
	if (m->type == 4)
		tricorn(m);
	if (m->type == 5)
		burningship(m);
	if (m->type == 3)
	{
		mlx_clear_window(m->mlx, m->win);
		canter(c);
	}
	return (0);
}

void	butt(int button, t_magic *m)
{
	if (button == 5)
		m->zoom *= 1.05;
	if (button == 4)
		m->zoom *= 0.99;
	if (m->type == 1)
		julia(m);
	if (m->type == 2)
		mandelbrot(m);
	if (m->type == 4)
		tricorn(m);
	if (m->type == 5)
		burningship(m);
}

int		mouse_scroll_hook(int button, int x, int y, t_magic *m)
{
	t_canter	c;

	(void)x;
	(void)y;
	c.len = WIN_WIDTH - 20;
	c.x = 10;
	c.y = 10;
	c.m = m;
	if (m->type == 3)
	{
		mlx_clear_window(m->mlx, m->win);
		canter(c);
	}
	butt(button, m);
	return (0);
}
