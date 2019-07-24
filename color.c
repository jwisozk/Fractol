/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwisozk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 14:05:44 by jwisozk           #+#    #+#             */
/*   Updated: 2019/07/24 18:20:32 by jwisozk          ###   ########.fr       */
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

int get_color(int current, int start, t_asset *p)
{
	int     red;
	int    	green;
	int    	blue;
	double  percentage;

	percentage = percent(start, p->MaxIter, current);
	if (p->key == 3)
	{
		red = get_light((0x000000 >> 16) & 0xFF, (0xFF0000 >> 16) & 0xFF, percentage);
		return (red << 16);
	}
	if (p->key == 4)
	{
		green = get_light((0x000000 >> 8) & 0xFF, (0x00FF00>> 8) & 0xFF, percentage);
		return (green << 8);
	}
	if (p->key == 5)
	{
		blue = get_light(0x000000 & 0xFF, 0x0000FF & 0xFF, percentage);
		return (blue);
	}
	else
	{
		red = get_light((0xFF0000 >> 16) & 0xFF, (0x000000 >> 16) & 0xFF, percentage);
		green = get_light((0x00FF00 >> 8) & 0xFF, (0x000000 >> 8) & 0xFF, percentage);
		blue = get_light(0x0000FF & 0xFF, 0x000000 & 0xFF, percentage);
		return ( (red << 16) | (green << 8) | blue);
	}
}

int ft_set_rgb(int r, int g, int b)
{
	return ((r << 16) | (g << 8) | b);
}

void ft_set_init_colors(t_asset *p)
{
	static int rgb[16] = {INIT_COLOR};
	p->rgb = rgb;
}
void ft_set_second_colors(t_asset *p)
{
	static int rgb[16] = {SCND_COLOR};
	p->rgb = rgb;
}
//void ft_set_random_colors(t_asset *p)
//{
//	int i;
//
//	i = 0;
//	while (i < 16)
//	{
//		p->rgb[i] = ft_set_rgb(rand() % 256, rand() % 256, rand() % 256);
//		i++;
//	}
//}