#include <math.h>
#include <stdlib.h>
#include <stdio.h>



double root(double (*f1)(double), double (*df1)(double), double (*f2)(double), double(*df2)(double),
			double a, double b, double eps){
	double x_0 = (a + b) / 2, x_1 = x_0;
	int iter = 0;
	while(fabs(f1(x_1) - f2(x_1)) >= eps / 2){
		double temp = x_1;
		x_1 = x_0 - (f1(x_0) - f2(x_0)) / (df1(x_0) - df2(x_0));
		//if(x_1 < a) x_1 = a;
		//if(x_1 > b) x_1 = b;
		x_0 = temp;
		++iter;
		if(iter > 1000){
			printf("can`t converge!\n");
			exit(1);
		}
	}
	return x_1;
}