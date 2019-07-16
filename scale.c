/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scale.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwisozk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 17:27:57 by jwisozk           #+#    #+#             */
/*   Updated: 2019/07/16 15:15:50 by jwisozk          ###   ########.fr       */
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
	e->Re.min = interpolate(mouseRe, e->Re.min, interpolation);
	e->Im.min = interpolate(mouseIm, e->Im.min, interpolation);
	e->Re.max = interpolate(mouseRe, e->Re.max, interpolation);
	e->Im.max = interpolate(mouseIm, e->Im.max, interpolation);
	printf("Re.min = %.20Lf\nRe.max = %.20Lf\nIm.min = %.20Lf\nIm.max = %.20Lf\n\n\n\n", e->Re.min, e->Re.max, e->Im.min, e->Im.max);
}

void	ft_scale(t_fractal* e, int mouse_x, int mouse_y, long double scale)
{
	long double mouseRe;
	long double mouseIm;

	mouseRe = (long double)mouse_x / (DW / (e->Re.max - e->Re.min)) + e->Re.min;
	mouseIm = (long double)mouse_y / (DH / (e->Im.max - e->Im.min)) + e->Im.min;
	printf("mouse_x = %i\nmouse_y = %i\nmouseRe = %Lf\nmouseIm = %Lf\n", mouse_x, mouse_y, mouseRe, mouseIm);
	applyZoom(e, mouseRe, mouseIm, scale);
}

