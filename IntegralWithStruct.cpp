#include <math.h>
#include <stdio.h>
#include <stdlib.h>
typedef double(*dfunc)(double x);
double parabola(double x) {
	return x * x + x + 1;
}
double logarifm(double x) {
	return log(1 + x);
}
double sincos(double x) {
	return sin(x) + cos(x);
}
struct myfunc {
	dfunc f;
	const char *description;
}func[3]{ {parabola,"x^2+x+1"},{logarifm,"log(1+x)"},{sincos,"sinx+cosx"} };
struct dinterval { double from, to; }interval[5];
		
double dIntegral(double(*func)(double x), double from, double to, double step)
{
	double S, dsum;
	int n, i;
	dsum = 0.;
	S = 0.;
	n = (to-from)/step;
	for (i = 0; i <= n; i ++) {
		dsum += func(from + (i*step));
	}
	S = (dsum+(func(from)+func(to))/2)*step;
	return S;
}
int main() {
	int i,k;
	printf("Please, enter the limits of integration:\n");
	for (i = 0; i < 5; i++) {
		printf("%d)", i+1);
		scanf_s("%lf %lf", &interval[i].from, &interval[i].to);
	}
	for (k = 0; k < 5; k++) {
		printf("%d)from %0.1lf to %0.1lf:\n", k + 1, interval[k].from, interval[k].to);
		for (i = 0; i < 3; i++) {
			printf("  integral %s = %.3lf\n", func[i].description, dIntegral(func[i].f,interval[k].from,interval[k].to,0.001));
		}
	}
	getchar();
	getchar();
	return 0;
}
