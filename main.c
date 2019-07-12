/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwisozk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 13:28:03 by jwisozk           #+#    #+#             */
/*   Updated: 2019/07/12 19:09:32 by jwisozk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		ft_close_window(void)
{
	exit(0);
}

int		ft_key_press(int keycode)
{
	if (keycode == 53)
		ft_close_window();
	return (0);
}

void	ft_print_usage(void)
{
	ft_putstr("Usage: ./fractol [\n\t- Julia\n\t- Mandelbrot\n\t- optional\n]");
	ft_putchar('\n');
}

int		ft_mouse_press(int button, int x, int y, t_asset *p)
{
	mlx_clear_window(p->mlx_ptr, p->win_ptr);
	if (button == 5)
	{
		ft_scale(&p->e, x, DH - y, 10);
	}
	if (button == 4)
	{
		ft_scale(&p->e, x, y, 1.0 / 10);
	}
//	printf("scale = %f, x = %i, y = %i\n", p->scale, x, y);
	ft_draw_fractal(p->mlx_ptr, p->win_ptr, p);

//	if (button == 1)
//		p->press_mouse_l = 1;
//	if (button == 5 && scale < LIMIT_SCALE_UP)
//		ft_draw_fractal(mlx_ptr, win_ptr, 1.1, );
//		ft_scale(p, 1.1);
//	if (button == 4 && scale > LIMIT_SCALE_DOWN)
//		ft_scale(p, 0.9);
//	ft_draw_lines(p);
	return (0);
}



void	ft_open_window(void)
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_asset	p;
	t_fractal e;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, DW, DH, "Fractal");

//	float MinRe = -2.5;
//	float MaxRe = 1.0;
//	float MinIm = -1.1;
//	float MaxIm = 1.1;

	p.mlx_ptr = mlx_ptr;
	p.win_ptr = win_ptr;
	p.scale = 1.0;
	p.ix = 0;
	p.iy = 0;
	e.Re.min = -2.5;
	e.Re.max = 1.0;
	e.Im.min = -1.1;
	e.Im.max = 1.1;
	p.e = e;

//	p->mlx_ptr = mlx_ptr;
//	p->win_ptr = win_ptr;
//	ft_add_coords(p);
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
