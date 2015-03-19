#include <stdio.h>
#include <math.h>

double get_optimal_time(double c, double f, double x);

int main(void)
{
	int i = 0;
	int T;
	double C, F, X;
	double result;
	scanf("%d", &T);

	for (i = 0; i < T; i++)
	{
		scanf("%lf", &C);
		scanf("%lf", &F);
		scanf("%lf", &X);

		result = get_optimal_time(C, F, X);
		printf("Case #%d: %.7f\n", i+1, result);
	}

	return 0;

}

double get_optimal_time(double c, double f, double x)
{
	double t_old = x/2.0;
	double a = c/2.0; // additional time
	double rate = 2.0+f;
	double t_new = x/rate + a;

	while ( t_old > t_new )
	{
		t_old = t_new;
		a += c/rate;
		rate += f;
		t_new = x/rate + a;
	}
	return t_old;
}


