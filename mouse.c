/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwisozk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 12:54:18 by jwisozk           #+#    #+#             */
/*   Updated: 2019/08/01 20:40:34 by jwisozk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			ft_print_error(char *str)
{
	ft_putstr(str);
	ft_putchar('\n');
	exit(0);
}

long double	ft_map(long double n, int len, double min, double max)
{
	return (n / (len / (max - min)) + min);
}

int			ft_mouse_press(int button, int x, int y, t_asset *p)
{
	mlx_clear_window(p->mlx_ptr, p->win_ptr);
	if (button == 5 && p->f.remax - p->f.remin > 0.00000000000001 && y > 0)
	{
		p->zoom++;
		p->maxiter += SCALE * 3;
		ft_scale(p, x, y, SCALE);
	}
	if (button == 4 && p->f.remax - p->f.remin < 1000 && y > 0)
	{
		p->zoom--;
		p->maxiter -= SCALE * 3;
		ft_scale(p, x, y, 1.0 / SCALE);
	}
	ft_draw_fractal(p);
	return (0);
}

int			ft_mouse_move(int x, int y, t_asset *p)
{
	if (p->julia == 1 && p->julia_move == 1 && y > 0)
	{
		p->cx = ft_map(x, DW, p->f.remin, p->f.remax);
		p->cy = ft_map(y, DH, p->f.immin, p->f.immax);
		mlx_clear_window(p->mlx_ptr, p->win_ptr);
		ft_draw_fractal(p);
	}
	return (0);
}
