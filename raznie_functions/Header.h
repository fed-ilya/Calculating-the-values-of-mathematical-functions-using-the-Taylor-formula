#pragma once

typedef double(*pFunc)(double);
typedef long double(*pFunc_p)(long double, int);

#define double long double

double max(double* mas, int n);

int razmetka(double* fx, double* fx_p, int size, int* k);

void zapoln_chertochki(int k);

double exp_p(double x, int n);

double sin_p(double x, int n);

double cos_p(double x, int n);

double log_p(double y, int n);

void inicializy(double* x_mas, double* fx_p, double* fx, double* mas_delta, int size, double a, double h, int n, pFunc_p pr, pFunc p);

void print_mas(double* x_mas, double* fx_p, double* fx, double* mas_delta, int size, int k);