/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scale.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwisozk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 17:27:57 by jwisozk           #+#    #+#             */
/*   Updated: 2019/07/12 19:06:30 by jwisozk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double interpolate(double start, double end, double interpolation)
{
	return start + ((end - start) * interpolation);
}

void applyZoom(t_fractal* e, double mouseRe, double mouseIm, double zoomFactor)
{
	double interpolation = 1.0 / zoomFactor;
	e->Re.min = interpolate(mouseRe, e->Re.min, interpolation);
	e->Im.min = interpolate(mouseIm, e->Im.min, interpolation);
	e->Re.max = interpolate(mouseRe, e->Re.max, interpolation);
	e->Im.max = interpolate(mouseIm, e->Im.max, interpolation);
	printf("Re.min = %f\nRe.max = %f\nIm.min = %f\nIm.max = %f\n\n\n\n", e->Re.min, e->Re.max, e->Im.min, e->Im.max);
}

void	ft_scale(t_fractal* e, int mouse_x, int mouse_y, double scale)
{
	double mouseRe;
	double mouseIm;

	mouseRe = (double)mouse_x / (DW / (e->Re.max - e->Re.min)) + e->Re.min;
	mouseIm = (double)mouse_y / (DH / (e->Im.max - e->Im.min)) + e->Im.min;
	printf("mouse_x = %i\nmouse_y = %i\nmouseRe = %f\nmouseIm = %f\n", mouse_x, mouse_y, mouseRe, mouseIm);
	applyZoom(e, mouseRe, mouseIm, scale);
}

