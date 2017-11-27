#include <iostream>
#include "Balance.h"

using std::cin;
using std::cout;
using std::endl;


unsigned int dim = 10;

static long double* a = new long double[dim + 1];
static long double* Phi = new long double[dim + 1];
static long double* d = new long double[dim + 1];

long double* A = new long double[dim + 1];
long double* B = new long double[dim + 1];
long double* C = new long double[dim + 1];

static double ksi = 0.5;
static double step = 1. / dim;

int main(int argc, char* argv[]) {
	set_a(ksi, step, a);

	for (int i(0); i < dim + 1; ++i) {
		cout << a[i] << endl;

	}
	cout << endl;

	set_d(ksi, step, dim, d);

	for (int i(0); i < dim + 1; ++i) {
		cout << d[i] << endl;

	}

	cout << endl;

	set_Phi(ksi, step, dim, Phi);

	for (int i(0); i < dim + 1; ++i) {
		cout << Phi[i] << endl;

	}

	
	system("pause");
	return 0;
}
