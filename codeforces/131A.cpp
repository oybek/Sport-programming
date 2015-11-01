
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

bool is_upper(const string & s, int i) {
	for (; i < int(s.size()); ++i)
		if (!isupper(s[i]))
			return false;
	return true;
}

string cap_reverse(string s) {
	for (int i = 0; i < int(s.size()); ++i)
		if (isupper(s[i])) {
			s[i] = 'a' + s[i] - 'A';
		} else {
			s[i] = 'A' + s[i] - 'a';
		}
	return s;
}

int main() {
	string s;
	cin >> s;
	cout << ((islower(s[0]) && is_upper(s, 1)) || is_upper(s, 0) ? cap_reverse(s) : s) << endl;

	return 0;
}

