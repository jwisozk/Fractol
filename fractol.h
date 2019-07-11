/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwisozk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 19:36:19 by jwisozk           #+#    #+#             */
/*   Updated: 2019/07/05 19:36:22 by jwisozk          ###   ########.fr       */
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
# include <stdio.h>

#endif
