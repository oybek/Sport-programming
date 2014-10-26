
#include <bitset>
#include <vector>
#include <iostream>
using namespace std;

#define SIZE 100000

bitset<SIZE+1> prime;
void gen_sieve() {
	prime.set();
	prime[0] = prime[1] = 0;
	for (int i = 2; i*i <= SIZE; ++i)
		if (prime[i])
			for (int j = i*i; j <= SIZE; j += i)
				prime[j] = false;
}

int main() {
	vector<int> primev;
	primev.reserve(10000);

	gen_sieve();
	for (int i = 0; i <= SIZE; ++i)
		if (prime[i])
			primev.push_back(i);

	int n;
	cin >> n;

	for (int i = 0; i < int(primev.size()) && primev[i] < n; ++i)
		if (prime[ n-primev[i] ]) {
			cout << primev[i] << ' ' << n-primev[i] << endl;
			break;
		}

	return 0;
}

