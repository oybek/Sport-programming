
#include <cmath>
#include <bitset>
#include <cstdio>
#include <vector>
#include <iostream>
using namespace std;

int div_sum(int n) {
   int d, dlim, s = 1;

   dlim = sqrt( n );
   for (d = 2; d <= dlim; ++d) {
      if (n%d == 0) {
		 s += d;
         if ( d != n/d )
			 s += n/d;
      }
   }
   return s;
}

const size_t primen = 1000000;
bitset<primen+1> prime;

void gen_sieve() {
	prime.reset();
	prime.flip();
	prime.set(0, false);
	prime.set(1, false);
	for (size_t i = 2; i <= primen; ++i)
		if (prime.test(i)) {
			for (size_t j = i * i; j <= primen; j += i)
				prime.set(j, false);
		}
}

double get_triviality(int n) {
	return double(div_sum(n))/n;
}

int main() {
	gen_sieve();
	int a, b;
	scanf("%d%d", &a, &b);
	if (a == 1) {
		printf("1\n");
		return 0;
	}

	for (int n = b; n >= a; --n) {
		if (prime[n]) {
			printf("%d\n", n);
			return 0;
		}
	}

	int most_trivial_n = a;
	double n_triviality = get_triviality(a), cur_triviality;

	for (int n = a+1; n <= b; ++n) {
		cur_triviality = get_triviality(n);
		if (cur_triviality < n_triviality) {
			n_triviality = cur_triviality;
			most_trivial_n = n;
		}
	}

	printf("%d\n", most_trivial_n);

	return 0;
}

