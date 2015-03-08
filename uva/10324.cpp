
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

#define s_size_MAX 1000001

string s;
int query_n,
	a[s_size_MAX];

int main() {
	for (int test_i = 1; cin >> s; ++test_i) {
		a[0] = s[0]-'0';
		for (int i = 1; i < int(s.size()); ++i)
			a[i] = a[i-1] + s[i] - '0';

		cin >> query_n;

		cout << "Case " << test_i << ":\n";
		while (query_n--) {
			int x, y;
			cin >> x >> y;
			if (x > y)
				swap(x, y);

			if (x > 0) {
				cout << (a[y]-a[x-1] == y-x+1 || a[y]-a[x-1] == 0 ? "Yes" : "No") << endl;
			} else {
				cout << (a[y] == y+1 || a[y] == 0 ? "Yes" : "No") << endl;
			}
		}
	}

	return 0;
}

