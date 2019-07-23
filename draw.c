/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwisozk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 16:59:55 by jwisozk           #+#    #+#             */
/*   Updated: 2019/07/23 18:46:19 by jwisozk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

//void *ft_row(void *data)
//{
//	t_asset *p;
//
//	p = (t_asset *)data;
//	int k;
//	int n;
//	int j;
//
//	p->point.x = p->f.ReMin;
//	j = 0;
//	while (j < DW)
//	{
//		p->x = 0.0;
//		p->y = 0.0;
//		k = 0;
//		while (p->x * p->x + p->y * p->y <= 4 && k < p->MaxIter)
//		{
//			p->t = p->x *p->x - p->y * p->y + p->point.x;
//			p->y = 2 * p->x * p->y + p->point.y;
//			p->x = p->t;
//			k++;
//		}
//		if (k < p->MaxIter)
//		{
//			if (p->key == 1 || p->key == 2)
//			{
//				n = k % 16;
//				p->img.img_arr[p->i*DW + j] = p->rgb[n];
//			}
//			else
//				p->img.img_arr[p->i*DW + j] = get_color(k, 0, p);
//		}
//		else
//			p->img.img_arr[p->i*DW + j] = 0x000000;
//		p->point.x += p->delta.Re;
//		j++;
//	}
//	return (NULL);
////	pthread_exit(0);
//}
//void	ft_draw_fractal(t_asset *p)
//{
//	int i;
//
//	//выделяем память под массив идентификаторов потоков
//	pthread_t* threads = (pthread_t*)malloc(DH * sizeof(pthread_t));
//	//сколько потоков - столько и структур с потоковых данных
//	t_asset* threadData = (t_asset*)malloc(DH * sizeof(t_asset));
//
//
//	p->delta.Re = (p->f.ReMax - p->f.ReMin) / ((DW - 1));
//	p->delta.Im = (p->f.ImMax - p->f.ImMin) / ((DH - 1));
//
//	p->point.y = p->f.ImMax;
//	i = 0;
//	while (i < DH)
//	{
//		threadData[i].delta.Re = p->delta.Re;
//		threadData[i].point.y = p->point.y;
//		threadData[i].f.ReMin = p->f.ReMin;
//		threadData[i].MaxIter = p->MaxIter;
//		threadData[i].key = p->key;
//		threadData[i].i = i;
////		ft_row(threadData);
//		pthread_create(&(threads[i]), NULL, ft_row, &threadData[i]);
//
//		threadData[i].point.y -= p->delta.Im;
//		//p->point.y -= p->delta.Im;
//		i++;
//	}
//	i = 0;
//	while (i < DH)
//	{
//		pthread_join(threads[i], NULL);
//		i++;
//	}
////	p->img.img_arr = threadData[i].img.img_arr;
//
////	p->img.img_arr;
//
//
//	mlx_put_image_to_window(p->mlx_ptr, p->win_ptr, p->img.img_ptr, 0, 0);
//}

void *ft_row(void *data)
{
	t_asset *p;

	p = (t_asset *) data;
	int k;
	int n;
	int j;

	p->point.x = p->f.ReMin;
	j = 0;
	while (j < DW)
	{
		p->x = 0.0;
		p->y = 0.0;
		k = 0;
		while (p->x * p->x + p->y * p->y <= 4 && k < p->MaxIter)
		{
			p->t = p->x * p->x - p->y * p->y + p->point.x;
			p->y = 2 * p->x * p->y + p->point.y;
			p->x = p->t;
			k++;
		}
		if (k < p->MaxIter)
		{
			if (p->key == 1 || p->key == 2)
			{
				n = k % 16;
				p->img.img_arr[p->i * DW + j] = p->rgb[n];
			}
			else
				p->img.img_arr[p->i * DW + j] = get_color(k, 0, p);
		}
		else
			p->img.img_arr[p->i * DW + j] = 0x000000;
		p->point.x += p->delta.Re;
		j++;
	}
	return (NULL);
}

void	ft_draw_fractal(t_asset *p)
{
	pthread_t* threadsId;
	t_asset* threadData;

	//выделяем память под массив идентификаторов потоков
	threadsId = (pthread_t*) malloc(DH * sizeof(pthread_t));
	//сколько потоков - столько и структур с потоковых данных
	threadData = (t_asset*) malloc(DH * sizeof(t_asset));

	p->delta.Re = (p->f.ReMax - p->f.ReMin) / ((DW - 1));
	p->delta.Im = (p->f.ImMax - p->f.ImMin) / ((DH - 1));
	p->point.y = p->f.ImMin;

	//инициализируем структуры потоков
	p->i = 0;
	while (p->i < DH)
	{
		if (p->key == 1)
			ft_set_init_colors(&threadData[p->i]);
		if (p->key == 2)
			ft_set_second_colors(&threadData[p->i]);
		threadData[p->i].delta.Re = p->delta.Re;
		threadData[p->i].point.y = p->point.y;
		threadData[p->i].f.ReMin = p->f.ReMin;
		threadData[p->i].MaxIter = p->MaxIter;
		threadData[p->i].key = p->key;
		threadData[p->i].i = p->i;
		threadData[p->i].img.img_arr = p->img.img_arr;
		pthread_create(&(threadsId[p->i]), NULL, ft_row, &threadData[p->i]);
		p->point.y += p->delta.Im;
		p->i++;
	}

	//ожидаем выполнение всех потоков
	p->i = 0;
	while (p->i < DH)
	{
		pthread_join(threadsId[p->i], NULL);
		p->i++;
	}

	mlx_put_image_to_window(p->mlx_ptr, p->win_ptr, p->img.img_ptr, 0, 0);
	free(threadsId);
	free(threadData);
}

//void *ft_row(void *data)
//{
//	t_asset *p;
//
//	p = (t_asset *) data;
//	int k;
//	int n;
//	int j;
//
//	p->point.x = p->f.ReMin;
//	j = 0;
//	while (j < DW)
//	{
//		p->x = 0.0;
//		p->y = 0.0;
//		k = 0;
//		while (p->x * p->x + p->y * p->y <= 4 && k < p->MaxIter)
//		{
//			p->t = p->x * p->x - p->y * p->y + p->point.x;
//			p->y = 2 * p->x * p->y + p->point.y;
//			p->x = p->t;
//			k++;
//		}
//		if (k < p->MaxIter)
//		{
//			if (p->key == 1 || p->key == 2)
//			{
//				n = k % 16;
//				p->img.img_arr[p->i * DW + j] = p->rgb[n];
//			}
//			else
//				p->img.img_arr[p->i * DW + j] = get_color(k, 0, p);
//		}
//		else
//			p->img.img_arr[p->i * DW + j] = 0x000000;
//		p->point.x += p->delta.Re;
//		j++;
//	}
//	return (NULL);
//}
//
//void	ft_draw_fractal(t_asset *p)
//{
//	p->delta.Re = (p->f.ReMax - p->f.ReMin) / ((DW - 1));
//	p->delta.Im = (p->f.ImMax - p->f.ImMin) / ((DH - 1));
//	p->point.y = p->f.ImMax;
//	p->i = 0;
//	while (p->i < DH)
//	{
//
//		ft_row(p);
//		p->point.y -= p->delta.Im;
//		p->i++;
//	}
//	mlx_put_image_to_window(p->mlx_ptr, p->win_ptr, p->img.img_ptr, 0, 0);
//}
