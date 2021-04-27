#include <stdio.h>

double f3(double x);
double f2(double x);

int main(void){
	double x;
	scanf("%lf", &x);
	printf("%lf\n", f2(x));
	return 0;
}