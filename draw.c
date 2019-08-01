/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwisozk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 16:59:55 by jwisozk           #+#    #+#             */
/*   Updated: 2019/08/01 20:31:31 by jwisozk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_put_color(t_asset *p, int iter)
{
	int n;

	if (iter < p->maxiter)
	{
		if (p->key == 1)
		{
			n = iter % 16;
			p->img.img_arr[p->i * DW + p->j] = p->rgb[n];
		}
		else if (p->key == 2)
		{
			p->img.img_arr[p->i * DW + p->j] = ft_smooth_color(iter, p);
		}
		else
			p->img.img_arr[p->i * DW + p->j] = get_color(iter, p);
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
	while (iter < p->maxiter)
	{
		p->dx = p->x * p->x;
		p->dy = p->y * p->y;
		if (p->dx + p->dy > 4.0)
			break ;
		if (p->ship == 1)
			p->y = 2.0 * fabs((float)p->x * (float)p->y) + p->cy;
		else
			p->y = 2.0 * p->x * p->y + p->cy;
		p->x = p->dx - p->dy + p->cx;
		iter++;
	}
	ft_put_color(p, iter);
}

void	*ft_row(void *data)
{
	t_asset *p;

	p = (t_asset *)data;
	p->point.x = p->f.remin;
	p->j = 0;
	while (p->j < DW)
	{
		ft_get_iter(p);
		p->point.x += p->delta.re;
		p->j++;
	}
	return (NULL);
}

void	ft_put_image(t_asset *p, pthread_t *thrs_id, t_asset *thread_data)
{
	p->i = 0;
	while (p->i < DH)
		if (pthread_join(thrs_id[p->i++], NULL) != 0)
			ft_print_error("Error: the threads has not been joined.");
	mlx_put_image_to_window(p->mlx_ptr, p->win_ptr, p->img.img_ptr, 0, 0);
	p->str = ft_strjoin("Max iteration: ", ft_itoa(p->maxiter));
	p->str = ft_strjoin(p->str, " Zoom: ");
	p->str = ft_strjoin(p->str, ft_itoa(p->zoom));
	p->str = ft_strjoin(p->str, "/50");
	mlx_string_put(p->mlx_ptr, p->win_ptr, 21, DH - 39, 0xFF0000, p->str);
	mlx_string_put(p->mlx_ptr, p->win_ptr, 20, DH - 40, 0xFFAA00, p->str);
	free(thrs_id);
	free(thread_data);
}

void	ft_draw_fractal(t_asset *p)
{
	pthread_t	*thrs_id;
	t_asset		*thread_data;
	int			s;

	thrs_id = (pthread_t*)malloc(DH * sizeof(pthread_t));
	thread_data = (t_asset*)malloc(DH * sizeof(t_asset));
	if (thrs_id == NULL || thread_data == NULL)
		ft_print_error("Error: malloc didn't allocate memory.");
	p->delta.re = (p->f.remax - p->f.remin) / (DW - 1);
	p->delta.im = (p->f.immax - p->f.immin) / (DH - 1);
	p->point.y = p->f.immin;
	p->i = 0;
	while (p->i < DH)
	{
		ft_init_fractals(p, &thread_data[p->i]);
		s = pthread_create(&(thrs_id[p->i]), NULL, ft_row, &thread_data[p->i]);
		if (s != 0)
			ft_print_error("Error: the thread has not been created.");
		p->point.y += p->delta.im;
		p->i++;
	}
	ft_put_image(p, thrs_id, thread_data);
}
