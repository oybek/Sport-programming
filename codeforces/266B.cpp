
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
#include <numeric>
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

int main() {
	int n, t;
	string s;
	cin >> n >> t >> s;
	while (t--) {
		for (int i = 0; i+1 < int(s.size()); ++i)
			if (s[i] == 'B' && s[i+1] == 'G') {
				swap(s[i], s[i+1]);
				++i;
			}
	}
	cout << s;

	return 0;
}

