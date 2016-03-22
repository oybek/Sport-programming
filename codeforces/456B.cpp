
/* Use <F5> to compile & run program */
/* file.in will be redirected to stdin */
/* in file.out you'll get program stdout */

#include <algorithm>
#include <bitset>
#include <cassert>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

#define INF 1000000001

template <class T> inline T SQR(T x) { return x*x; }
template <class T> inline T DIVC(T a, T b) { return a/b+(a%b?1:0); }

typedef unsigned long long ull;
typedef long long ll;

using namespace std;

void dec_div_2(string & s) {
	string t; t.reserve(s.size());
	if (s[0] != '0')
		s = "0" + s;
	for (int i = 0; i+1 < s.size(); ++i) {
		switch ((s[i]-'0')%2) {
			case 0:
				t.push_back((s[i+1]-'0')/2+'0');
				break;
			case 1:
				t.push_back((s[i+1]-'0')/2+5+'0');
				break;
		}
	}
	s = t;
}

bool zero(const string & s) {
	for (char c : s)
		if (c != '0')
			return false;
	return true;
}

template <typename T>
T modpow(T b, string exp, T mod) {
	b %= mod;
	T result = 1;
	while (!zero(exp)) {
		if ( (*exp.rbegin()-'0')%2 )
			result = (result * b) % mod;
		b = (b * b) % mod;

		dec_div_2(exp);
	}
	return result;
}

int main() {
	string s;
	cin >> s;
	cout << (
		modpow(1, s, 5) +
		modpow(2, s, 5) +
		modpow(3, s, 5) +
		modpow(4, s, 5))%5 << endl;


	return 0;
}

