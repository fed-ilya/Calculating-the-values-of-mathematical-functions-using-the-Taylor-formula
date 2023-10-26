#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#define _USE_MARH_DEFINES
#include <math.h>
#include "Header.h"

#define double long double

int main() {
	setlocale(LC_CTYPE, "Russian");
	double a, b, h; //a- ����� �������, b- ������ �������, x- �����, h- ���, �������� ������� � ������� �� �������������
	double* x_mas, * fx, * fx_p, * mas_delta; //������� �� ����������

	int n; //n- ���-�� ���������(������������ �������)
	int size;

	printf("������� ����� ������ ����� � ������ �������\n");
	scanf_s("%lf%lf", &a, &b);

	printf("������� ����� ������ ��� � ���-�� ���������\n");
	scanf_s("%lf%i", &h, &n);

	size = (b - a) / h + 1;

	x_mas = (double*)malloc(size * sizeof(double));
	fx = (double*)malloc(size * sizeof(double));
	fx_p = (double*)malloc(size * sizeof(double));
	mas_delta = (double*)malloc(size * sizeof(double));

	printf("\n������� '1'- ������� ����������\n");
	printf("������� '2'- ������� ������\n");
	printf("������� '3'- ������� ��������\n");
	printf("������� '4'- ������� ���������\n");
	printf("������� '0'- ����� ������ ����� \n\n");

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
			printf("������� ����� ������ ����� � ������ �������\n");
			scanf_s("%lf%lf", &a, &b);

			printf("������� ����� ������ ��� � ���-�� ���������\n");
			scanf_s("%lf%i", &h, &n);

			size = (b - a) / h + 1;

			x_mas = (double*)malloc(size * sizeof(double));
			fx = (double*)malloc(size * sizeof(double));
			fx_p = (double*)malloc(size * sizeof(double));
			mas_delta = (double*)malloc(size * sizeof(double));

			printf("\n������� '1'- ������� ����������\n");
			printf("������� '2'- ������� ������\n");
			printf("������� '3'- ������� ��������\n");
			printf("������� '4'- ������� ���������\n");
			printf("������� '0'- ����� ������ ����� \n");
		}
		if (kod != 0) {
			printf("\n������������ �������- ");
			max_delta = max(mas_delta, size);
			printf("%lf\n", max_delta);
			printf("\n\n");
		}
	}
}