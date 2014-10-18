#include <iostream>
#include <cmath>

int main()
{
	float n;
	std::cin >> n;
	std::cout.precision(7);
	if (n == 1)
		std::cout << 1 << std::endl;
	else
		std::cout << 1.0/cos( M_PI*(n-2)/(2*n) ) + 1.0 << std::endl;

	return 0;
}

