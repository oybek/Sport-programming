
#include <cmath>
#include <cstdio>
#include <iostream>
using namespace std;

int main() {
	int n;
	double r;
	while (scanf("%lf%d", &r, &n) != EOF) {
		/*printf("%.3lf\n", round(500.0*r*r*n*sin(4.0*asin(1) / n))/1000.0);*/
		printf("%.3lf\n", round(500.0*r*r*n*sin(2.0*M_PI / n))/1000.0);
	}

	return 0;
}

