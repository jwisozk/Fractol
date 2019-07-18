/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwisozk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 14:05:44 by jwisozk           #+#    #+#             */
/*   Updated: 2019/07/18 14:10:15 by jwisozk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static double percent(int start, int end, int current)
{
	double placement;
	double distance;

	placement = current - start;
	distance = end - start;
	return ((distance == 0) ? 0.0 : (placement / distance));
}

static int get_light(int start, int end, double percentage)
{
	return ((int)((1 - percentage) * start + percentage * end));
}

int get_color(int current, int start, int end)
{
	int     red;
	int    	green;
	int    	blue;
	double  percentage;

	percentage = percent(start, end, current);
	red = get_light((0xb8860b >> 16) & 0xFF, (0xfafad2 >> 16) & 0xFF, percentage);
	green = get_light((0xb8860b >> 8) & 0xFF, (0xfafad2>> 8) & 0xFF, percentage);
	blue = get_light(0xb8860b & 0xFF, 0xfafad2 & 0xFF, percentage);

	return ( (red << 16) | (green << 8) | blue);
}

int ft_set_rgb(int r, int g, int b)
{
	return ((r << 16) | (g << 8) | b);
}

void ft_set_init_colors(t_asset *p)
{
	p->rgb[0] = ft_set_rgb(66, 30, 15);
	p->rgb[1] = ft_set_rgb(25, 7, 26);
	p->rgb[2] = ft_set_rgb(9, 1, 47);
	p->rgb[3] = ft_set_rgb(4, 4, 73);
	p->rgb[4] = ft_set_rgb(0, 7, 100);
	p->rgb[5] = ft_set_rgb(12, 44, 138);
	p->rgb[6] = ft_set_rgb(24, 82, 177);
	p->rgb[7] = ft_set_rgb(57, 125, 209);
	p->rgb[8] = ft_set_rgb(134, 181, 229);
	p->rgb[9] = ft_set_rgb(211, 236, 248);
	p->rgb[10] = ft_set_rgb(241, 233, 191);
	p->rgb[11] = ft_set_rgb(248, 201, 95);
	p->rgb[12] = ft_set_rgb(255, 170, 0);
	p->rgb[13] = ft_set_rgb(204, 128, 0);
	p->rgb[14] = ft_set_rgb(153, 87, 0);
	p->rgb[15] = ft_set_rgb(106, 52, 3);
}
void ft_set_random_colors(t_asset *p)
{
	int i;

	i = 0;
	while (i < 16)
	{
		p->rgb[i] = ft_set_rgb(rand() % 256, rand() % 256, rand() % 256);
		i++;
	}
}