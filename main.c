/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwisozk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 13:28:03 by jwisozk           #+#    #+#             */
/*   Updated: 2019/07/23 16:44:45 by jwisozk          ###   ########.fr       */
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
//
//#include <pthread.h>
//#include <stdlib.h>
//#include <stdio.h>
//
////размеры матриц
//#define N 5
//#define M 5
//
////специальная структура для данных потока
//typedef struct{
//	int rowN; //номер обрабатываемой строки
//	int rowSize; //размер строки
//	//указатели на матрицы
//	int** array1;
//	int** array2;
//	int** resArr;
//} pthrData;
//
//void* threadFunc(void* thread_data){
//	//получаем структуру с данными
//	pthrData *data = (pthrData*) thread_data;
//
//	//складываем элементы строк матриц и сохраняем результат
//	for(int i = 0; i < data->rowSize; i++)
//		data->resArr[data->rowN][i] = data->array1[data->rowN][i] + data->array2[data->rowN][i];
//
//	return NULL;
//}
//
//int main(){
//	//выделяем память под двумерные массивы
//	int** matrix1 = (int**) malloc(N * sizeof(int*));
//	int** matrix2 = (int**) malloc(N * sizeof(int*));
//	int** resultMatrix = (int**) malloc(N * sizeof(int*));
//
//	//выделяем память под элементы матриц
//	for(int i = 0; i < M; i++){
//		matrix1[i] = (int*) malloc(M * sizeof(int));
//		matrix2[i] = (int*) malloc(M * sizeof(int));
//		resultMatrix[i] = (int*) malloc(M * sizeof(int));
//	}
//
//	//инициализируем начальными значениями
//	for(int i = 0; i < N; i++){
//		for(int j = 0; j < M; j++){
//			matrix1[i][j] = i;
//			matrix2[i][j] = j;
//			resultMatrix[i][j] = 0;
//		}
//	}
//
//	//выделяем память под массив идентификаторов потоков
//	pthread_t* threads = (pthread_t*) malloc(N * sizeof(pthread_t));
//	//сколько потоков - столько и структур с потоковых данных
//	pthrData* threadData = (pthrData*) malloc(N * sizeof(pthrData));
//
//	//инициализируем структуры потоков
//	for(int i = 0; i < N; i++){
//		threadData[i].rowN = i;
//		threadData[i].rowSize = M;
//		threadData[i].array1 = matrix1;
//		threadData[i].array2 = matrix2;
//		threadData[i].resArr = resultMatrix;
//
//		//запускаем поток
//		pthread_create(&(threads[i]), NULL, threadFunc, &threadData[i]);
//	}
//
//	//ожидаем выполнение всех потоков
//	for(int i = 0; i < N; i++)
//		pthread_join(threads[i], NULL);
//
//	for(int i = 0; i < N; i++){
//		for(int j = 0; j < M; j++)
//		{
//
////			matrix1[i][j] = i;
////			matrix2[i][j] = j;
//		printf("%i", resultMatrix[i][j]);
////			resultMatrix[i][j] = 0;
//		}
//		printf("\n");
//	}
//	//освобождаем память
//	free(threads);
//	free(threadData);
//	for(int i = 0; i < N; i++){
//		free(matrix1[i]);
//		free(matrix2[i]);
//		free(resultMatrix[i]);
//	}
//	free(matrix1);
//	free(matrix2);
//	free(resultMatrix);
//	return 0;
//}