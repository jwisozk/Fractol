/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwisozk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 16:59:55 by jwisozk           #+#    #+#             */
/*   Updated: 2019/07/27 17:18:27 by jwisozk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		ft_print_error(char *str)
{
	ft_putstr(str);
	ft_putchar('\n');
	exit(0);
}

void	ft_put_color(t_asset *p, int iter)
{
	int n;

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

void	ft_get_iter(t_asset *p)
{
	int iter;

	if (p->julia != 1)
	{
		p->cx = p->point.x;
		p->cy = p->point.y;
	}
	p->x = p->point.x;
	p->y = p->point.y;
	iter = 0;
	while (iter < p->MaxIter)
	{
		p->dx = p->x * p->x;
		p->dy = p->y * p->y;
		if (p->dx + p->dy > 4.0)
			break ;
		p->y = 2.0 * p->x * p->y + p->cy;
		p->x = p->dx - p->dy + p->cx;
		iter++;
	}
	ft_put_color(p, iter);
}

void *ft_row(void *data)
{
	t_asset *p;

	p = (t_asset *) data;
	p->point.x = p->f.ReMin;
	p->j = 0;
	while (p->j < DW)
	{
		ft_get_iter(p);
		p->point.x += p->delta.Re;
		p->j++;
	}
	return (NULL);
}

void	ft_draw_fractal(t_asset *p)
{
	pthread_t* threadsId;
	t_asset* threadData;
	int s;

	threadsId = (pthread_t*) malloc(DH * sizeof(pthread_t));
	threadData = (t_asset*) malloc(DH * sizeof(t_asset));
	if (threadsId == NULL || threadData == NULL)
		ft_print_error("Error: malloc didn't allocate memory.");
	p->delta.Re = (p->f.ReMax - p->f.ReMin) / (DW - 1);
	p->delta.Im = (p->f.ImMax - p->f.ImMin) / (DH - 1);
	p->point.y = p->f.ImMin;
	p->i = 0;
	while (p->i < DH)
	{
		ft_init_fractals(p, &threadData[p->i]);
		s = pthread_create(&(threadsId[p->i]), NULL, ft_row, &threadData[p->i]);
		if (s != 0)
			ft_print_error("Error: the thread has not been created.");
		p->point.y += p->delta.Im;
		p->i++;
	}
	p->i = 0;
	while (p->i < DH)
		if (pthread_join(threadsId[p->i++], NULL) != 0)
			ft_print_error("Error: the threads has not been joined.");
	mlx_put_image_to_window(p->mlx_ptr, p->win_ptr, p->img.img_ptr, 0, 0);
	p->str = ft_strjoin("Max iterations: ", ft_itoa(p->MaxIter));
	mlx_string_put(p->mlx_ptr, p->win_ptr, 21, DH - 39, 0xFF0000, p->str);
	mlx_string_put(p->mlx_ptr, p->win_ptr, 20, DH - 40, 0xFFAA00, p->str);
	free(threadsId);
	free(threadData);
}