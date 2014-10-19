
#include <cmath>
#include <vector>
#include <bitset>
#include <cassert>
#include <iostream>
#include <algorithm>
using namespace std;

#define SIZE 1000
bitset<SIZE+1> prime;
vector<int> prime_list;

void gen_sieve() {
	prime.set();
	prime[0] = prime[1] = false;

	for (int i = 2; i*i <= SIZE; ++i)
		if (prime[i]) {
			prime_list.push_back(i);
			for (int j = i*i; j <= SIZE; j += i)
				prime[j] = false;
		}
}

int main() {
	gen_sieve();
	int N, C;
	while (cin >> N >> C) {
		cout << N << ' ' << C << ": ";

		int i	= lower_bound(prime_list.begin(), prime_list.end(), N)
				- prime_list.begin();

		if (prime_list[i] > N) --i;
	}

	return 0;
}

