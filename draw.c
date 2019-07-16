/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwisozk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 16:59:55 by jwisozk           #+#    #+#             */
/*   Updated: 2019/07/16 17:01:31 by jwisozk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fractol.h"

void	ft_draw_fractal(void *mlx_ptr, void *win_ptr, t_asset *p)
{
	double point[2];
	double Re_coef =(p->f.Re.max - p->f.Re.min) / ((DW - 1));
	double Im_coef =(p->f.Im.max - p->f.Im.min) / ((DH - 1));
	int MaxIterations = p->iter;
	int i;
	int j;
	int k;
	int n;
	double x;
	double y;
	double t;

	point[1] = p->f.Im.max;
	i = 0;
	while (i < DH)
	{
		j = 0;
		point[0] = p->f.Re.min;
		while (j < DW)
		{
			x = 0.0;
			y = 0.0;
			k = 0;
			while (x * x + y * y <= 4 && k < MaxIterations)
			{
				t = x * x - y * y + point[0];
				y = 2 * x * y + point[1];
				x = t;
				k++;
			}
			if (k < MaxIterations)
			{
				n = k % 16;
				mlx_pixel_put(mlx_ptr, win_ptr, j, i, p->rgb[n]);
//				mlx_pixel_put(mlx_ptr, win_ptr, j, i, get_color(k, 0, MaxIterations));
			}
			else
				mlx_pixel_put(mlx_ptr, win_ptr, j, i, 0x000000);
			point[0] += Re_coef;
			j++;
		}
		point[1] -= Im_coef;
		i++;
	}
}
