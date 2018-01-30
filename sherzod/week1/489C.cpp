
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

int main() {
	int m, s;
	cin >> m >> s;
	if (m == 1 && s == 0) {
		cout << "0 0";
		return 0;
	}
	if (s == 0) {
		cout << "-1 -1";
		return 0;
	}

	string smax, smin;
	for (int t = s; t > 0; t -= min(t, 9)) {
		smax += char(min(t, 9)+'0');
		smin = char(min(t, 9)+'0') + smin;
	}
	if (smax.size() > m) {
		cout << "-1 -1";
		return 0;
	}
	--smin[0];
	while (smax.size() < m) {
		smax.push_back('0');
		smin = "0"+smin;
	}
	++smin[0];
	cout << smin << ' ' << smax;

	return 0;
}

