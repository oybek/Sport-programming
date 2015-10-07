
#include <set>
#include <map>
#include <list>
#include <stack>
#include <queue>
#include <cmath>
#include <bitset>
#include <cstdio>
#include <string>
#include <vector>
#include <cassert>
#include <cstring>
#include <climits>
#include <iomanip>
#include <iostream>
#include <algorithm>

#define INF 1000000001
#define SQR(x) ((x)*(x))

typedef unsigned long long uint64;
typedef long long int64;

using namespace std;

typedef string::const_iterator const_stri;

#define SIZE 100001

string s;
bitset<SIZE> is_prime;

void init_is_prime() {
	is_prime.set();
	is_prime[0] = is_prime[0] = 1;
	for (int i = 2; i*i < SIZE; ++i)
		if (is_prime[i])
			for (int j = i*i; j < SIZE; j += i)
				is_prime[j] = 0;
}

int str2int(const_stri it1, const_stri it2) {
	int n = 0;
	for (; it1 <= it2; ++it1) {
		n *= 10;
		n += *it1-'0';
	}
	return n;
}

int get_max_prime(const_stri beg, const_stri end) {
	int max_prime = 0;
	for (const_stri i = beg; i < end; ++i)
		for (const_stri j = i; j < end; ++j) {
			if (j-i > 5)
				continue;
			int n = str2int(i, j);
			if (n < SIZE && is_prime[n]) {
				max_prime = max(max_prime, n);
			}
		}
	return max_prime;
}

int main() {
	init_is_prime();
	while (1) {
		cin >> s;
		if (s == "0")
			break;
		else
			cout << get_max_prime(s.cbegin(), s.cend()) << endl;
	}
	return 0;
}

