#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "funcs.h"

double integral(double (*f)(double), double a, double b, double eps){
	int n = 2;
	double I1, I2 = 0;
	do{
		I1 = I2;
		I2 = 0;
		double h = (b - a) / n;
		for(int j = 0; j <= n - 1; ++j){
			double x_0 = a + j * h;
			double x_1 = x_0 + h;
			I2 += (f(x_1) + f(x_0)) / 2 * (x_1 - x_0);
		}
		n <<= 1;
	}while(fabs(I1 - I2) >= eps / 2);
	return I2;
}