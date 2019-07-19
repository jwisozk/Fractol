/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwisozk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 12:52:18 by jwisozk           #+#    #+#             */
/*   Updated: 2019/07/19 16:54:26 by jwisozk          ###   ########.fr       */
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
	if (keycode == 18)
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


	return (0);
}