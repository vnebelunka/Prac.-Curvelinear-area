#include <stdio.h>
#include <math.h>
#include "funcs.h"
#include <string.h>

void unitTest();
void mTest();
void help();
unsigned iters;

int main(int argc, char **argv){
	int flagroots = 0, flagiters = 0;
	if(argc){
		for(int arg = 0; arg < argc; ++arg){
			if(strcmp("-iters", argv[arg]) == 0)
				flagiters = 1;
			if(strcmp("-roots", argv[arg]) == 0)
				flagroots = 1;
			if(strcmp("-test", argv[arg]) == 0)
				unitTest();
			if(strcmp("-mtest", argv[arg]) == 0)
				mTest();
			if(strcmp("-help", argv[arg]) == 0)
				help();
			if(strcmp("-ifuncs", argv[arg]) == 0){
				printf("f1:\t exp(x) + 2\nf2:\t-1/x\nf3:\t-2(x+1)/3\n");
			}
		}
	}
	double r1 = root(f1, df1, f2, df2, -1, -0.1, 1e-5);//first root; e^x + 2 = -1/x
    double r2 = root(f2, df2, f3, df3, -2.5, -1, 1e-5);//second root; -1/x = -2(x+1)/3
    double r3 = root(f1, df1, f3, df3, -5, -3, 1e-5);//third root; e^x + 2 = -2(x+1)/3
   	double s1 = integral(f1, r3, r1, 1e-5);//first integral; e^x + 2 from r3 to r1
    double s2 = integral(f2, r2, r1, 1e-5);//second integral;-1/x from r2 to r1
    double s3 = integral(f3, r3, r2, 1e-5);//third integral; -2(x+1)/3 from r3 to r2
    printf("Area is %lf\n", s1-s2-s3);//area formula
    if(flagiters){
    	printf("Total iters: %u\n", iters);
    }
    if(flagroots){
    	printf("Roots are:\nf1 = f2:\t%.8lf\nf2 = f3:\t%.8lf\nf3 = f1:\t%.8lf\n", r1, r2,r3);
    }
	return 0;
}


void help(void){
	printf("Name of executable file:\t area\n");
	printf("Available keys:\n");
	printf(" -ifuncs:  print initial functions\n");
	printf(" -iters:   print total number of iterations\n");
	printf(" -roots:   print roots of initial functions\n");
	printf(" -test:    start unitTest\n");
	printf(" -mtest:   start manual test\n");
}