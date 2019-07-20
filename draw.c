/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwisozk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 16:59:55 by jwisozk           #+#    #+#             */
/*   Updated: 2019/07/20 10:02:02 by jwisozk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_draw_fractal(t_asset *p)
{
	t_point point;
	p->delta.Re = (p->f.ReMax - p->f.ReMin) / ((DW - 1));
	p->delta.Im = (p->f.ImMax - p->f.ImMin) / ((DH - 1));
	int i;
	int j;
	int k;
	int n;

	point.y = p->f.ImMax;
	i = 0;
	while (i < DH)
	{
		j = 0;
		point.x = p->f.ReMin;
		while (j < DW)
		{
			p->x = 0.0;
			p->y = 0.0;
			k = 0;
			while (p->x * p->x + p->y * p->y <= 4 && k < p->MaxIter)
			{
				p->t = p->x *p->x - p->y * p->y + point.x;
				p->y = 2 * p->x * p->y + point.y;
				p->x = p->t;
				k++;
			}
			if (k < p->MaxIter)
			{
				if (p->key == 1 || p->key == 2)
				{
					n = k % 16;
					p->img.img[i*DW + j] = p->rgb[n];
				}
				else
					p->img.img[i*DW + j] = get_color(k, 0, p->MaxIter, p->key);
			}
			else
				p->img.img[i*DW + j] = 0x000000;
			point.x += p->delta.Re;
			j++;
		}
		point.y -= p->delta.Im;
		i++;
	}
	mlx_put_image_to_window(p->mlx_ptr, p->win_ptr, p->img.img_ptr, 0, 0);
}
