
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

int main() {
	int k, n, a[51];
	cin >> n >> k;
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	int count = 0;
	for (int i = 0; i < n; ++i)
		if (a[i] >= a[k-1] && a[i] > 0)
			++count;
	cout << count;

	return 0;
}

