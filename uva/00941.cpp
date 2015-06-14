
#include <cstdio>
#include <string>
#include <vector>
#include <cassert>
#include <cstdlib>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long int64;
typedef unsigned long long uint64;

uint64 fact[21];

string get_perm(int64 n, string s) {
	string p;
	while (s.size() > 0) {
		uint64 i = n / fact[s.size()-1];
		p += s[ i ];

		n %= fact[s.size()-1];
		s.erase(i, 1);
	}
	return p;
}

void gen_fact() {
	fact[0] = 1;
	for (uint64 i = 1; i <= 20; ++i)
		fact[i] = fact[i-1]*i;
}

int main() {
	int N;
	cin >> N;

	bool first = true;

	gen_fact();
	while (N--) {
		string s;
		uint64 n;

		cin >> s >> n;

		sort(s.begin(), s.end());

		/*
		if (n >= fact[s.size()])
			continue;
		*/

		cout << get_perm(n, s) << endl;
		/*
		if (first) {
			first = false;
			cout << get_perm(n, s);
		} else {
			cout << endl << get_perm(n, s);
		}
		*/
	}

	return 0;
}

