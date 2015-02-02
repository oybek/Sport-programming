
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

inline void DEBUG(bool cond, const char * msg) {
#ifdef DO_DEBUG
	if (cond) {
		std::cerr << msg << '\n';
		exit(0);
	}
#endif
}

#define INF INT_MAX-1
#define SQR(x) ((x)*(x))

typedef unsigned long long uint64;
typedef long long int64;

using namespace std;

uint64 pow(uint64 a, uint64 n) {
	if (n == 0) {
		return 1;
	} else
	if (n%2) {
		return pow(a, n-1)*a;
	} else {
		a = pow(a, n/2);
		return a*a;
	}
}

uint64 bin_to_dec(string s) {
	uint64 n = 0;
	reverse(s.begin(), s.end());
	for (int i = 0; i < int(s.size()); ++i) {
		if (s[i] == '1') {
			n += (1<<i);
		}
	}
	return n;
}

string dec_to_bin(uint64 n) {
	string s;
	for (; n > 0; n >>= 1) {
		s.push_back(static_cast<char>((n&1)+'0'));
	}
	reverse(s.begin(), s.end());
	if (s == "")
		s = "0";
	return s;
}

uint64 hex_to_dec(string s) {
	uint64 n = 0;
	reverse(s.begin(), s.end());
	for (int i = 0; i < int(s.size()); ++i) {
		n += pow(16, i) * static_cast<uint64>(isdigit(s[i]) ? s[i]-'0' : s[i]-'a'+10);
	}
	return n;
}

int N;
string X, Y;

int main() {
	cin >> N;
	for (int test_i = 1; test_i <= N; ++test_i) {
		uint64 t;
		cin >> X >> Y;

		cout << "Case " << test_i << ":\n";
		switch (tolower(Y[0])) {
			case 'b':
				t = bin_to_dec(X);
				cout	<< dec << t << " dec\n"
						<< hex << t << " hex\n\n";
				break;

			case 'd':
				t = atoi(X.c_str());
				cout	<< hex << t << " hex\n"
						<< dec_to_bin(t) << " bin\n\n";
				break;

			case 'h':
				t = hex_to_dec(X);
				cout	<< dec << t << " dec\n"
						<< dec_to_bin(t) << " bin\n\n";
				break;
		}
	}

	return 0;
}

