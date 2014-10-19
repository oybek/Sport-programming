
#include <cctype>
#include <bitset>
#include <string>
#include <vector>
#include <iostream>
using namespace std;

#define SIZE 1040

bitset<SIZE+1> prime;

void gen_sieve() {
	prime.set();
	prime[0] = prime[1] = false;

	prime[1] = true; /* due to problem statement ;) */
	for (int i = 2; i*i <= SIZE; ++i)   // valid for n < 46340^2 = 2147395600
		if (prime[i])
			for (int j = i*i; j <= SIZE; j += i)
				prime[j] = false;
}

int cost(char c) {
	if (!isalpha(c))
		return 0;

	if (isupper(c)) {
		return int(c-'A'+27);
	} else {
		return int(c-'a'+1);
	}
}

bool is_prime_word(const string & s) {
	int sum = 0;
	for (int i = 0; i < int(s.size()); ++i)
		sum += cost(s[i]);
	return prime[ sum ];
}

int main() {
	gen_sieve();
	string s;
	while (cin >> s) {
		cout << "It is" << (is_prime_word(s) ? " ": " not ") << "a prime word." << endl;
	}

	return 0;
}

