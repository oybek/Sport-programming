
#include <cstdio>
using namespace std;

int gcd(int a, int b)
{
	int c;
	while ( a != 0 ) {
		c = a;
		a = b%a;
		b = c;
	}
	return b;
}

int main() {
	int m, n;
	scanf("%d%d", &n, &m);
	printf("%d\n", n+m-gcd(n, m));

	return 0;
}

