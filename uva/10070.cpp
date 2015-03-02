
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

string n;

bool div_by_3(const string & n) {
	int s = 0;
	for (string::const_iterator it = n.begin(); it != n.end(); ++it) {
		s += *it-'0';
	}
	return s%3 == 0;
}

bool div_by_4(const string & n) {
	int last = n.size()-1;
	if (n.size() == 1)
		return (n[0]-'0')%4 == 0;
	else
		return (10 * (n[last-1]-'0') + (n[last]-'0'))%4 == 0;
}

bool div_by_100(const string & n) {
	int last = n.size()-1;
	return n.size() > 2 && n[last-1] == '0' && n[last] == '0';
}

bool div_by_11(const string & n) {
	int s1 = 0, s2 = 0;
	for (int i = 0; i < int(n.size()); i += 2)
		s1 += n[i]-'0';
	for (int i = 1; i < int(n.size()); i += 2)
		s2 += n[i]-'0';
	return abs(s1-s2)%11 == 0;
}

bool div_by_5(const string & n) {
	int last = n.size()-1;
	return n[last] == '0' || n[last] == '5';
}

bool div_by_400(const string & n) {
	int last = n.size()-1;
	if (n.size() < 3)
		return false;
	else if (n.size() == 3)
		return (n[last-2]-'0')%4 == 0;
	else
		return (10 * (n[last-3]-'0') + (n[last-2]-'0'))%4 == 0;
}

#define LEAP(n) (div_by_4(n) && (!div_by_100(n) || div_by_400(n)))
#define HULUCULU(n) (div_by_3(n) && div_by_5(n))
#define BULUCULU(n) (div_by_5(n) && div_by_11(n) && LEAP(n))

int main() {
	n.reserve(1000000);
	bool f1 = true;
	while (cin >> n) {
		if (f1) f1 = false;
		else cout << endl;

		bool any = false;
		if (LEAP(n)) {
			cout << "This is leap year.\n";
			any = true;
		}
		if (HULUCULU(n)) {
			cout << "This is huluculu festival year.\n";
			any = true;
		}
		if (BULUCULU(n)) {
			cout << "This is buluculu festival year.\n";
			any = true;
		}

		if (!any)
			cout << "This is an ordinary year.\n";
	}

	return 0;
}

