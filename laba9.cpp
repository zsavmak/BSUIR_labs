#include <iostream>
#include <cmath>

using namespace std;

double f(double x) {
	return sin(x) * sin(x) - x / 5 - 1;
}

double f_prime(double x)
{
	return 2 * cos(x) - 0.2;
}

double f_double_prime(double x)
{
	return -sin(x);
}

bool is_convergent(double x)
{
	double fx = f(x);
	double fpx = f_prime(x);
	double fppx = f_double_prime(x);
	double condition = abs(fx * fppx) / (fpx * fpx);

	return condition < 1;
}

double bisection_method(double a, double b, double tol, double max_iter)
{
	double fa = f(a);
	double fb = f(b);
	
	while ((b - a) / 2 > tol)
	{
		double c = (a + b) / 2;
		double fc = f(c);

		if (fc == 0 || is_convergent(c))
			return c;

		if (fa * fc < 0)
		{
			b = c;
			fb = fc;
		}
		else
		{
			a = c;
			fa = fc;

		}
	}

	return (a + b) / 2;
}

int main()
{
	int a = -4, b = 0, it = 0;
	double x0 = bisection_method(a, b, 1e-6, 100);
	double x = x0, x_new;
	while (x >= a && x <= b)
	{
		double fx = f(x);
		double fpx = f_prime(x);

		if (abs(fpx) <= 1e-6)
		{
			cout << "Derivative is close to zero. Method is not applicable.";
			cout << x << endl;
			return 0;
		}

		x_new = x - fx / fpx;
		cout << "Root was found: " << x_new << endl;
		x = x_new;
		
	}
}

