/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwisozk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 12:54:18 by jwisozk           #+#    #+#             */
/*   Updated: 2019/07/24 21:13:59 by jwisozk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		ft_mouse_press(int button, int x, int y, t_asset *p)
{
	mlx_clear_window(p->mlx_ptr, p->win_ptr);
	if (button == 5 && p->f.ReMax - p->f.ReMin > 0.00000000000001)
	{
		p->MaxIter += SCALE * 3;
		ft_scale(&p->f, x, y, SCALE);
	}
	if (button == 4 && p->f.ReMax - p->f.ReMin < 1000)
	{
		p->MaxIter -= SCALE * 3;
		ft_scale(&p->f, x, y, 1.0 / SCALE);
	}
	ft_draw_fractal(p);
	return (0);
}

int		ft_mouse_move(int x, int y, t_asset *p)
{
	if (p->julia == 1)
	{
//		printf("(%i, %i)\n", x, y);
		//printf("(%.10Lf, %.10Lf)\n", p->delta.Re * x,  p->delta.Im * y);
		p->cx = p->delta.Re * x - 5.0;
		p->cy = p->delta.Im * y - 2.7;
		mlx_clear_window(p->mlx_ptr, p->win_ptr);
		ft_draw_fractal(p);
//		if (p->init_x == 0)
//			p->init_x = x;
//		if (p->init_y == 0)
//			p->init_y = y;
//		if (p->is_perspective == 1)
//			ft_non_perspective(p);
//		ft_mouse_mini(p, x, y);
//		if (p->is_perspective == 1)
//			ft_perspective(p, -2000);
//		mlx_clear_window(p->mlx_ptr, p->win_ptr);
//		ft_draw_lines(p);
	}
	return (0);
}