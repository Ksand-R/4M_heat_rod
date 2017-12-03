//VARIANT_6
#include <cmath>
#define M_PI	3.14159265358979323846
#define M_EXP	2.71828182845904523536 

static double	ksi = 0.5;
static int		dim = 10;
static double	_step;

typedef double(*func)(double);

double _k1(double _x) { return (sqrt(M_EXP) / exp(_x)); }
double _k2(double _x) { return 1.; }
double _q1(double _x) { return 2.; }
double _q2(double _x) { return sin(M_PI * _x); }
double _f1(double _x) { return cos(M_PI * _x); }
double _f2(double _x) { return (exp(_x) / sqrt(M_EXP)); }

double _k1_t(double _x) { return 1.; }
double _k2_t(double _x) { return 1.; }
double _q1_t(double _x) { return 2.; }
double _q2_t(double _x) { return 1.; }
double _f1_t(double _x) { return 0.; }
double _f2_t(double _x) { return 1.; }



double _calc_integral(func f, double a, double b)
{
	double _res, _step;
	_res = 0.0;
	_step = (b - a) / 1000.;

#pragma opm parallel for private(_res) reduction(+ : _res) 
	for (int i(0); i < 1000; ++i) {
		_res = _res + f(a + _step * (i + 0.5));
	}
	_res *= _step;
	return _res;
}

void _calc_coef
	(int n, double ksi, double *d, double *phi, double *a, double(*k1)(double), double(*k2)(double), 
	double(*f1)(double), double(*f2)(double), double(*q1)(double), double(*q2)(double))
	{
	_step = 1. / n;
	int i;
	#pragma omp parallel for private(i)
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
	#pragma omp parallel for private(i)
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

void rush(int n, double *a, double *d, double *fi, double *v) {
	double *al, *bet, *A, *B, *C;
	double kappa1 = 0.0, kappa2 = 0.0;

	A = new double[n];
	B = new double[n];
	C = new double[n];
	al = new double[n + 1];
	bet = new double[n + 1];
	
	int i;
	_step = 1. / n;
	
	#pragma omp parallel for shared(A, B, C) private(i)
	for (i = 1; i < n; ++i) {
		A[i] = a[i] / (_step*_step);
		B[i] = a[i + 1] / (_step*_step);
		C[i] = (a[i] + a[i + 1]) / (_step*_step) + d[i];
	}
	al[1] = kappa1;
	bet[1] = 1.;
	for (int i = 2; i <= n; ++i) {
		al[i] = B[i - 1] / (C[i - 1] - al[i - 1] * A[i - 1]);
		bet[i] = (fi[i - 1] + bet[i - 1] * A[i - 1]) / (C[i - 1] - al[i - 1] * A[i - 1]);
	}
	v[n] = (1. + bet[n] * kappa2) / (1 - al[n] * kappa2);
	for (int i = n - 1; i >= 0; --i)
		v[i] = al[i + 1] * v[i + 1] + bet[i + 1];
	delete[] al;
	delete[] bet;
	delete[] A;
	delete[] B;
	delete[] C;
}
