#include <cmath>
#define M_PI 3.14159265358979323846
using std::cout;
using std::cin;
using std::endl;

namespace _4M_heat_rod{

static double	ksi = 0.5;
static int		dim = 10;
static double	_step = 1. / dim;

void set_a(long double* a) {
	a[0] = 0.;
	double x = 0.;
	int i(1);
	while (x <= ksi)
	{
		*(a + i) = 1. / ((1. / _step) * ((long double)exp(x + _step - 0.5) - (long double)exp(x - 0.5)));
		i++;
		x += _step;
	}
	while (x <= 1)
	{
		a[i] = 1.;
		i++;
		x += _step;
	}
}

void set_d(long double* d) {
	d[0] = 0.;
	double x = 0.5 * _step;
	int i(1);
	while (x + _step < ksi)
	{
		d[i] = 2.;
		i++;
		x += _step;
	}
	i++;
	d[i] = (1. / _step) * (1. + (-(long double)cos(M_PI * (x + _step) + (long double)cos(M_PI * (x + 0.5 * _step)))));
	x += _step;

	while (x <= 1 - 0.5 * _step)
	{
		d[i] = (1. / _step) * (-(long double)cos(M_PI * (x + _step) + (long double)cos(M_PI * x)));
		i++;
		x += _step;
	}
	d[dim] = 0.;
}

void set_Phi(long double* Phi) {
	Phi[0] = 1;
	double x = 0.5 * _step;
	int i(1);
	while (x + _step < ksi)
	{
		Phi[i] = -(1. / _step) * ((long double)sin(M_PI * (x + _step) - (long double)sin(M_PI * x)));
		i++;
		x += _step;
	}
	i++;
	Phi[i] = -(1. / _step) * ((long double)sin(M_PI * (x + 0.5 * _step) - (long double)sin(M_PI * x) +
		((long double)exp(x + _step - 0.5) - (long double)exp(x + 0.5 * _step - 0.5))));
	x += _step;

	while (x <= 1 - 0.5 * _step)
	{
		Phi[i] = -(1. / _step) * ((long double)exp(x + _step - 0.5) - (long double)exp(x - 0.5));
		i++;
		x += _step;
	}
	Phi[dim] = 1;
}

void set_A(long double* a, long double* A) {
	for (int i(0); i < dim; ++i) {
		A[i] = a[i] / (_step * _step);
	}
	A[dim] = -1;
}

void set_B(long double* a, long double* B) {
	B[0] = -1.;
	for (int i(1); i < dim; ++i) {
		B[i] = a[i + 1] / (_step * _step);
	}
}

void set_C(long double* a, long double* d, long double* C) {
	C[0] = 1;
	C[dim] = 1;
	for (int i(1); i < dim; ++i) {
		C[i] = -(a[i] / (_step * _step) + a[i + 1] / (_step * _step) + d[i]);
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
}