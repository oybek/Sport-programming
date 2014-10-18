#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

#define RADIANS_PER_DEG (180.0/3.1415926535)

int main()
{
	long v; float a; float k;
	cin >> v >> a >> k;
	a /= RADIANS_PER_DEG;

	float s = 0;
	int n = 10000;
	while (n--) {
		s += 0.2*v*v*sin(a)*cos(a);
		v /= k;
	}
	printf("%.2f\n", s);

	return 0;
}

