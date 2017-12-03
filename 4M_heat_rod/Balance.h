#include <cmath>
#define M_PI	3.14159265358979323846
#define M_EXP	2.71828182845904523536 

static double	ksi = 0.5;
static int		dim = 10;
static double	_step = 1. / dim;

double* A = new double[dim];
double* B = new double[dim];
double* C = new double[dim];

typedef double(*func)(double);
double _k1(double _x) { return (sqrt(M_EXP) / exp(_x)); }
double _k2(double _x) { return 1.; }
double _q1(double _x) { return 2.; }
double _q2(double _x) { return sin(M_PI * _x); }
double _f1(double _x) { return cos(M_PI * _x); }
double _f2(double _x) { return (exp(_x) / sqrt(M_EXP)); }

double _calc_integral(func f, double a, double b)
{
	double _res, _step;
	_res = 0.0;
	_step = (b - a) / 1000.;

#pragma opm parallel for private(_res), reduction(+ : sum) 
	for (unsigned int i(0); i < 1000; ++i) {
		_res += f(a + _step * (i + 0.5));
	}
	_res *= _step;
	return _res;
}

void _calc_coef
	(int n, double ksi, double *d, double *phi, double *a, double(*k1)(double), double(*k2)(double), 
	double(*f1)(double), double(*f2)(double), double(*q1)(double), double(*q2)(double))
	{
	int i;
	#pragma omp parallel for shared(d, fi, a) private(i)
	for (i = 1; i < n; ++i) {
		if (_step*(i + 0.5) <= ksi) {
			d[i] = _calc_integral(q1, _step*(i - 0.5), _step*(i + 0.5)) / _step;
			phi[i] = _calc_integral(f1, _step*(i - 0.5), _step*(i + 0.5)) / _step;
		}
		else {
			if (_step*(i - 0.5) >= ksi) {
				d[i] = _calc_integral(q2, _step*(i - 0.5), _step*(i + 0.5)) / _step;
				phi[i] = _calc_integral(f2, _step*(i - 0.5), _step*(i + 0.5)) / _step;
			}
			else {
				d[i] = (_calc_integral(q1, _step*(i - 0.5), ksi) + _calc_integral(q2, ksi, _step*(i + 0.5))) / _step;
				phi[i] = (_calc_integral(f1, _step*(i - 0.5), ksi) + _calc_integral(f2, ksi, _step*(i + 0.5))) / _step;
			}
		}
	}
	#pragma omp parallel for shared(d, fi, a) private(i)
	for (i = 1; i <= n; ++i) {
		if (_step*i <= ksi) {
			a[i] = 1 / (_calc_integral(k1, _step*(i - 1), _step*i) / _step);
		}
		else {
			if (_step*(i - 1) >= ksi) {
				a[i] = 1 / (_calc_integral(k2, _step*(i - 1), _step*i) / _step);
			}
			else {
				a[i] = 1 / ((_calc_integral(k1, _step*(i - 1), ksi) + _calc_integral(k2, ksi, _step*i)) / _step);
			}
		}
	}
}

void set_diag(double *a, double *d) 
{
	int i;
#pragma omp parallel for shared(A, B, C) private(i)
	for (i = 1; i < dim; ++i) {
		A[i] = a[i] / (_step * _step);
		B[i] = a[i + 1] / (_step * _step);
		C[i] = (a[i] + a[i + 1]) / (_step * _step) + d[i];
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
