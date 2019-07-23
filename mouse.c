/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwisozk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 12:54:18 by jwisozk           #+#    #+#             */
/*   Updated: 2019/07/23 20:51:02 by jwisozk          ###   ########.fr       */
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
	if (button == 4 && p->f.ReMax - p->f.ReMin < 200)
	{
		p->MaxIter -= SCALE * 3;
		ft_scale(&p->f, x, y, 1.0 / SCALE);
	}
	ft_draw_mandelbrot(p);
	return (0);
}