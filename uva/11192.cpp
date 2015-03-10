
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

int n, sz;
string s;

int main() {
	while (1) {
		cin >> n;
		if (n == 0)
			break;
		cin >> s;

		sz = s.size()/n;
		for (string::iterator it = s.begin(); it != s.end(); it += sz)
			reverse(it, it+sz);

		cout << s << endl;
	}

	return 0;
}

