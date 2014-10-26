
#include <bitset>
#include <iostream>
using namespace std;

#define SIZE 1000000

bitset<SIZE+1> prime;
void gen_sieve() {
	prime.set();
	prime[0] = 0;
	prime[1] = 1;
	for (int i = 2; i*i <= SIZE; ++i)   // valid for n < 46340^2 = 2147395600
		if (prime[i])
			for (int j = i*i; j <= SIZE; j += i)
				prime[j] = false;
}

int reversed_number(int n) {
	int m = n%10;
	for (n /= 10; n > 0; n /= 10) {
		m *= 10;
		m += n%10;
	}
	return m;
}

int main() {
	gen_sieve();

	int n;
	while (cin >>n) {
		cout <<n;
		if (!prime[ n ]) {
			cout <<" is not prime.\n";
		} else {
			if (prime[ reversed_number(n) ] && reversed_number(n) != n)
				cout <<" is emirp.\n";
			else
				cout <<" is prime.\n";
		}
	}

	return 0;
}

