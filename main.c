#include "fractol.h"

void	ft_print_usage(void)
{
	ft_putstr("Usage: ./fractol [\n\t- Julia\n\t- Mandelbrot\n\t- optional\n]");
	ft_putchar('\n');
}

//int mlx_pixel_put(void *mlx_ptr, void *win_ptr, int x, int y, int color);

void	ft_draw_fractal(void *mlx_ptr, void *win_ptr)
{
	double MinRe = -2.0;
	double MaxRe = 1.0;
	double MinIm = -1.2;
	double MaxIm = 1.0;
	double Re_factor = (MaxRe-MinRe)/(DW-1);
	double Im_factor = (MaxIm-MinIm)/(DH-1);
	unsigned MaxIterations = 30;

	for(unsigned y=0; y<DH; ++y)
	{
		double c_im = MaxIm - y*Im_factor;
		for(unsigned x=0; x<DW; ++x)
		{
			double c_re = MinRe + x*Re_factor;

			double Z_re = c_re, Z_im = c_im;
			int isInside = 1;
			for(unsigned n=0; n<MaxIterations; ++n)
			{
				double Z_re2 = Z_re*Z_re, Z_im2 = Z_im*Z_im;
				if(Z_re2 + Z_im2 > 4)
				{
					isInside = 0;
					break;
				}
				Z_im = 2*Z_re*Z_im + c_im;
				Z_re = Z_re2 - Z_im2 + c_re;
			}
			if(isInside) { mlx_pixel_put(mlx_ptr, win_ptr,  x, y, 0xFF0000); }
		}
	}
}

void	ft_open_window()
{
	void	*mlx_ptr;
	void	*win_ptr;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, DW, DH, "Fractal");
//	p->mlx_ptr = mlx_ptr;
//	p->win_ptr = win_ptr;
//	ft_add_coords(p);
	ft_draw_fractal(mlx_ptr, win_ptr);
//	mlx_hook(win_ptr, 17, 0, ft_close_window, p);
//	mlx_hook(win_ptr, 2, 0, ft_key_press, p);
//	mlx_hook(win_ptr, 4, 0, ft_mouse_press, p);
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
