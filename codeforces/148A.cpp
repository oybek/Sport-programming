
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

#define size 100005
int a[size], b[4], n;

int main() {
	for (int i = 0; i < 4; ++i)
		cin >> b[i];
	cin >> n;
	for (int i = 0; i < 4; ++i)
		for (int j = b[i]; j <= n; j += b[i])
			a[j] = 1;
	cout << accumulate(a, a+n+1, 0) << endl;

	return 0;
}

