
#include <stdio.h>

typedef unsigned long long uint64;
typedef unsigned int uint32;

typedef long long int64;

#define SIZE 3002

uint32 fib[SIZE], test_n, len, mod;
uint64 a, b, tmp;

uint32 pow_mod(uint64 a, uint64 n, uint32 mod) {
	a %= mod;
    register uint32 res = 1;
    for (; n > 0; n >>= 1) {
       if (n%2 == 1) {
		   res *= a;
		   res %= mod;
       }
       a *= a;
	   a %= mod;
    }
    return res;
}

int main() {
	scanf("%u", &test_n);
	while (test_n--) {
		scanf("%llu%llu%d", &a, &b, &mod);

		fib[0] = 0%mod;
		fib[1] = 1%mod;
		for (len = 2; len < SIZE; ) {
			fib[len] = (fib[len-1] + fib[len-2])%mod;
			++len;

			if (fib[len-1] == 1 && fib[len-2] == 0) {
				len -= 2;
				break;
			}
		}

		printf("%u\n", fib[pow_mod(a%len, b, len)]);
	}


	return 0;
}

