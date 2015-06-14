
#include <bitset>
#include <vector>
#include <iostream>
using namespace std;

#define SIZE 1000000

bitset<SIZE> prime;
vector<int> odd_prime;

void gen_sieve() {
	prime.set();
	prime[0] = prime[1] = false;
	for (int i = 2; i*i <= SIZE; ++i)   // valid for n < 46340^2 = 2147395600
		if (prime[i])
			for (int j = i*i; j <= SIZE; j += i)
				prime[j] = false;
}

int main() {
	odd_prime.reserve(100000);

	gen_sieve();

	for (int i = 3; i < SIZE; ++i)
		if (prime[i])
			odd_prime.push_back(i);

	int n;
	while (cin >> n) {
		if (!n) break;

		bool found = false;
		for (int i = 0; i < int(odd_prime.size()); ++i) {
			if (prime[ n-odd_prime[i] ]) {
				cout << n << " = " << odd_prime[i] << " + " << n-odd_prime[i] << endl;
				found = true;
				break;
			}
		}

		if (!found) {
			cout << "Goldbach's conjecture is wrong." << endl;
		}
	}

	return 0;
}

