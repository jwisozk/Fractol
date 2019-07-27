/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwisozk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 12:52:18 by jwisozk           #+#    #+#             */
/*   Updated: 2019/07/24 20:06:25 by jwisozk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		ft_close_window(void)
{
	exit(0);
}

int		ft_key_press(int keycode, t_asset *p)
{
	if (keycode == 53)
		ft_close_window();
	if (keycode == 19)
	{
		mlx_clear_window(p->mlx_ptr, p->win_ptr);
		p->key++;
		if (p->key == 1)
			ft_set_init_colors(p);
		if (p->key == 2)
			ft_set_second_colors(p);
		ft_draw_fractal(p);
		if (p->key == 6)
			p->key = 0;
	}
	if (keycode == 123 || keycode == 0)
	{
		mlx_clear_window(p->mlx_ptr, p->win_ptr);
		p->f.ReMin += p->delta.Re * OFFSET;
		p->f.ReMax += p->delta.Re * OFFSET;
		ft_draw_fractal(p);
	}
	if (keycode == 124 || keycode == 2)
	{
		mlx_clear_window(p->mlx_ptr, p->win_ptr);
		p->f.ReMin -= p->delta.Re * OFFSET;
		p->f.ReMax -= p->delta.Re * OFFSET;
		ft_draw_fractal(p);
	}
	if (keycode == 125 || keycode == 1)
	{
		mlx_clear_window(p->mlx_ptr, p->win_ptr);
		p->f.ImMin -= p->delta.Im * OFFSET;
		p->f.ImMax -= p->delta.Im * OFFSET;
		ft_draw_fractal(p);
	}
	if (keycode == 126 || keycode == 13)
	{
		mlx_clear_window(p->mlx_ptr, p->win_ptr);
		p->f.ImMin += p->delta.Im * OFFSET;
		p->f.ImMax += p->delta.Im * OFFSET;
		ft_draw_fractal(p);
	}
	if (keycode == 18)
	{
		mlx_clear_window(p->mlx_ptr, p->win_ptr);
		ft_init_fractal(p);
		ft_draw_fractal(p);
	}
	if (keycode == 20)
	{
		printf("%i\n",p->julia);
		if (p->julia == 0)
		{
			p->julia = 1;
			p->cx = CX;
			p->cy = CY;
			mlx_clear_window(p->mlx_ptr, p->win_ptr);
			ft_draw_fractal(p);
		}
		if (p->julia_move == 0)
			p->julia_move = 1;
		else
			p->julia_move = 0;
	}
	return (0);
}