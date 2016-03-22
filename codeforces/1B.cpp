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
#include <regex>
#include <set>
#include <stack>
#include <string>
#include <sstream>
#include <vector>

#define INF 1000000001
#define SQR(x) ((x)*(x))
#define ALL(a) a.begin(), a.end()
#define DIVC(a, b) (a/b+(a%b?1:0))

typedef unsigned long long uint64;
typedef long long int64;

using namespace std;

template <class iteratorT>
void show(string s, iteratorT a, iteratorT b) {
	cout << s << ':';
	for (; a != b; ++a)
		cout << ' ' << *a;
	cout << endl;
}

bool is_RC(const string & s) {
	int c = 0;
	for (int i = 0; i+1 < s.size(); ++i)
		c += ((s[i] == 'R' || s[i] == 'C') && isdigit(s[i+1]));
	return c == 2;
}

string int2abc(int n) {
	string s;
	for (; n > 0; n /= 26)
		s += (n%26 == 0 ? 'Z' : n%26+'A'-1);
	return string(s.rbegin(), s.rend());
}

int power(int a, int n) {
	if (n == 0) {
		return 1;
	} else
	if (n%2) {
		return power(a, n-1)*a;
	} else {
		int t = power(a, n/2);
		return t*t;
	}
}

int abc2int(const string & s) {
	int n = 0;
	for (int i = 0; i < s.size(); ++i)
		n += (s[i] == 'Z' ? 0 : (s[i]-'A'+1)*power(26, int(s.size())-i-1));
	return n;
}

int main() {
	int n;
	cin >> n;
	while (n--) {
		string s;
		cin >> s;

		if (is_RC(s)) {
			for_each(s.begin(), s.end(), [](char & c) {
				if (isalpha(c)) c = ' ';
			});
			stringstream ss(s);
			int x, y;
			ss >> x >> y;

			cout << int2abc(y) << x << endl;
		} else {
			int n = 0, i = 0;
			auto mid = find_if(s.begin(), s.end(), [](char c) { return isdigit(c); });
			cout << 'R' << string(mid, s.end()) << 'C' << abc2int(string(s.begin(), mid)) << endl;
		}
	}

	return 0;
}

