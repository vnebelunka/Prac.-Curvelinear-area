#include <math.h>
#include <assert.h>
#include <stdio.h>
#include "funcs.h"

/*
 * Elementary functions for testing.
*/
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
	return 0 * x - 2.0 / 3;
}

/// test of "root" function.
void rootTest(){
	double eps = 1e-6;
	double x = root(f_x, df_x,  f_lowerx, df_lowerx, 0.5, 20, eps);
	printf("function root: %.9lf; real root: %.9lf\n", x, 1.0);
	assert(fabs(x - (1 / x)) < eps && fabs(x-1) < eps);
	x = root(f_x, df_x, f_sinx, df_sinx, -1, 1, eps);
	printf("function root: %.9lf; real root: %.9lf\n", x, 0.0);
	assert(fabs(x - sin(x)) < eps && fabs(x) < eps);
	x = root(f_lowerx, df_lowerx, df_ex, df_ex, 0.3, 13, eps);
	assert(fabs(1 / x - exp(x)) < eps);
	///
	x = root(f_1, df_1, f_2, df_2, -1, -0.1, eps);
	assert(fabs(exp(x) + 2 + 1 / x) < eps);
	x = root(f_2, df_2, f_3, df_3, -2.5, -1, eps);
	assert(fabs(-1 / x + 2*(x + 1) / 3) < eps);
	x = root(f_3, df_3, f_1, df_1, -5, -3, eps);
	assert(fabs(exp(x) + 2  + 2*(x+1) / 3) < eps);
	printf("Root test: successful!\n");
}

///test of "integral" function.
void integralTest(){
	double eps = 1e-6;
	double I = integral(f_x, 0, 1, eps);
	printf("function Integral: %.9lf; real Integral: %.9lf\n", I, 0.5);
	assert(fabs(I - 0.5) < eps);
	I = integral(f_sinx, 0, M_PI, eps);
	printf("function Integral: %.9lf; real Integral: %.9lf\n", I, 2.0);
	assert(fabs(I - 2) < eps);
	I = integral(f_lowerx, 1, M_E, eps);
	printf("function Integral: %.9lf; real Integral: %.9lf\n", I, 1.0);
	assert(fabs(I - 1) < eps);
	I = integral(f_ex, 0, M_LN10, eps);
	assert(fabs(I - 9) < eps);
	printf("function Integral: %.9lf; real Integral: %.9lf\n", I, 9.0);
	printf("Integral test: successful!\n");
} 


void unitTest(){
	rootTest();
	integralTest();
}