/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwisozk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 16:59:55 by jwisozk           #+#    #+#             */
/*   Updated: 2019/07/23 20:51:02 by jwisozk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_put_color(t_asset *p)
{
	int iter;
	int n;

	p->x = 0.0;
	p->y = 0.0;
	iter = 0;
	while (p->x * p->x + p->y * p->y <= 4 && iter < p->MaxIter)
	{
		p->t = p->x * p->x - p->y * p->y + p->point.x;
		p->y = 2 * p->x * p->y + p->point.y;
		p->x = p->t;
		iter++;
	}
	if (iter < p->MaxIter)
	{
		if (p->key == 1 || p->key == 2)
		{
			n = iter % 16;
			p->img.img_arr[p->i * DW + p->j] = p->rgb[n];
		}
		else
			p->img.img_arr[p->i * DW + p->j] = get_color(iter, 0, p);
	}
	else
		p->img.img_arr[p->i * DW + p->j] = 0x000000;
}

void *ft_row(void *data)
{
	t_asset *p;

	p = (t_asset *) data;
	p->point.x = p->f.ReMin;
	p->j = 0;
	while (p->j < DW)
	{
		ft_put_color(p);
		p->point.x += p->delta.Re;
		p->j++;
	}
	return (NULL);
}

void	ft_draw_mandelbrot(t_asset *p)
{
	pthread_t* threadsId;
	t_asset* threadData;

	threadsId = (pthread_t*) malloc(DH * sizeof(pthread_t));
	threadData = (t_asset*) malloc(DH * sizeof(t_asset));
	p->delta.Re = (p->f.ReMax - p->f.ReMin) / (DW - 1);
	p->delta.Im = (p->f.ImMax - p->f.ImMin) / (DH - 1);
	p->point.y = p->f.ImMin;
	p->i = 0;
	while (p->i < DH)
	{
		ft_init_fractals(p, &threadData[p->i]);
		pthread_create(&(threadsId[p->i]), NULL, ft_row, &threadData[p->i]);
		p->point.y += p->delta.Im;
		p->i++;
	}
	p->i = 0;
	while (p->i < DH)
		pthread_join(threadsId[p->i++], NULL);
	mlx_put_image_to_window(p->mlx_ptr, p->win_ptr, p->img.img_ptr, 0, 0);
	free(threadsId);
	free(threadData);
}