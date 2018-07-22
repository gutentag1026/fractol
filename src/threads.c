/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuang <yhuang@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 21:26:52 by yhuang            #+#    #+#             */
/*   Updated: 2018/07/17 00:24:46 by yhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	*julia_row(void *n)
{
	int				y;
	int				x;
	t_thread_data	*t;

	t = (t_thread_data *)n;
	t->maxiterations = 255;
	y = t->y;
	x = -1;
	while (++x < WIN_WIDTH && (t->i = -1))
	{
		t->new_re = 1.5 * (x - WIN_WIDTH / 2) /\
	(0.5 * t->m->zoom * WIN_WIDTH) + t->m->move_x;
		t->new_im = (y - WIN_HEIGHT / 2) / \
	(0.5 * t->m->zoom * WIN_HEIGHT) + t->m->move_y;
		while (++(t->i) < t->maxiterations)
		{
			convert_j(t);
			if ((t->new_re * t->new_re + t->new_im * t->new_im) > 4)
				break ;
		}
		t->color = fetch_color(t->i);
		t->m->pixel[y][x] = t->color;
	}
	return (NULL);
}

void	*mandelbrot_row(void *n)
{
	int				y;
	t_thread_data	*t;

	t = (t_thread_data *)n;
	t->maxiterations = 255;
	y = t->y;
	t->x = -1;
	while (++(t->x) < WIN_WIDTH && (t->i = -1))
	{
		t->pr = 1.5 * (t->x - WIN_WIDTH / 2) / (0.5 * \
				t->m->zoom * WIN_WIDTH) + t->m->move_x;
		t->pi = (y - WIN_HEIGHT / 2) / (0.5 * \
				t->m->zoom * WIN_HEIGHT) + t->m->move_y;
		convert_m(t);
		while (++(t->i) < t->maxiterations)
		{
			convert_m1(t);
			if ((t->new_re * t->new_re + t->new_im * t->new_im) > 4)
				break ;
		}
		t->color = get_color(t->i);
		t->m->pixel[y][t->x] = t->color;
	}
	return (NULL);
}

void	*tricorn_row(void *n)
{
	int				y;
	t_thread_data	*t;

	t = (t_thread_data *)n;
	t->maxiterations = 255;
	y = t->y;
	t->x = -1;
	while (++(t->x) < WIN_WIDTH && (t->i = -1))
	{
		t->pr = 1.5 * (t->x - WIN_WIDTH / 2) / (0.5 * \
				t->m->zoom * WIN_WIDTH) + t->m->move_x;
		t->pi = (y - WIN_HEIGHT / 2) / (0.5 * \
				t->m->zoom * WIN_HEIGHT) + t->m->move_y;
		convert_m(t);
		while (++(t->i) < t->maxiterations)
		{
			convert_m2(t);
			if ((t->new_re * t->new_re + t->new_im * t->new_im) > 4)
				break ;
		}
		t->color = get_color(t->i);
		t->m->pixel[y][t->x] = t->color;
	}
	return (NULL);
}

void	*burningship_row(void *n)
{
	int				y;
	t_thread_data	*t;

	t = (t_thread_data *)n;
	t->maxiterations = 255;
	y = t->y;
	t->x = -1;
	while (++(t->x) < WIN_WIDTH && (t->i = -1))
	{
		t->pr = 1.5 * (t->x - WIN_WIDTH / 2) / (0.5 * \
				t->m->zoom * WIN_WIDTH) + t->m->move_x;
		t->pi = (y - WIN_HEIGHT / 2) / (0.5 * \
				t->m->zoom * WIN_HEIGHT) + t->m->move_y;
		convert_m(t);
		while (++(t->i) < t->maxiterations)
		{
			convert_m3(t);
			if ((t->new_re * t->new_re + t->new_im * t->new_im) > 4)
				break ;
		}
		t->color = get_color(t->i);
		t->m->pixel[y][t->x] = t->color;
	}
	return (NULL);
}
