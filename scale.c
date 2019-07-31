/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scale.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwisozk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 17:27:57 by jwisozk           #+#    #+#             */
/*   Updated: 2019/07/31 13:40:27 by jwisozk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double interpolate(long double start, long double end, double interpolation)
{
	return start + (end - start) * interpolation;
}


void	ft_scale(t_asset *p, int x, int y, float scale)
{
	long double mouseRe;
	long double mouseIm;

	mouseRe = ft_map(x, DW, p->f.ReMin, p->f.ReMax);
	mouseIm = ft_map(y, DH, p->f.ImMin, p->f.ImMax);
//	mouseRe = (long double)x / (DW / (p->f.ReMax - p->f.ReMin)) + p->f.ReMin;
//	mouseIm = (long double)y / (DH / (p->f.ImMax - p->f.ImMin)) + p->f.ImMin;

	double interpolation =  1.0 / scale;
//	printf("ft_map = %Lf\n", ((long double)x - 0) / (DW - 0) * (p->f.ReMax - p->f.ReMin) + p->f.ReMin);
//	printf("ft_mape= %Lf\n", (long double)x / (DW / (p->f.ReMax - p->f.ReMin)) + p->f.ReMin);
//	printf("ft_mapo= %Lf\n", ft_map(x, 0, DW, p->f.ReMin, p->f.ReMax));
//	printf("x = %i mouseRe = %Lf\n", x, mouseRe);
//	printf("y = %i mouseIm = %Lf\n", y, mouseIm);
//	printf("double interpolation = %f\n", interpolation);
//	printf("p->f.ReMin - mouseRe = %Lf\n", p->f.ReMin - mouseRe);
//	printf("(p->f.ReMin - mouseRe) * interpolation = %Lf\n", (p->f.ReMin - mouseRe) * interpolation);
//	printf("mouseRe + (p->f.ReMin - mouseRe) * interpolation = %Lf\n", mouseRe + (p->f.ReMin - mouseRe) * interpolation);
	p->f.ReMin = interpolate(mouseRe, p->f.ReMin, interpolation);
	p->f.ImMin = interpolate(mouseIm, p->f.ImMin, interpolation);
	p->f.ReMax = interpolate(mouseRe, p->f.ReMax, interpolation);
	p->f.ImMax = interpolate(mouseIm, p->f.ImMax, interpolation);
}

