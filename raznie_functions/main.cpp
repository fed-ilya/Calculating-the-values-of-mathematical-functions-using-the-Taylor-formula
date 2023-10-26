#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#define _USE_MARH_DEFINES
#include <math.h>
#include "Header.h"

#define double long double

int main() {
	setlocale(LC_CTYPE, "Russian");
	double a, b, h; //a- Левая граница, b- Правая граница, x- точка, h- шаг, значение функции в которой мы рассматриваем
	double* x_mas, * fx, * fx_p, * mas_delta; //Массивы со значениями

	int n; //n- кол-во слагаемых(Максимальная степень)
	int size;

	printf("Введите через пробел левую и правую границу\n");
	scanf_s("%lf%lf", &a, &b);

	printf("Введите через пробел шаг и кол-во слагаемых\n");
	scanf_s("%lf%i", &h, &n);

	size = (b - a) / h + 1;

	x_mas = (double*)malloc(size * sizeof(double));
	fx = (double*)malloc(size * sizeof(double));
	fx_p = (double*)malloc(size * sizeof(double));
	mas_delta = (double*)malloc(size * sizeof(double));

	printf("\nНажмите '1'- функция экспоненты\n");
	printf("Нажмите '2'- функция синуса\n");
	printf("Нажмите '3'- функция косинуса\n");
	printf("Нажмите '4'- функция логарифма\n");
	printf("Нажмите '0'- чтобы ввести новые \n\n");

	while (1)
	{
		int kod;
		int i = 0;
		int k = 20;
		double max_delta;
		scanf_s("%i", &kod);
		switch (kod)
		{
		case 1:
			inicializy(x_mas, fx_p, fx, mas_delta, size, a, h, n, exp_p, exp);
			k = razmetka(fx_p, fx, size, &k);
			print_mas(x_mas, fx_p, fx, mas_delta, size, k);
			break;

		case 2:
			inicializy(x_mas, fx_p, fx, mas_delta, size, a, h, n, sin_p, sin);
			k = razmetka(fx_p, fx, size, &k);
			print_mas(x_mas, fx_p, fx, mas_delta, size, k);
			break;

		case 3:
			inicializy(x_mas, fx_p, fx, mas_delta, size, a, h, n, cos_p, cos);
			k = razmetka(fx_p, fx, size, &k);
			print_mas(x_mas, fx_p, fx, mas_delta, size, k);
			break;
		case 4:
			inicializy(x_mas, fx_p, fx, mas_delta, size, a, h, n, log_p, log);
			k = razmetka(fx_p, fx, size, &k);
			print_mas(x_mas, fx_p, fx, mas_delta, size, k);
			break;
		case 0:
			//free(x_mas);
			//free(fx);
			//free(fx_p);
			//free(mas_delta);
			printf("Введите через пробел левую и правую границу\n");
			scanf_s("%lf%lf", &a, &b);

			printf("Введите через пробел шаг и кол-во слагаемых\n");
			scanf_s("%lf%i", &h, &n);

			size = (b - a) / h + 1;

			x_mas = (double*)malloc(size * sizeof(double));
			fx = (double*)malloc(size * sizeof(double));
			fx_p = (double*)malloc(size * sizeof(double));
			mas_delta = (double*)malloc(size * sizeof(double));

			printf("\nНажмите '1'- функция экспоненты\n");
			printf("Нажмите '2'- функция синуса\n");
			printf("Нажмите '3'- функция косинуса\n");
			printf("Нажмите '4'- функция логарифма\n");
			printf("Нажмите '0'- чтобы ввести новые \n");
		}
		if (kod != 0) {
			printf("\nМаксимальная разница- ");
			max_delta = max(mas_delta, size);
			printf("%lf\n", max_delta);
			printf("\n\n");
		}
	}
}