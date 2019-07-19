/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwisozk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 13:27:05 by jwisozk           #+#    #+#             */
/*   Updated: 2019/07/19 16:26:10 by jwisozk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <math.h>
# include "libft/libft.h"
# include "minilibx/mlx.h"
# define DW 1600
# define DH 900
# define MAX_ITER 50
# define STEP 2
# define RE_MIN -2.5
# define RE_MAX	1.0
# define IM_MIN	-1.1
# define IM_MAX 1.1

typedef struct 	s_point
{
	long double 		min;
	long double 		max;
}				t_point;

typedef struct 	s_fractal
{
	t_point 	Re;
	t_point 	Im;

}				t_fractal;

//typedef struct 	s_color
//{
//	int 		r;
//	int 		g;
//	int 		b;
//}				t_color;

typedef struct	s_img
{
	int 	bits_per_pixel;
	int 	size_line;
	int 	endian;
	void	*img_ptr;
	int 	*img;
}				t_img;

typedef struct 	s_asset
{
	void		*mlx_ptr;
	void		*win_ptr;
	int 		iter;
	t_fractal	f;
	int			rgb[16];
	t_img		img;
	int 		key;

}				t_asset;


int 			get_color(int current, int start, int end, int key);
void			ft_draw_fractal(t_asset *p);
void			ft_scale(t_fractal* e,int mouse_x, int mouse_y, long double scale);
int				ft_close_window(void);
int				ft_key_press(int keycode, t_asset *p);
int				ft_mouse_press(int button, int x, int y, t_asset *p);
int 			ft_set_rgb(int r, int g, int b);
void 			ft_set_random_colors(t_asset *p);
void 			ft_set_init_colors(t_asset *p);
void 			ft_set_second_colors(t_asset *p);

# include <stdio.h>

#endif
