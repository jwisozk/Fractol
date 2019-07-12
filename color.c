/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwisozk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 14:05:44 by jwisozk           #+#    #+#             */
/*   Updated: 2019/07/12 16:45:42 by jwisozk          ###   ########.fr       */
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
	red = get_light((0x000000 >> 16) & 0xFF, (0xFF0000 >> 16) & 0xFF, percentage);
	green = get_light((0x000000 >> 8) & 0xFF, (0x00FF00 >> 8) & 0xFF, percentage);
	blue = get_light(0x000000 & 0xFF, 0x0000FF & 0xFF, percentage);

	return ( (red << 16) | (green << 8) | blue);
}
