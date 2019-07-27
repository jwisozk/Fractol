/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scale.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwisozk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 17:27:57 by jwisozk           #+#    #+#             */
/*   Updated: 2019/07/23 20:51:02 by jwisozk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double interpolate(long double start, long double end, long double interpolation)
{
	return start + ((end - start) * interpolation);
}

void applyZoom(t_fractal* e, long double mouseRe, long double mouseIm, long double zoomFactor)
{
	double interpolation = 1.0 / zoomFactor;
	e->ReMin = interpolate(mouseRe, e->ReMin, interpolation);
	e->ImMin = interpolate(mouseIm, e->ImMin, interpolation);
	e->ReMax = interpolate(mouseRe, e->ReMax, interpolation);
	e->ImMax = interpolate(mouseIm, e->ImMax, interpolation);
//	printf("ReMin = %.100Lf\nReMax = %.100Lf\nImMin = %.100Lf\nImMax = %.100Lf\n\n\n\n", e->ReMin, e->ReMax, e->ImMin, e->ImMax);
}

void	ft_scale(t_fractal* e, int mouse_x, int mouse_y, long double scale)
{
	long double mouseRe;
	long double mouseIm;

	mouseRe = (long double)mouse_x / (DW / (e->ReMax - e->ReMin)) + e->ReMin;
	mouseIm = (long double)mouse_y / (DH / (e->ImMax - e->ImMin)) + e->ImMin;
//	printf("mouse_x = %i\nmouse_y = %i\nmouseRe = %Lf\nmouseIm = %Lf\n", mouse_x, mouse_y, mouseRe, mouseIm);
	applyZoom(e, mouseRe, mouseIm, scale);
}

