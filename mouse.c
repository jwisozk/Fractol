/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwisozk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 12:54:18 by jwisozk           #+#    #+#             */
/*   Updated: 2019/07/13 17:39:26 by jwisozk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		ft_mouse_press(int button, int x, int y, t_asset *p)
{
	x = x + y;
	mlx_clear_window(p->mlx_ptr, p->win_ptr);
	if (button == 5 && p->scale < MAX_ITER)
	{
		p->zoom += 1;
//		p->scale += STEP;
//		printf("scale = %f\n", p->scale);
//		ft_scale(&p->f, x, DH - y, STEP);
	}
	if (button == 4 && p->scale > 0)
	{
		p->zoom -= 1;
//		p->scale -= STEP;
//		ft_scale(&p->f, x, y, 1.0 / STEP);
	}
	//	printf("scale = %f, x = %i, y = %i\n", p->scale, x, y);
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