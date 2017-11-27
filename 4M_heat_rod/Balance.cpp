#include <cmath>
#define M_PI 3.14159265358979323846

using namespace std;

unsigned int dim = 10;

static long double* a = new long double[dim + 1];
static long double* Phi = new long double[dim + 1];
static long double* d = new long double[dim + 1];

static long double* A = new long double[dim + 1];
static long double* B = new long double[dim + 1];
static long double* C = new long double[dim + 1];

static const double ksi = 0.5;
static const double step = 1. / dim;

void set_a() {
	a[0] = 0.;
	double x = 0.;
	int i(1);
	while (x <= ksi)
	{
		a[i] = 1. / ((1. / step) * ((long double)exp(x + step - 0.5) - (long double)exp(x - 0.5)));
		i++;
		x += step;
	}
	while (x <= 1)
	{
		a[i] = 1.;
		i++;
		x += step;
	}
}

void set_d() {
	d[0] = 0.;
	double x = 0.5 * step;
	int i(1);
	while (x + step < ksi)
	{
		d[i] = 2.;
		i++;
		x += step;
	}
	i++;
	d[i] = (1. / step) * (1. + (-(long double)cos(M_PI * (x + step) + (long double)cos(M_PI * (x + 0.5 * step)))));
	x += step;

	while (x != 1 - 0.5 * step)
	{
		d[i] = (1. / step) * (-(long double)cos(M_PI * (x + step) + (long double)cos(M_PI * x)));
		i++;
		x += step;
	}
	d[dim] = 0.;
}

void set_Phi() {
	Phi[0] = 1;
	double x = 0.5 * step;
	int i(1);
	while (x + step < ksi)
	{
		Phi[i] = -(1. / step) * ((long double)sin(M_PI * (x + step) - (long double)sin(M_PI * x)));
		i++;
		x += step;
	}
	i++;
	Phi[i] = -(1. / step) * ((long double)sin(M_PI * (x + 0.5 * step) - (long double)sin(M_PI * x) +
		((long double)exp(x + step - 0.5) - (long double)exp(x + 0.5 * step - 0.5))));
	x += step;

	while (x != 1 - 0.5 * step)
	{
		Phi[i] = -(1. / step) * ((long double)exp(x + step - 0.5) - (long double)exp(x - 0.5));
		i++;
		x += step;
	}
	Phi[dim] = 1;
}

void set_A() {
	for (int i(0); i < dim; ++i) {
		A[i] = a[i] / (step * step);
	}
	A[dim] = -1;
}

void set_B() {
	B[0] = -1.;
	for (int i(1); i < dim; ++i) {
		B[i] = a[i + 1] / (step * step);
	}
}

void set_C() {
	C[0] = 1;
	C[dim] = 1;
	for (int i(1); i < dim; ++i) {
		C[i] = -(a[i] / (step * step) + a[i + 1] / (step * step) + d[i]);
	}
}

float a_test[11];
float d_test[11];
float phi_test[11];

void phi_test_set()
{
	phi_test[0] = -1.;
	phi_test[10] = -1.;
	for (int i(1); i < 10; ++i) {
		if (i < 5) {
			phi_test[i] = 0.;
		}
		if (i > 5) {
			phi_test[i] = -1.;
		}
		if (i == 5) {
			phi_test[i] = -0.5;
		}
	}
}


void a_test_set() {
	a_test[0] = -2.;
	for (int i(1); i < 11; ++i) {
		a_test[i] = 1.;
	}
}


void d_test_set() {
	d_test[0] = -2.;
	for (int i(1); i < 10; ++i) {
		if (i < 5) {
			phi_test[i] = 1.;
		}
		if (i > 5) {
			phi_test[i] = 2.;
		}
		if (i == 5) {
			phi_test[i] = 1.5;
		}
	}
}




void rush(int n, double *_A, double *_C, double *_B, double *_Phi, double *_V)
/*
* n - число уравнений (строк матрицы)
* _B - диагональ, лежащая над главной (нумеруется: [0;n-2])
* _C - главная диагональ матрицы A (нумеруется: [0;n-1])
* _A - диагональ, лежащая под главной (нумеруется: [1;n-1])
* _Phi - правая часть (столбец)
* V - решение, массив v будет содержать ответ
*/
{
	double m;
	for (int i = 1; i < n; i++)
	{
		m = _A[i] / _C[i - 1];
		_C[i] = _C[i] - m*_B[i - 1];
		_Phi[i] = _Phi[i] - m*_Phi[i - 1];
	}

	_V[n - 1] = _Phi[n - 1] / _C[n - 1];

	for (int i = n - 2; i >= 0; i--)
		_V[i] = (_Phi[i] - _B[i] * _V[i + 1]) / _C[i];

}
