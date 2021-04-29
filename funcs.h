#ifndef FUNCS_H_INCLUDED
#define FUNCS_H_INCLUDED


double root(double (*f1)(double), double (*df1)(double), double (*f2)(double), double(*df2)(double),
			double a, double b, double eps);

double integral(double (*f)(double), double a, double b, double eps);

#endif // FUNCS_H_INCLUDED