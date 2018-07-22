/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuang <yhuang@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/15 00:10:25 by yhuang            #+#    #+#             */
/*   Updated: 2018/07/17 00:32:05 by yhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		useage(void)
{
	ft_putstr("usage: ./fractol [julia/mandelbrot/");
	ft_putstr("canter/tricorn/burningship]\n");
	exit(0);
}

int			compare(char *input)
{
	if (!(ft_strcmp(ft_str_tolower(input), "julia")) \
	|| !(ft_strcmp(ft_str_tolower(input), "mandelbrot")) \
	|| !(ft_strcmp(ft_str_tolower(input), "canter")) \
	|| !(ft_strcmp(ft_str_tolower(input), "tricorn")) \
	|| !(ft_strcmp(ft_str_tolower(input), "burningship")))
	{
		if (!(ft_strcmp(ft_str_tolower(input), "julia")))
			return (1);
		else if (!(ft_strcmp(ft_str_tolower(input), "mandelbrot")))
			return (2);
		else if (!(ft_strcmp(ft_str_tolower(input), "canter")))
			return (3);
		else if (!(ft_strcmp(ft_str_tolower(input), "tricorn")))
			return (4);
		else if (!(ft_strcmp(ft_str_tolower(input), "burningship")))
			return (5);
	}
	return (0);
}

void		convert_j(t_thread_data *t)
{
	t->old_re = t->new_re;
	t->old_im = t->new_im;
	t->new_re = t->old_re * t->old_re - \
	t->old_im * t->old_im + t->m->c_re;
	t->new_im = 2 * t->old_re * t->old_im + \
	t->m->c_im;
}

void		put_alert(t_magic *m)
{
	if (m->type == 1 || m->type == 2 || m->type == 4 || m->type == 5)
	{
		mlx_string_put(m->mlx, m->win, 10, 10, \
				0xffffff, "esc: exit");
		mlx_string_put(m->mlx, m->win, 10, 30, \
				0xffffff, "arrow up -> move up; arrow down -> move down");
		mlx_string_put(m->mlx, m->win, 10, 50, \
				0xffffff, "arrow left -> move left; arrow right -> move right");
		mlx_string_put(m->mlx, m->win, 10, 70, \
				0xffffff, "press R -> zoom in");
		mlx_string_put(m->mlx, m->win, 10, 90, \
				0xffffff, "press B -> zoom out");
	}
}

void		mlx(t_magic *m)
{
	m->mlx = mlx_init();
	m->win = mlx_new_window(m->mlx, WIN_WIDTH, \
			WIN_HEIGHT, "Fractol");
	m->c_re = -0.7;
	m->c_im = 0.27015;
	m->zoom = 1;
	m->move_x = 0;
	m->move_y = 0;
	type(m);
	put_alert(m);
	if (m->type == 3)
		mlx_string_put(m->mlx, m->win, 10, 10, \
				0xffffff, "esc: exit");
	mlx_mouse_hook(m->win, mouse_scroll_hook, m);
	mlx_hook(m->win, 6, 0, mouse_move_hook, m);
	mlx_key_hook(m->win, hook_keydown, m);
	mlx_loop(m->mlx);
}
