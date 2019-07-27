/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwisozk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 13:28:03 by jwisozk           #+#    #+#             */
/*   Updated: 2019/07/27 18:53:39 by jwisozk          ###   ########.fr       */
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
	long double w = RE_LEN;
	long double h = (w * DH) / DW;

	p->f.ReMin = -w / 2;
	p->f.ReMax = p->f.ReMin + w;
	p->f.ImMin = -h / 2;
	p->f.ImMax = p->f.ImMin + h;
	p->MaxIter = MAX_ITER;
	p->key = 1;
	p->julia = 0;
	p->julia_move = 0;
	p->cx = CX;
	p->cy = CY;
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
	p->julia = main->julia;
	p->julia_move = main->julia;
	p->cx = main->cx;
	p->cy = main->cy;
	p->img.img_arr = main->img.img_arr;
}

void	ft_open_window(int n, char **name)
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_asset	p[n];
	int 	windows;
	int i;

	mlx_ptr = mlx_init();
	windows = n;
	i = 0;
	while (i < n)
	{
		win_ptr = mlx_new_window(mlx_ptr, DW, DH + HEADER, name[i]);
		p[i].img.img_ptr = mlx_new_image(mlx_ptr, DW, DH);
		p[i].img.img_arr = (int*)mlx_get_data_addr(p[i].img.img_ptr, &p[i].img.bits_per_pixel, &p[i].img.size_line, &p[i].img.endian);
		p[i].mlx_ptr = mlx_ptr;
		p[i].win_ptr = win_ptr;
		p[i].windows = &windows;
		ft_init_fractal(&p[i]);
		if (ft_strequ("Julia", name[i]))
			p[i].julia = 1;
		ft_draw_fractal(&p[i]);
		mlx_hook(win_ptr, 17, 0, ft_close_window, 0);
		mlx_hook(win_ptr, 2, 0, ft_key_press, &p[i]);
		mlx_hook(win_ptr, 4, 0, ft_mouse_press, &p[i]);
		//	mlx_hook(win_ptr, 5, 0, ft_mouse_release, p);
		mlx_hook(win_ptr, 6, 0, ft_mouse_move, &p[i]);
		i++;
	}
	mlx_loop(mlx_ptr);
}

int		main(int argc, char **argv)
{
	char	*name[2];
	int 	i;

	if (argc == 2 || argc == 3)
	{
		i = 0;
		while (i < argc - 1)
		{
			name[i] = *(argv + 1 + i);
			i++;
		}
		ft_open_window(argc - 1, name);
	}
	else
		ft_print_usage();
	return (0);
}