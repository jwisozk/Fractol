/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwisozk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 16:59:55 by jwisozk           #+#    #+#             */
/*   Updated: 2019/07/19 16:46:50 by jwisozk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_draw_fractal(t_asset *p)
{
	double point[2];
	double Re_coef =(p->f.Re.max - p->f.Re.min) / ((DW - 1));
	double Im_coef =(p->f.Im.max - p->f.Im.min) / ((DH - 1));
	int MaxIter = p->iter;
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
			while (x * x + y * y <= 4 && k < MaxIter)
			{
				t = x * x - y * y + point[0];
				y = 2 * x * y + point[1];
				x = t;
				k++;
			}
			if (k < MaxIter)
			{
				if (p->key == 1 || p->key == 2)
				{
					n = k % 16;
					p->img.img[i*DW + j] = p->rgb[n];
				}
				else
					p->img.img[i*DW + j] = get_color(k, 0, MaxIter, p->key);
			}
			else
				p->img.img[i*DW + j] = 0x000000;
			point[0] += Re_coef;
			j++;
		}
		point[1] -= Im_coef;
		i++;
	}
	mlx_put_image_to_window(p->mlx_ptr, p->win_ptr, p->img.img_ptr, 0, 0);
}
