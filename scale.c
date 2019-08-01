/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scale.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwisozk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 17:27:57 by jwisozk           #+#    #+#             */
/*   Updated: 2019/08/01 20:44:19 by jwisozk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	interpolate(long double start, long double end, double interpolation)
{
	return (start + (end - start) * interpolation);
}

void	ft_scale(t_asset *p, int x, int y, float scale)
{
	long double	mouse_x;
	long double	mouse_y;
	double		interpolation;

	mouse_x = ft_map(x, DW, p->f.remin, p->f.remax);
	mouse_y = ft_map(y, DH, p->f.immin, p->f.immax);
	interpolation = 1.0 / scale;
	p->f.remin = interpolate(mouse_x, p->f.remin, interpolation);
	p->f.immin = interpolate(mouse_y, p->f.immin, interpolation);
	p->f.remax = interpolate(mouse_x, p->f.remax, interpolation);
	p->f.immax = interpolate(mouse_y, p->f.immax, interpolation);
}
