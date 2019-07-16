/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwisozk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 12:54:18 by jwisozk           #+#    #+#             */
/*   Updated: 2019/07/16 14:46:46 by jwisozk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		ft_mouse_press(int button, int x, int y, t_asset *p)
{
	mlx_clear_window(p->mlx_ptr, p->win_ptr);
	if (button == 5)
	{
//		p->zoom += 1;
		p->scale += STEP;
		p->iter += STEP * 3;
//		printf("iter = %i\n", p->iter);
		ft_scale(&p->f, x, DH - y, STEP);
	}
	if (button == 4 && p->scale > 0)
	{
//		p->zoom -= 1;
		p->scale -= STEP;
		p->iter -= STEP * 3;
		ft_scale(&p->f, x, y, 1.0 / STEP);
//		printf("iter = %i\n", p->iter);
	}
		printf("scale = %f, iter = %i\n", p->scale, p->iter);
	ft_draw_fractal(p->mlx_ptr, p->win_ptr, p);

	//	if (button == 1)
	//		p->press_mouse_l = 1;
	//	if (button == 5 && scale < LIMIT_SCALE_UP)
	//		ft_draw_fractal(mlx_ptr, win_ptr, 1.1, );
	//		ft_scale(p, 1.1);
	//	if (button == 4 && scale > LIMIT_SCALE_DOWN)
	//		ft_scale(p, 0.9);
	//	ft_draw_lines(p);
	return (0);
}