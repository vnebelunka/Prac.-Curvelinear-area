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

double f_sqr(double x){
	return x*x + x - 6;
}
double df_sqr(double x){
	return 2*x + 1;
}


/// test of "root" function.
void rootTest(){
	double eps = 1e-6;
	double x = root(f_x, df_x,  f_lowerx, df_lowerx, 0.5, 20, eps);
	printf("function root: %.9lf; real root: %.9lf\n", x, 1.0);
	assert(fabs(x - (1 / x)) < eps && fabs(x-1) < eps);
	x = root(f_x, df_x, f_sqr, df_sqr, -0.3, 10, eps);
	printf("function root: %.9lf; real root: %.9lf\t", x, sqrt(6));
	printf("eps = %.9lf\n", x -sqrt(6));
	assert(fabs(x - sqrt(6))< eps);
	x = root(f_lowerx, df_lowerx, df_ex, df_ex, 0.3, 13, eps);
	printf("function root e^x - 1/x: %.9lf\n", x);
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


void mTest(){
	int key = -1;
	printf("Print num of part u want to test: \"1\" for root and \"2\" for integral:\t");
	scanf("%d", &key);
	if(key == 1){
		unsigned numfunc = 0;
		printf("U can test this functions:\n1:\t1/x = x\n2:\tsin(x) = x\n3:\t1/x = sin(x)\n4:\t1/x = e^x\n");
		printf("Print num of function u want to test: ");
		scanf("%d", &numfunc);
		double s1, s2, eps;
		printf("Print interval, where function will try to find root: ");
		scanf("%lf %lf", &s1, &s2);
		printf("Print accuracy for function: ");
		scanf("%lf", &eps);
		switch(numfunc){
			case 1:
				printf("Root is: %.9lf\n", root(f_x, df_x, f_lowerx, df_lowerx, s1,s2,eps));
				break;
			case 2:
				printf("Root is: %.9lf\n", root(f_x, df_x, f_sinx, df_sinx, s1,s2,eps));
				break;
			case 3:
				printf("Root is: %.9lf\n", root(f_sinx, df_sinx, f_lowerx, df_lowerx, s1,s2,eps));
				break;
			case 4:
				printf("Root is: %.9lf\n", root(f_ex, df_ex, f_lowerx, df_lowerx, s1,s2,eps));
				break;
			default:
				printf("There is no functions with this num!\n");
		}
	}
	if(key == 2){
		unsigned numfunc = 0;
		printf("U can test this functions:\n1:\tf(x) = x\n2:\tf(x) = sin(x)\n3:\tf(x) = 1/x\n4:\tf(x) = e^x\n");
		printf("Print num of function u want to test: ");
		scanf("%d", &numfunc);
		double s1, s2, eps;
		printf("Print borders, where function will try to find integral: ");
		scanf("%lf %lf", &s1, &s2);
		printf("Print accuracy for function: ");
		scanf("%lf", &eps);
		switch(numfunc){
			case 1:
				printf("Integral is: %.9lf\n", integral(f_x, s1, s2, eps));
				break;
			case 2:
				printf("Integral is: %.9lf\n", integral(f_sinx, s1, s2, eps));
				break;
			case 3:
				printf("Integral is: %.9lf\n", integral(f_lowerx, s1, s2, eps));
				break;
			case 4:
				printf("Integral is: %.9lf\n", integral(f_ex, s1, s2, eps));
				break;
			default:
				printf("There is no functions with this num!\n");
		}
	}
}