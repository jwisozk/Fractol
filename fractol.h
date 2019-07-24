/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwisozk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 13:27:05 by jwisozk           #+#    #+#             */
/*   Updated: 2019/07/24 18:20:51 by jwisozk          ###   ########.fr       */
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
# define MAX_ITER 50
# define SCALE 2
# define OFFSET 10
# define RE_LEN 10
# define INIT_COLOR 0x19071A, 0x09012F, 0x040449, 0x000764, 0x0C2C8A, 0x1852B1,\
					0x397DD1, 0x86B5E5, 0xD3ECF8, 0xF1E9BF, 0xF8C95F, 0xFFAA00,\
					0xCC8000, 0x995700, 0x6A3403, 0x421E0F
# define SCND_COLOR 0xD67D4C, 0xA62F2B, 0xEBC258, 0x711F3C, 0x488B81, 0xEBC258,\
					0xD67D4C, 0xA62F2B, 0xEBC258, 0x711F3C, 0x488B81, 0xEBC258,\
					0xD67D4C, 0xA62F2B, 0xEBC258, 0x711F3C
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
	int			*rgb;
	t_img		img;
	int 		key;
	t_delta		delta;
	long double x;
	long double y;
	long double dx;
	long double dy;
	int 		i;
	int 		j;
	t_point 	point;
}				t_asset;

int 			get_color(int current, int start, t_asset *p);
void			ft_draw_fractal(t_asset *p);
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
