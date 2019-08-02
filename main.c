/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwisozk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 13:28:03 by jwisozk           #+#    #+#             */
/*   Updated: 2019/08/02 14:54:34 by jwisozk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	ft_print_usage(void)
{
	ft_putstr("Usage: ./fractol "\
	"[\n\t- Julia\n\t- Mandelbrot\n\t- BurningShip\n]" \
	"[optional: Julia, Mandelbrot, BurningShip]");
	ft_putchar('\n');
	exit(0);
}

void		ft_init_fractal(t_asset *p)
{
	long double w;
	long double h;

	w = RE_LEN;
	h = (w * DH) / DW;
	p->f.remin = -w / 2;
	p->f.remax = p->f.remin + w;
	p->f.immin = -h / 2;
	p->f.immax = p->f.immin + h;
	p->maxiter = MAX_ITER;
	p->key = 1;
	p->ship = 0;
	p->julia = 0;
	p->julia_move = 0;
	p->cx = CX;
	p->cy = CY;
	p->zoom = 0;
	ft_set_init_colors(p);
}

void		ft_init_fractals(t_asset *main, t_asset *p)
{
	ft_set_init_colors(p);
	p->delta.re = main->delta.re;
	p->point.y = main->point.y;
	p->f.remin = main->f.remin;
	p->maxiter = main->maxiter;
	p->key = main->key;
	p->i = main->i;
	p->ship = main->ship;
	p->julia = main->julia;
	p->julia_move = main->julia;
	p->cx = main->cx;
	p->cy = main->cy;
	p->img.img_arr = main->img.img_arr;
}

void		ft_open_window(int n, char **name, void *mlx_ptr, int i)
{
	void	*win_ptr;
	t_asset	p[n];

	while (i < n)
	{
		win_ptr = mlx_new_window(mlx_ptr, DW, DH + HEADER, name[i]);
		p[i].img.img_ptr = mlx_new_image(mlx_ptr, DW, DH);
		p[i].img.img_arr = (int*)mlx_get_data_addr(p[i].img.img_ptr,
				&p[i].img.bit_per_pixel, &p[i].img.size_line, &p[i].img.endian);
		p[i].mlx_ptr = mlx_ptr;
		p[i].win_ptr = win_ptr;
		p[i].windows = &n;
		ft_init_fractal(&p[i]);
		if (ft_strequ("Julia", name[i]))
			p[i].julia = 1;
		if (ft_strequ("BurningShip", name[i]))
			p[i].ship = 1;
		ft_draw_fractal(&p[i]);
		mlx_hook(win_ptr, 17, 0, ft_close_window, &p[i]);
		mlx_hook(win_ptr, 2, 0, ft_key_press, &p[i]);
		mlx_hook(win_ptr, 4, 0, ft_mouse_press, &p[i]);
		mlx_hook(win_ptr, 6, 0, ft_mouse_move, &p[i]);
		i++;
	}
	mlx_loop(mlx_ptr);
}

int			main(int argc, char **argv)
{
	char	*name[2];
	int		i;
	void	*mlx_ptr;

	if (argc == 2 || argc == 3)
	{
		mlx_ptr = mlx_init();
		i = 0;
		while (i < argc - 1)
		{
			name[i] = *(argv + 1 + i);
			if (ft_strequ("Mandelbrot", name[i]) +
				ft_strequ("Julia", name[i]) +
				ft_strequ("BurningShip", name[i]) == 0)
				ft_print_usage();
			i++;
		}
		i = 0;
		ft_open_window(argc - 1, name, mlx_ptr, i);
	}
	else
		ft_print_usage();
	return (0);
}
