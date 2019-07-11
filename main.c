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

//int mlx_pixel_put(void *mlx_ptr, void *win_ptr, int x, int y, int color);

//void	ft_scale(t_param *p, float scale)
//{
//	int	i;
//	int	j;
//
//	i = 0;
//	while (i < p->len_y)
//	{
//		j = 0;
//		while (j < p->len_x)
//		{
//			p->arr_lst[i][j].x = p->arr_lst[i][j].x * scale;
//			p->arr_lst[i][j].y = p->arr_lst[i][j].y * scale;
//			p->arr_lst[i][j].z = p->arr_lst[i][j].z * scale;
//			j++;
//		}
//		i++;
//	}
//}
//

void	ft_draw_fractal(void *mlx_ptr, void *win_ptr, t_asset *p)
{
	float MinRe = -2.5;
	float MaxRe = 1.0;
	float MinIm = -1.1;
	float MaxIm = 1.1;
	//	float scale = 1.5;
	//	float xm = 300;
	//	float ym = 300;
	//
	float point[2];
	float Re_coef =(MaxRe - MinRe) / ((DW - 1) * p->scale);
	float Im_coef =(MaxIm - MinIm) / ((DH - 1) * p->scale);
	int MaxIterations = 30;
	int i;
	int j;
	int k;
	float x;
	float y;
	float t;

	point[1] = MaxIm;
	i = 0;
	while (i < DH * p->scale)
	{
		j = 0;
		point[0] = MinRe;
		while (j < DW * p->scale)
		{
			x = 0.0;
			y = 0.0;
			k = 0;
			while (x * x + y * y <= 4 && k < MaxIterations)
			{
				t = x * x - y * y + point[0];
				y = 2 * x * y + point[1];
				x = t;
				k++;
			}
			if(k == MaxIterations)
				mlx_pixel_put(mlx_ptr, win_ptr, j - p->ix, i - p->iy, 0xFF0000);
			point[0] += Re_coef;
			j++;
		}
		point[1] -= Im_coef;
		i++;
	}
}

int		ft_mouse_press(int button, int x, int y, t_asset *p)
{
	mlx_clear_window(p->mlx_ptr, p->win_ptr);
	if (button == 5 && p->scale < 10)
	{
		p->ix += x;
		p->iy += y;
		p->scale += 1;
	}
	if (button == 4 && p->scale > 1)
	{
		p->ix -= x;
		p->iy -= y;
		p->scale -= 1;
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

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, DW, DH, "Fractal");

	p.mlx_ptr = mlx_ptr;
	p.win_ptr = win_ptr;
	p.scale = 1.0;
	p.ix = 0;
	p.iy = 0;

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
