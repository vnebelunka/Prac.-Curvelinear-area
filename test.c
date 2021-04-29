#include <math.h>
#include <assert.h>
#include <stdio.h>

double root(double (*f1)(double), double (*df1)(double), double (*f2)(double), double(*df2)(double),
			double a, double b, double eps);

double f_x(double x){
	return x;
}
double df_x(double x){
	return 0 * x + 1;
}

double f_lowerx(double x){
	return 1 / x;
}

double df_lowerx(double x){
	return -1 / (x*x);
}
double f_sinx(double x){
	return sin(x);
}
double df_sinx(double x){
	return cos(x);
}
double f_ex(double x){
	return exp(x);
}
double df_ex(double x){
	return exp(x);
}
double f_1(double x){
	return exp(x) + 2;
}
double df_1(double x){
	return exp(x);
}
double f_2(double x){
	return -1 / x;
}
double df_2(double x){
	return 1 / (x*x);
}
double f_3(double x){
	return -2 * (x + 1) / 3;
}
double df_3(double x){
	return 0 * x - 2 / 3;
}


void rootTest(){
	double eps = 1e-6;
	double x = root(f_x, df_x,  f_lowerx, df_lowerx, 0.5, 20, eps);
	assert(fabs(x - (1 / x)) < eps);
	x = root(f_x, df_x, f_sinx, df_sinx, -1, 1, eps);
	assert(fabs(x - sin(x)) < eps);
	x = root(f_lowerx, df_lowerx, df_ex, df_ex, 0.3, 13, eps);
	assert(fabs(1 / x - exp(x)) < eps);
	///
	x = root(f_1, df_1, f_2, df_2, -1, -0.1, eps);
	assert(fabs(exp(x) + 2 + 1 / x) < eps);
	//x = root(f_2, df_2, f_3, df_3, -2.5, -1, eps);
	//assert(fabs(-1 / x + 2*(x + 1) / 3) < eps);
	x = root(f_3, df_3, f_1, df_1, -6, -2, eps);
	//assert(fabs(exp(x) + 2  + 2*(x+1) / 3) < eps);
	printf("%.9lf\n", x);
	printf("Root test: successful!\n");
}

void unitTest(){
	rootTest();
}