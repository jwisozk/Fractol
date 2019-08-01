/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwisozk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 13:27:05 by jwisozk           #+#    #+#             */
/*   Updated: 2019/08/01 20:05:16 by jwisozk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <pthread.h>
# include <math.h>
# include "libft/libft.h"
# include "minilibx/mlx.h"
# define DW 1600
# define DH 855
# define HEADER 45
# define MAX_ITER 60
# define SCALE 2
# define OFFSET 10
# define RE_LEN 10
# define CX -0.70176
# define CY -0.3842
# define ONE 0x19071A, 0x09012F, 0x040449, 0x000764, 0x0C2C8A, 0x1852B1
# define TWO 0x397DD1, 0x86B5E5, 0xD3ECF8, 0xF1E9BF, 0xF8C95F, 0xFFAA00
# define THREE 0xCC8000, 0x995700, 0x6A3403, 0x421E0F
# define INIT_COLOR ONE, TWO, THREE

typedef struct	s_point
{
	long double x;
	long double y;
}				t_point;

typedef struct	s_fractal
{
	long double	remin;
	long double remax;
	long double immin;
	long double immax;
}				t_fractal;

typedef struct	s_delta
{
	long double	re;
	long double	im;
}				t_delta;

typedef struct	s_img
{
	int			bit_per_pixel;
	int			size_line;
	int			endian;
	void		*img_ptr;
	int			*img_arr;
}				t_img;

typedef struct	s_asset
{
	void		*mlx_ptr;
	void		*win_ptr;
	int			maxiter;
	t_fractal	f;
	int			*rgb;
	t_img		img;
	int			key;
	t_delta		delta;
	long double x;
	long double y;
	long double dx;
	long double dy;
	long double cx;
	long double cy;
	int			i;
	int			j;
	int			julia;
	int			julia_move;
	int			ship;
	char		*str;
	t_point		point;
	int			*windows;
	int			zoom;
}				t_asset;

int				get_color(int current, t_asset *p);
void			ft_draw_fractal(t_asset *p);
void			ft_scale(t_asset *p, int x, int y, float scale);
int				ft_close_window(t_asset *p);
int				ft_key_press(int key, t_asset *p);
int				ft_mouse_press(int button, int x, int y, t_asset *p);
void			ft_set_init_colors(t_asset *p);
void			ft_init_fractal(t_asset *p);
void			ft_init_fractals(t_asset *main, t_asset *p);
int				ft_mouse_move(int x, int y, t_asset *p);
long double		ft_map(long double n, int len, double min, double max);
int				ft_smooth_color(int n, t_asset *p);
int				ft_print_error(char *str);

#endif
