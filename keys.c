/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwisozk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 12:52:18 by jwisozk           #+#    #+#             */
/*   Updated: 2019/08/01 20:21:26 by jwisozk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		ft_close_window(t_asset *p)
{
	mlx_destroy_window(p->mlx_ptr, p->win_ptr);
	(*p->windows)--;
	if (*p->windows > 0)
		return (1);
	exit(0);
}

void	ft_move(int key, t_asset *p)
{
	if (key == 123 || key == 0)
	{
		p->f.remin += p->delta.re * OFFSET;
		p->f.remax += p->delta.re * OFFSET;
	}
	if (key == 124 || key == 2)
	{
		p->f.remin -= p->delta.re * OFFSET;
		p->f.remax -= p->delta.re * OFFSET;
	}
	if (key == 125 || key == 1)
	{
		p->f.immin -= p->delta.im * OFFSET;
		p->f.immax -= p->delta.im * OFFSET;
	}
	if (key == 126 || key == 13)
	{
		p->f.immin += p->delta.im * OFFSET;
		p->f.immax += p->delta.im * OFFSET;
	}
	mlx_clear_window(p->mlx_ptr, p->win_ptr);
	ft_draw_fractal(p);
}

void	ft_switch_fractal(int key, t_asset *p)
{
	if (key == 18)
	{
		ft_init_fractal(p);
	}
	if (key == 19)
	{
		if (p->julia_move == 0)
			p->julia_move = 1;
		else
			p->julia_move = 0;
		if (p->julia == 0)
		{
			ft_init_fractal(p);
			p->julia = 1;
			p->cx = CX;
			p->cy = CY;
		}
	}
	if (key == 20)
	{
		ft_init_fractal(p);
		p->ship = 1;
	}
	mlx_clear_window(p->mlx_ptr, p->win_ptr);
	ft_draw_fractal(p);
}

void	ft_change_maxiter(int key, t_asset *p)
{
	if (key == 47)
		p->maxiter++;
	if (key == 43)
		p->maxiter--;
	mlx_clear_window(p->mlx_ptr, p->win_ptr);
	ft_draw_fractal(p);
}

int		ft_key_press(int key, t_asset *p)
{
	if (key == 53)
		ft_close_window(p);
	if (key == 10)
	{
		mlx_clear_window(p->mlx_ptr, p->win_ptr);
		p->key++;
		if (p->key == 1)
			ft_set_init_colors(p);
		ft_draw_fractal(p);
		if (p->key == 3)
			p->key = 0;
	}
	if ((key >= 123 && key <= 126) || (key >= 0 && key <= 2) || key == 13)
		ft_move(key, p);
	if (key >= 18 && key <= 20)
		ft_switch_fractal(key, p);
	if (key == 43 || key == 47)
		ft_change_maxiter(key, p);
	return (0);
}
