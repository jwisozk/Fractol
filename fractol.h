/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwisozk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 13:27:05 by jwisozk           #+#    #+#             */
/*   Updated: 2019/07/12 17:53:47 by jwisozk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <math.h>
# include "libft/libft.h"
# include "/usr/local/include/mlx.h"
# define DW 1600
# define DH 900



//typedef struct 	s_point
//{
//	int 		x;
//	int 		y;
//	int 		color;
//}				t_point;

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

typedef struct 	s_asset
{
	void		*mlx_ptr;
	void		*win_ptr;
	float 		scale;
	int 		ix;
	int 		iy;
	t_fractal	e;

}				t_asset;

int 			get_color(int current, int start, int end);
void			ft_draw_fractal(void *mlx_ptr, void *win_ptr, t_asset *p);
void			ft_scale(t_fractal* e,int mouse_x, int mouse_y, double scale);

# include <stdio.h>

#endif
