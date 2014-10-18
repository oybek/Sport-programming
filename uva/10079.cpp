
#include <cstdio>
using namespace std;

#define L(n) ((n * (n + 1)) / 2 + 1)

int main() {
	using namespace std;

	long long int n;
	while ( 1 ) {
		scanf("%lld", &n);
		if ( n < 0 )
			break;

		printf("%lld\n", L(n));
	}

	return 0;
}

