/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scale.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwisozk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 17:27:57 by jwisozk           #+#    #+#             */
/*   Updated: 2019/07/30 17:28:56 by jwisozk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double interpolate(long double start, long double end, double interpolation)
{
	return start + ((end - start) * interpolation);
}

void ft_zoom(t_asset* p, long double mouseRe, long double mouseIm, float scale)
{
	double interpolation =  1.0 / scale;
	p->f.ReMin = interpolate(mouseRe, p->f.ReMin, interpolation);
	p->f.ImMin = interpolate(mouseIm, p->f.ImMin, interpolation);
	p->f.ReMax = interpolate(mouseRe, p->f.ReMax, interpolation);
	p->f.ImMax = interpolate(mouseIm, p->f.ImMax, interpolation);
//	printf("ReMin = %.100Lf\nReMax = %.100Lf\nImMin = %.100Lf\nImMax = %.100Lf\n\n\n\n", e->ReMin, e->ReMax, e->ImMin, e->ImMax);
}

void	ft_scale(t_asset *p, int x, int y, float scale)
{
	long double mouseRe;
	long double mouseIm;

	mouseRe = ft_map(x, 0, DW, p->f.ReMin, p->f.ReMax);
	mouseIm = ft_map(y, 0, DH, p->f.ImMin, p->f.ImMax);
//	printf("mouse_x = %i\nmouse_y = %i\nmouseRe = %Lf\nmouseIm = %Lf\n", mouse_x, mouse_y, mouseRe, mouseIm);
	ft_zoom(p, mouseRe, mouseIm, scale);
}

