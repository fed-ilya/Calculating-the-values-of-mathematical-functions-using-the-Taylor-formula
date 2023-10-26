#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "Header.h"
#define M_PI       3.141592 //65358979323846

#define double long double

/*
int obyavlenye(int a, int b, int h, int n, int) {
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

	printf("������� '1'- ������� ����������\n");
	printf("������� '2'- ������� ������\n");
	printf("������� '3'- ������� ��������\n");
	printf("������� '0'- ����� ������ ����� \n");
	return size;
}
*/

double max(double* mas, int n) { //������� ������� ������������ ������� � �������
	double maxd;
	maxd = mas[0];
	for (int i = 1; i < n; i ++ ) {
		if (mas[i] > maxd) {
			maxd = mas[i];
		}
	}
	return maxd;
}

double exp_p(double x, int n) { //������� ������� �������� ���������� �� ������� �������
	int k = 0;
	double logn = log(2);
	while (x - k * logn >= 0) {
		x = x - logn;
		k++;
	}
	double res = 1, a = 1;
	for (int i = 1; i <= n; i++) {
		a = a * x / i;
		res += a;
	}
	return res * pow(2,k);
}

double sin_p(double x, int n) { //������� ������� �������� ������ �� ������� �������
	double k = 0;
	double b = x;
	while (b - 2 * M_PI * (k + 1) >= 0) {
		x = x - 2 * M_PI;
		k++;
	}
	double res = x, a = x;
	for (double i = 3; i <= n; i += 2) {
		a = (a * (-1) * x * x) / (i * (i - 1));
		res += a;
	}
	return res;
}

double cos_p(double x, int n) { //������� ������� �������� �������� �� ������� �������
	double k = 0;
	double b = x;
	while (b - 2 * M_PI * (k + 1) >= 0) {
		x = x - 2 * M_PI;
		k++;
	}
	
	double res = 1, a = 1;
	for (double i = 2; i <= n; i += 2) {
		a = (a * (-1) * x * x) / (i * (i - 1));
		res += a;
	}
	return res;
}

double log_p(double y, int n) { //������� ������� �������� ������������ ��������� �� ������� �������
	double x = (y - 1) / (y + 1), a = x, sum = x;
	for (double i = 1; i < n; i++) {
		a = a * x * x;
		sum += (a / (i + 2));
	}
	return 2 * sum;
}

//x_mas- ������ x, fx_p- ������ � ���������������� ���������� �������, fx- ������ � ��������� ���������� �������, mas_delta- ������ ������ ����� ��������������� � �������� ���������
//size- ������ ���� ��������, n- ���-�� ���������, h- ���, a- ��������������� ���������� ��� ����� x
//pr- ��������� �� ������� ���������������, p- ��������� �� ������� ��������
void inicializy(double* x_mas, double* fx_p, double* fx, double* mas_delta, int size,
				double a, double h, int n, pFunc_p pr, pFunc p) { //������� ��������� ��� �������
	for (int i = 0; i < size; i++) {
		x_mas[i] = a + i * h;
		fx[i] = p(x_mas[i]);
		fx_p[i] = pr(x_mas[i], n);
		mas_delta[i] = fabs(fx_p[i] - fx[i]);
	}
}

//���������� ������� 

int size_chertochki(double x) { //�������, ������� ������� ������ ������ �������� � �������� � ����������� �� ������ �������� ����� � ��������
	int k = 6; //1.0000- 6 ��������
	for (int i = 0; x / 10 >= 1; i++) {
		x /= 10;
		k++;
	}
	if (k < 17) k = 20;
	return k;
}

int size_str(char* str) //�������, ������� ������� ����� ������ � ����� ������ ������� � ������������ ���������
{
	int k = 0;
	while (str[k++] != '\0');
	return k - 1;
}

void zapoln_probel(int k, char* str) { //�������, ������� ����������� �������� ������ ���������� � ��������� ��������� ����� � ������ �� �� � ������
	int n;
	n = size_str(str);
	printf("|");
	for (int i = 0; i <= k-n; i++) {
		if (i == (k - n) / 2) printf("%s", str);
		else printf(" ");
	}
}

void zapoln_chertochki(int k) { //������� , ������� ������ ����� ����� ���������� 
	printf("|");
	for (int j = 0; j < 4; j++) {
		for (int i = 0; i < k; i++) {
			printf("-");
		}
		printf("|");
	}
	printf("\n");
}


int razmetka(double* fx_p, double*fx, int size, int* k) { //�������, ������� ��������� ������ ������ ������� � ������������. ���������� ������������ ������ ����� ������
	char str1[2] = "x";
	char str2[18] = "f ���������������";
	char str3[11] = "f ��������";
	char str4[8] = "�������";
	printf("\n");
	if (fx[size - 1] > fx_p[size - 1])
		*k = size_chertochki(fx[size - 1]);
	else
		*k = size_chertochki(fx_p[size - 1]);
	zapoln_probel(*k, str1);
	zapoln_probel(*k, str2);
	zapoln_probel(*k, str3);
	zapoln_probel(*k, str4);
	printf("|\n");
	zapoln_chertochki(*k);
	return *k;
}

void sizeprobel(double x, int size_chisla) { //�������, ������� ��������� ��������� ������������, ������� �������� ����� ���������� � ������ �����
	int k = 1;
	if (x < 0) k++;
	for (int i = 0; fabs(x / 10) >= 1; i++) {
		x /= 10;
		k++;
	}
	for (int i = 0; i < size_chisla-5-k; i++) {
		printf(" ");
	}
}

int s1, s2, s3, s4;

//����� ������� � ���������� �������

void print_mas(double* x_mas, double* fx_p, double* fx, double* mas_delta, int size, int k) { //������� ������ ���� �������� � �������
	for (int i = 0; i < size; i++) {
		printf("|%0.4f", x_mas[i]);
		sizeprobel(x_mas[i], k);

		printf("|%0.4f", fx_p[i]);
		sizeprobel(fx_p[i], k);

		printf("|%0.4f", fx[i]);
		sizeprobel(fx[i], k);

		printf("|%0.4f", mas_delta[i]);
		sizeprobel(mas_delta[i], k);
		printf("|\n");
		zapoln_chertochki(k);
	}
}