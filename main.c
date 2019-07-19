/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwisozk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 13:28:03 by jwisozk           #+#    #+#             */
/*   Updated: 2019/07/19 16:46:50 by jwisozk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_print_usage(void)
{
	ft_putstr("Usage: ./fractol [\n\t- Julia\n\t- Mandelbrot\n\t- optional\n]");
	ft_putchar('\n');
}

//void *mlx_new_image(void *mlx_ptr, int width, int height);
//char *mlx_get_data_addr(void *img_ptr, int *bits_per_pixel, int *size_line, int *endian);
//int mlx_put_image_to_window(void *mlx_ptr, void *win_ptr, void *img_ptr, int x, int y);

void	ft_open_window(void)
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_asset	p;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, DW, DH, "Fractal");
	p.img.img_ptr = mlx_new_image(mlx_ptr, DW, DH);
	p.img.img = (int*)mlx_get_data_addr(p.img.img_ptr, &p.img.bits_per_pixel, &p.img.size_line, &p.img.endian);

	p.mlx_ptr = mlx_ptr;
	p.win_ptr = win_ptr;
	p.f.Re.min = RE_MIN;
	p.f.Re.max = RE_MAX;
	p.f.Im.min = IM_MIN;
	p.f.Im.max = IM_MAX;
	p.iter = MAX_ITER;

	p.key = 1;
	ft_set_init_colors(&p);
	printf("key = %i\n", p.key);
	ft_draw_fractal(&p);
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