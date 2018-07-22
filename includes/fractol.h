/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuang <yhuang@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/15 01:17:41 by yhuang            #+#    #+#             */
/*   Updated: 2018/07/17 00:24:51 by yhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../libft/libft.h"
# include "mlx.h"
# include <math.h>
# include <pthread.h>
# include <stdlib.h>
# define WIN_WIDTH 1000
# define WIN_HEIGHT 1000

typedef struct s_thread_data	t_thread_data;

typedef	struct					s_magic
{
	void						*mlx;
	void						*win;
	double						move_x;
	double						move_y;
	double						zoom;
	double						c_re;
	double						c_im;
	int							type;
	t_thread_data				*t;
	int							**pixel;
}								t_magic;

struct							s_thread_data
{
	t_magic						*m;
	pthread_t					tid;
	int							y;
	int							x;
	double						new_re;
	double						new_im;
	double						old_re;
	double						old_im;
	double						pr;
	double						pi;
	int							color;
	int							maxiterations;
	int							i;
};

typedef struct					s_canter
{
	float						x;
	float						y;
	float						len;
	t_magic						*m;
}								t_canter;

typedef struct					s_map
{
	int							x;
	int							y;
}								t_map;

typedef struct					s_dot
{
	float						x;
	float						y;
}								t_dot;

typedef struct					s_line
{
	float						x0;
	float						y0;
	float						x1;
	float						y1;
}								t_line;

void							julia(t_magic *m);
void							*julia_row(void *n);
void							mandelbrot(t_magic *m);
void							*mandelbrot_row(void *n);
void							*tricorn_row(void *n);
void							*burningship_row(void *n);
void							burningship(t_magic *m);
void							tricorn(t_magic *m);
void							canter(t_canter c);
void							alloc_threads(t_magic *m);
void							type(t_magic *m);
void							convert_m(t_thread_data *t);
void							convert_j(t_thread_data *t);
void							convert_m1(t_thread_data *t);
void							convert_m2(t_thread_data *t);
void							convert_m3(t_thread_data *t);
void							useage(void);
int								compare(char *input);
int								get_color(int i);
int								fetch_color(int i);
void							line(float x, float y, float x1, t_magic *m);
int								mouse_move_hook(int x, int y, t_magic *m);
int								hook_keydown(int keycode, t_magic *m);
int								mouse_scroll_hook\
	(int button, int x, int y, t_magic *m);
void							free_memory(t_magic *m);
int								effect(int key, t_magic *m);
void							mlx(t_magic *m);

#endif
