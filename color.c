/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwisozk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 14:05:44 by jwisozk           #+#    #+#             */
/*   Updated: 2019/07/31 19:11:26 by jwisozk          ###   ########.fr       */
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

int get_color(int current, t_asset *p)
{
	int     red;
	int    	green;
	int    	blue;
	double  percentage;

	percentage = percent(0, p->MaxIter, current);
	if (p->key == 4)
	{
		red = get_light((0x000000 >> 16) & 0xFF, (0xFF0000 >> 16) & 0xFF, percentage);
		return (red << 16);
	}
	else
	{
		red = get_light((0xFF0000 >> 16) & 0xFF, (0x000000 >> 16) & 0xFF, percentage);
		green = get_light((0x00FF00  >> 8) & 0xFF, (0x000000 >> 8) & 0xFF, percentage);
		blue = get_light(0x0000FF  & 0xFF, 0x000000 & 0xFF, percentage);
		return ( (red << 16) | (green << 8) | blue);
	}
}

int ft_smooth_color(int n, t_asset *p)
{
	double t = (double)n / (double)p->MaxIter;

	int r = (int)(9 * (1 - t) * t * t * t * 255);
	int g = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
	int b =  (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
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