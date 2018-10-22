#include <math.h>
#include <stdio.h>
double parabola(double x) {
	return x * x + x + 1;
}
double logarifm(double x) {
	return log(1 + x);
}
double sincos(double x) {
	return sin(x) + cos(x);
}
double dIntegral(double(*func)(double x), double from, double to, double step)
{
	double i, S, dsum;
	int n;
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
	int a, b, i;
	i = 0;
	a = 1;
	b = 2;
	printf("The limits of integration    x^2+x+1    ln(1+x)    sinx+cosx\n");
	while (i < 5) {
	printf("%d %d %31.3lf %10.3lf %11.3lf\n", a, b, dIntegral(parabola, a, b, 0.001), dIntegral(logarifm, a, b, 0.001), dIntegral(sincos, a, b, 0.001));
	b++;
	a++;
	i++;
	}
	getchar();
	return 0;
}
