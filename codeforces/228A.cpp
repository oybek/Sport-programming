
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
	int n, s = 0;
	map<int, int> occ;

	cin >> n; if (occ.find(n) == occ.end()) occ[n] = 1; else ++occ[n];
	cin >> n; if (occ.find(n) == occ.end()) occ[n] = 1; else ++occ[n];
	cin >> n; if (occ.find(n) == occ.end()) occ[n] = 1; else ++occ[n];
	cin >> n; if (occ.find(n) == occ.end()) occ[n] = 1; else ++occ[n];

	for (auto t : occ) s += t.second-1;
	cout << s;

	return 0;
}

