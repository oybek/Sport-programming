
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

void lower(string & s) {
	for (int i = 0; i < int(s.size()); ++i)
		s[i] = tolower(s[i]);
}

int main() {
	string s1, s2;
	cin >> s1 >> s2;

	lower(s1);
	lower(s2);

	if (s1 < s2) {
		cout << -1;
	} else
	if (s1 > s2) {
		cout << 1;
	} else {
		cout << 0;
	}

	return 0;
}

