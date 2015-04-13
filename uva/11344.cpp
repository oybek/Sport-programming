
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

#define INF INT_MAX-1
#define SQR(x) ((x)*(x))

typedef unsigned long long uint64;
typedef long long int64;

using namespace std;

inline
int to_dec(string::const_iterator a, string::const_iterator b) {
	int n = 0;
	while (a < b) {
		n *= 10;
		n += *a-'0';
		++a;
	}
	return n;
}

inline
int get_sum(string::const_iterator a, string::const_iterator b) {
	int s = 0;
	while (a < b) {
		s += *a-'0';
		++a;
	}
	return s;
}

bool divby_2(const string & s) {
	return to_dec(s.end()-1, s.end())%2 == 0;
}

bool divby_3(const string & s) {
	return get_sum(s.begin(), s.end())%3 == 0;
}

bool divby_4(const string & s) {
	return to_dec(s.end()-2, s.end())%4 == 0;
}

bool divby_5(const string & s) {
	return to_dec(s.end()-1, s.end())%5 == 0;
}

bool divby_6(const string & s) {
	return divby_2(s) && divby_3(s);
}

bool divby_7(const string & s) {
	return (3*(s[s.size()-2]-'0') + s[s.size()-1]-'0')%7 == 0;
}

bool divby_8(const string & s) {
	return to_dec(max(s.end()-3, s.begin()), s.end())%8 == 0;
}

bool divby_9(const string & s) {
	return get_sum(s.begin(), s.end())%9 == 0;
}

bool divby_10(const string & s) {
	return *s.rbegin() == '0';
}

bool divby_11(const string & s) {
	int s1, s2;
	s1 = s2 = 0;
	for (int i = 1; i < s.size(); i += 2) {
		s1 += s[i  ]-'0';
		s2 += s[i-1]-'0';
	}

	return abs(s1-s2)%11 == 0;
}

bool divby_12(const string & s) {
	return divby_3(s) && divby_4(s);
}

int main() {
	int test_n, divn, t;
	string s;

	cin >> test_n;

	while (test_n--) {
		cin >> s;

		bool wonderfull = true;
		cin >> divn;
		while (divn--) {
			cin >> t;

			switch (t) {
			}
		}
	}

	return 0;
}

