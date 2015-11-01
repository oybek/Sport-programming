
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

int a[101];

int main() {
	int n, t;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> t;
		a[t-1] = i+1;
	}
	for (int i = 0; i < n; ++i)
		cout << a[i] << ' ';

	return 0;
}

