
#include <cmath>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n, s;
	vector<int> factors;
	factors.reserve(256);

	printf("PERFECTION OUTPUT\n");
	for ( ;; ) {
		scanf("%d", &n);
		if ( !n )
			break;

		if ( n == 1 ) {
			printf("DEFICIENT\n");
			continue;
		}

		s = 0;

		printf("%5d  ", n);
		if ( s > n ) {
			printf("ABUNDANT\n");
		} else
		if ( s < n ) {
			printf("DEFICIENT\n");
		} else {
			printf("PERFECT\n");
		}
	}
	printf("END OF OUTPUT");

	return 0;
}

