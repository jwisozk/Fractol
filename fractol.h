/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwisozk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 13:27:05 by jwisozk           #+#    #+#             */
/*   Updated: 2019/07/12 15:14:10 by jwisozk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <math.h>
# include "libft/libft.h"
# include "/usr/local/include/mlx.h"
# define DW 1600
# define DH 900

typedef struct 	s_asset
{
	void		*mlx_ptr;
	void		*win_ptr;
	float 		scale;
	int 		ix;
	int 		iy;
}				t_asset;

typedef struct 	s_point
{
	int x;
	int y;
	int color;
}				t_point;
int get_color(int current, int start, int end);


# include <stdio.h>

#endif
