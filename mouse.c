/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwisozk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 12:54:18 by jwisozk           #+#    #+#             */
/*   Updated: 2019/07/20 09:43:57 by jwisozk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		ft_mouse_press(int button, int x, int y, t_asset *p)
{
	mlx_clear_window(p->mlx_ptr, p->win_ptr);
	if (button == 5 && p->f.ReMin - p->f.ReMax < -0.000000000001)
	{
		p->MaxIter += STEP * 3;
		ft_scale(&p->f, x, DH - y, STEP);
	}
	if (button == 4)
	{
		p->MaxIter -= STEP * 3;
		ft_scale(&p->f, x, y, 1.0 / STEP);
	}
	ft_draw_fractal(p);
	return (0);
}