#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include "funcs.h"

extern unsigned iters;

double root(double (*f1)(double), double (*df1)(double), double (*f2)(double), double(*df2)(double),
			double a, double b, double eps){
	double x_1 = (a + b) / 2;
	while(fabs(f1(x_1) - f2(x_1)) >= eps / 2){
		x_1 = x_1 - (f1(x_1) - f2(x_1)) / (df1(x_1) - df2(x_1));
		++iters;
	}
	return x_1;
}