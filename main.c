/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwisozk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 13:28:03 by jwisozk           #+#    #+#             */
/*   Updated: 2019/07/16 12:36:45 by jwisozk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_print_usage(void)
{
	ft_putstr("Usage: ./fractol [\n\t- Julia\n\t- Mandelbrot\n\t- optional\n]");
	ft_putchar('\n');
}

void	ft_open_window(void)
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_asset	p;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, DW, DH, "Fractal");

	p.mlx_ptr = mlx_ptr;
	p.win_ptr = win_ptr;
	p.scale = 0;
	p.f.Re.min = RE_MIN;
	p.f.Re.max = RE_MAX;
	p.f.Im.min = IM_MIN;
	p.f.Im.max = IM_MAX;
	p.iter = MAX_ITER;
	p.zoom = 1;
	p.rgb[0] = ft_set_rgb(66, 30, 15);
	p.rgb[1] = ft_set_rgb(25, 7, 26);
	p.rgb[2] = ft_set_rgb(9, 1, 47);
	p.rgb[3] = ft_set_rgb(4, 4, 73);
	p.rgb[4] = ft_set_rgb(0, 7, 100);
	p.rgb[5] = ft_set_rgb(12, 44, 138);
	p.rgb[6] = ft_set_rgb(24, 82, 177);
	p.rgb[7] = ft_set_rgb(57, 125, 209);
	p.rgb[8] = ft_set_rgb(134, 181, 229);
	p.rgb[9] = ft_set_rgb(211, 236, 248);
	p.rgb[10] = ft_set_rgb(241, 233, 191);
	p.rgb[11] = ft_set_rgb(248, 201, 95);
	p.rgb[12] = ft_set_rgb(255, 170, 0);
	p.rgb[13] = ft_set_rgb(204, 128, 0);
	p.rgb[14] = ft_set_rgb(153, 87, 0);
	p.rgb[15] = ft_set_rgb(106, 52, 3);


	ft_draw_fractal(mlx_ptr, win_ptr, &p);
	mlx_hook(win_ptr, 17, 0, ft_close_window, 0);
	mlx_hook(win_ptr, 2, 0, ft_key_press, 0);
	mlx_hook(win_ptr, 4, 0, ft_mouse_press, &p);
//	mlx_hook(win_ptr, 5, 0, ft_mouse_release, p);
//	mlx_hook(win_ptr, 6, 0, ft_mouse_move, p);
	mlx_loop(mlx_ptr);
}

int		main(int argc, char **argv)
{
	char	*name;

	if (argc == 2)
	{
		name = *(argv + 1);
		ft_open_window();
	}
	else
		ft_print_usage();
	return (0);
}
