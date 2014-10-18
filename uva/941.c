
#include <stdio.h>

typedef long long int64;
typedef unsigned long long uint64;

uint64 fact[21];
uint64 p_sz, s_sz;
char p[ 21 ], s[ 21 ];

void get_perm(int64 n) {
	while (s_sz > 0) {
		uint64 i = n / fact[s_sz-1];
		p[ p_sz++ ] = s[ i ];

		n %= fact[s_sz-1];

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

