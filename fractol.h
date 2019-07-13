/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwisozk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 13:27:05 by jwisozk           #+#    #+#             */
/*   Updated: 2019/07/13 16:42:44 by jwisozk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <math.h>
# include "libft/libft.h"
# include "minilibx/mlx.h"
# define DW 1600
# define DH 900
# define MAX_ITER 100
# define STEP 10
# define RE_MIN -2.5
# define RE_MAX	1.0
# define IM_MIN	-1.1
# define IM_MAX 1.1

typedef struct 	s_point
{
	double 		min;
	double 		max;
}				t_point;

typedef struct 	s_fractal
{
	t_point 	Re;
	t_point 	Im;

}				t_fractal;

typedef struct 	s_color
{
	int 		r;
	int 		g;
	int 		b;
}				t_color;

typedef struct 	s_asset
{
	void		*mlx_ptr;
	void		*win_ptr;
	double 		scale;
	double 		zoom;
	t_fractal	f;
	int			rgb[16];

}				t_asset;


int 			get_color(int current, int start, int end);
void			ft_draw_fractal(void *mlx_ptr, void *win_ptr, t_asset *p);
void			ft_scale(t_fractal* e,int mouse_x, int mouse_y, double scale);
int				ft_close_window(void);
int				ft_key_press(int keycode);
int				ft_mouse_press(int button, int x, int y, t_asset *p);
int 			ft_set_rgb(int r, int g, int b);

# include <stdio.h>

#endif
