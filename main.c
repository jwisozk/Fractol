/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwisozk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 13:28:03 by jwisozk           #+#    #+#             */
/*   Updated: 2019/07/23 20:51:02 by jwisozk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_print_usage(void)
{
	ft_putstr("Usage: ./fractol [\n\t- Julia\n\t- Mandelbrot\n\t- optional\n]");
	ft_putchar('\n');
}
void	ft_init_fractal(t_asset *p)
{
	p->f.ReMin = RE_MIN;
	p->f.ReMax = RE_MAX;
	p->f.ImMin = IM_MIN;
	p->f.ImMax = IM_MAX;
	p->MaxIter = MAX_ITER;
	p->key = 1;
	ft_set_init_colors(p);
}

void	ft_init_fractals(t_asset *main, t_asset *p)
{
	if (main->key == 1)
		ft_set_init_colors(p);
	if (main->key == 2)
		ft_set_second_colors(p);
	p->delta.Re = main->delta.Re;
	p->point.y = main->point.y;
	p->f.ReMin = main->f.ReMin;
	p->MaxIter = main->MaxIter;
	p->key = main->key;
	p->i = main->i;
	p->img.img_arr = main->img.img_arr;
}

void	ft_open_window(void)
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_asset	p;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, DW, DH, "Fractal");
	p.img.img_ptr = mlx_new_image(mlx_ptr, DW, DH);
	p.img.img_arr = (int*)mlx_get_data_addr(p.img.img_ptr, &p.img.bits_per_pixel, &p.img.size_line, &p.img.endian);
	p.mlx_ptr = mlx_ptr;
	p.win_ptr = win_ptr;
	ft_init_fractal(&p);
	ft_draw_mandelbrot(&p);
	mlx_hook(win_ptr, 17, 0, ft_close_window, 0);
	mlx_hook(win_ptr, 2, 0, ft_key_press, &p);
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