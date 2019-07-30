/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwisozk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 12:54:18 by jwisozk           #+#    #+#             */
/*   Updated: 2019/07/30 17:24:54 by jwisozk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

long double ft_map(long double n, int st1, int end1, float st2, float end2)
{
	return (n - st1) / (end1 - st1) * (end2 - st2) + st2;
}

int		ft_mouse_press(int button, int x, int y, t_asset *p)
{
	mlx_clear_window(p->mlx_ptr, p->win_ptr);
	if (button == 5 && p->f.ReMax - p->f.ReMin > 0.00000000000001 && y > 0)
	{
		p->MaxIter += SCALE * 3;
		ft_scale(p, x, y, SCALE);
	}
	if (button == 4 && p->f.ReMax - p->f.ReMin < 1000 && y > 0)
	{
		p->MaxIter -= SCALE * 3;
		ft_scale(p, x, y, 1.0 / SCALE);
	}
	ft_draw_fractal(p);
	return (0);
}

int		ft_mouse_move(int x, int y, t_asset *p)
{
	if (p->julia == 1 && p->julia_move == 1 && y > 0)
	{
		p->cx = ft_map(x, 0, DW, p->f.ReMin, p->f.ReMax);
		p->cy = ft_map(y, 0, DH, p->f.ImMin, p->f.ImMax);
		mlx_clear_window(p->mlx_ptr, p->win_ptr);
		ft_draw_fractal(p);
	}
	return (0);
}