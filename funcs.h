#ifndef FUNCS_H_INCLUDED
#define FUNCS_H_INCLUDED


double root(double (*f1)(double), double (*df1)(double), double (*f2)(double), double(*df2)(double),
			double a, double b, double eps);

double integral(double (*f)(double), double a, double b, double eps);


double f1(double x);
double df1(double x);
double f2(double x);
double df2(double x);
double f3(double x);
double df3(double x);


double f_x(double x); // 1
double df_x(double x); // 2
double f_lowerx(double x); // 3
double df_lowerx(double x);
double f_sinx(double x);  // 4
double df_sinx(double x);
double f_ex(double x);  // 5
double df_ex(double x);
#endif // FUNCS_H_INCLUDED