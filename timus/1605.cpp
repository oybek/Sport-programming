#include <iostream>

#define SIZE 100

long double Fn(int n)
{
	if (n == 1)			return 0;
	else if (n == 2)	return 1;
	else				n -= 1;

	long double Fn_2 = 0;
	long double Fn_1 = 1;
	long double Fn_0;

	while (n--) {
		Fn_0 = (Fn_1+Fn_2)/2;

		Fn_2 = Fn_1;
		Fn_1 = Fn_0;
	}

	return Fn_0;
}

int get_leading_six_num(long double x)
{
	int n = 0;
	while ((int)(x *= 10) == 6) {
		x -= 6.0;
		++n;
	}

	return n;
}

int main()
{
	long n;
	std::cin >> n;
	std::cout << get_leading_six_num(Fn(n)) << std::endl;

	return 0;
}

