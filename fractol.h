/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwisozk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 13:27:05 by jwisozk           #+#    #+#             */
/*   Updated: 2019/07/23 21:34:40 by jwisozk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <pthread.h>
# include <math.h>
# include "libft/libft.h"
# include "minilibx/mlx.h"
# define DW 1600
# define DH 900
# define MAX_ITER 50
# define SCALE 2
# define OFFSET 10
# define RE_MIN -3.5
# define RE_MAX	3.5
# define IM_MIN	-2.0
# define IM_MAX 2.0

typedef struct 	s_point
{
	long double x;
	long double y;
}				t_point;

typedef struct 	s_fractal
{
	long double ReMin;
	long double ReMax;
	long double ImMin;
	long double ImMax;
}				t_fractal;

typedef struct 	s_delta
{
	long double	Re;
	long double	Im;
}				t_delta;

typedef struct	s_img
{
	int 		bits_per_pixel;
	int 		size_line;
	int 		endian;
	void		*img_ptr;
	int 		*img_arr;
}				t_img;

typedef struct 	s_asset
{
	void		*mlx_ptr;
	void		*win_ptr;
	int 		MaxIter;
	t_fractal	f;
	int			rgb[16];
	t_img		img;
	int 		key;
	t_delta		delta;
	long double x;
	long double y;
	long double t;
	int 		i;
	int 		j;
	t_point 	point;
}				t_asset;

int 			get_color(int current, int start, t_asset *p);
void			ft_draw_mandelbrot(t_asset *p);
void			ft_scale(t_fractal* e,int mouse_x, int mouse_y, long double scale);
int				ft_close_window(void);
int				ft_key_press(int keycode, t_asset *p);
int				ft_mouse_press(int button, int x, int y, t_asset *p);
int 			ft_set_rgb(int r, int g, int b);
void 			ft_set_random_colors(t_asset *p);
void 			ft_set_init_colors(t_asset *p);
void 			ft_set_second_colors(t_asset *p);
void			ft_init_fractal(t_asset *p);
void			ft_init_fractals(t_asset *main, t_asset *p);

# include <stdio.h>

#endif
