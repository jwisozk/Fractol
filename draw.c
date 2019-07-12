/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwisozk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 17:50:10 by jwisozk           #+#    #+#             */
/*   Updated: 2019/07/12 19:15:17 by jwisozk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_draw_fractal(void *mlx_ptr, void *win_ptr, t_asset *p)
{
	float MinRe = p->e.Re.min;
	float MaxRe = p->e.Re.max;
	float MinIm = p->e.Im.min;
	float MaxIm = p->e.Im.max;
	//	float scale = 1.5;
	//	float xm = 300;
	//	float ym = 300;
	//
	float point[2];
	float Re_coef =(MaxRe - MinRe) / ((DW - 1));
	float Im_coef =(MaxIm - MinIm) / ((DH - 1));
	int MaxIterations = 100;
	int i;
	int j;
	int k;
	float x;
	float y;
	float t;

	point[1] = MaxIm;
	i = 0;
	while (i < DH)
	{
		j = 0;
		point[0] = MinRe;
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
				mlx_pixel_put(mlx_ptr, win_ptr, j, i, get_color(k, 0, MaxIterations));
			else
				mlx_pixel_put(mlx_ptr, win_ptr, j, i, 0x000000);
			point[0] += Re_coef;
			j++;
		}
		point[1] -= Im_coef;
		i++;
	}
}
