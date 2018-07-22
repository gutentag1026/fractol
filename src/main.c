/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuang <yhuang@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 17:11:43 by yhuang            #+#    #+#             */
/*   Updated: 2018/07/16 23:51:04 by yhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	julia(t_magic *m)
{
	int		i;
	int		x;
	int		y;

	i = -1;
	y = 0;
	while (++i < WIN_HEIGHT)
		pthread_create(&(m->t[i].tid), NULL, julia_row, (void *)(m->t + i));
	while (--i >= 0)
		pthread_join(m->t[i].tid, NULL);
	while (y < WIN_HEIGHT)
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

void	mandelbrot(t_magic *m)
{
	int		i;
	int		x;
	int		y;

	i = -1;
	y = 0;
	while (++i < WIN_HEIGHT)
		pthread_create(&(m->t[i].tid), NULL, \
				mandelbrot_row, (void *)(m->t + i));
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

void	canter(t_canter c)
{
	if (c.len >= 0.01)
	{
		line(c.x * c.m->zoom, c.y * c.m->zoom, \
				c.x * c.m->zoom + c.len * c.m->zoom, c.m);
		c.y += 100;
		c.len /= 3;
		canter(c);
		c.x += c.len * 2;
		canter(c);
	}
}

void	tricorn(t_magic *m)
{
	int		i;
	int		x;
	int		y;

	i = -1;
	y = 0;
	while (++i < WIN_HEIGHT)
		pthread_create(&(m->t[i].tid), NULL, \
				tricorn_row, (void *)(m->t + i));
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

int		main(int argc, char **argv)
{
	t_magic		m;
	int			i;

	i = 0;
	m.type = 0;
	if (argc != 2 || !(m.type = compare(argv[1])))
		useage();
	m.pixel = (int **)malloc(sizeof(int *) * WIN_HEIGHT);
	while (i < WIN_HEIGHT)
	{
		m.pixel[i] = (int *)malloc(sizeof(int) * WIN_WIDTH);
		i++;
	}
	mlx(&m);
	return (0);
}
