/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwisozk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 12:52:18 by jwisozk           #+#    #+#             */
/*   Updated: 2019/07/18 14:09:12 by jwisozk          ###   ########.fr       */
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
		ft_set_init_colors(p);
		ft_draw_fractal(p);
	}
	if (keycode == 19)
	{
		mlx_clear_window(p->mlx_ptr, p->win_ptr);
		ft_set_random_colors(p);
		ft_draw_fractal(p);
	}

	return (0);
}